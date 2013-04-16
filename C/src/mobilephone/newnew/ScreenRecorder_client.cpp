//ScreenRecorder_client.cpp
/*
 *	Code copyright by wangyunjin 
 *	Date@20120906
 *    The ScreenRecorder_client Interface function for
 *     interaction with ScreenRecorder_server process 
 *
 */

//#define LOG_TAG "ScreenRecorder_client_test"

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <pthread.h>

#include "ScreenRecorderInterface.h"
#include "ScreenRecorder_client.h"
#define LOG_TAG "RECORDER_CLIENT"
#include "Android_log.h"

static int create_local_socket_client(const char *localName)
{
	int clientFd;
	struct sockaddr_un addr;
	int namelen, addrlen;

	clientFd = socket(AF_LOCAL, SOCK_STREAM, 0);
	if(clientFd < 0)
	{
	LOGE("Create local-socket CLIENT Failed(name=%s),error:%s", localName, strerror(errno));
	return -1;
	}
	else 
	{
		fcntl(clientFd, F_SETFD, FD_CLOEXEC);
	}
	namelen  = strlen(localName);

	// Test with length +1 for the *initial* '\0'.
	if ((namelen + 1) > sizeof(addr.sun_path)) {
		return -1;
	}
	addr.sun_path[0] = 0;
	memcpy(addr.sun_path + 1, localName, namelen);
	addr.sun_family = AF_LOCAL;
	addrlen = namelen + offsetof(struct sockaddr_un, sun_path) +1;
	if(connect(clientFd, (struct sockaddr *)&addr, (socklen_t)addrlen))
	{
		LOGE("Connect socket(%s) error", localName);
		return -1;
	}
	return clientFd;
}

int screenrecorder_init(int *connFd, int *cmdFd)
{
	int fd;
	int ret;
	char buff[256];
	
	//LOGWYJ("screenrecorder_init in ScreenRecord_client");
	
	fd = create_local_socket_client(LOCAL_SOCKET_CONNECT_NAME);
	if (fd <= 0)
		return -1;
	
	SR_EVENT_S msg;
	msg.evt = EVENT_CONNECT;

	ret = write(fd, &msg, sizeof(SR_EVENT_S));
	if (ret <= 0)
	{
		LOGE("Send failed with ret=%d, error:%s", ret, strerror(errno));
		return -1;
	}	

	memset(buff, 0, sizeof(buff));
	ret = read(fd, buff, sizeof(buff));
	if ((ret > 0)&&(!strncmp(buff, CONNECTION_MSG_STRING, ret)))
	{
		LOGE("Recv msg:%s in screenrecorder_init", buff);
		*connFd = fd;
	}
	else
		return -1;

	int n = 15;
	while(n--)
	{
		fd = create_local_socket_client(LOCAL_SOCKET_COMMAND_NAME);
		if (fd <= 0)
			usleep(200*1000);
		else
			break;
	}

	//LOGWYJ("Create local socket success(name=%s,fd=%d)", LOCAL_SOCKET_COMMAND_NAME, fd);
	if (fd <= 0)
		return -1;
	
	*cmdFd = fd;
	
	return 0;
}


int screenrecorder_set_rate(int sockFd, int fps)
{
	int ret;
	SR_EVENT_S msg;
	msg.evt = EVENT_SET_RATE;
	msg.ext1 = fps;

	//LOGWYJ("screenrecorder_set_rate in ScreenRecord_client");

	ret = write(sockFd, &msg, sizeof(SR_EVENT_S));
	if (ret <= 0)
	{
		LOGE("Send failed with ret=%d, error:%s", ret, strerror(errno));
		return -1;
	}	
	return 0;
}

int screenrecorder_set_format(int sockFd, output_format_e format)
{
	int ret;
	SR_EVENT_S msg;
	msg.evt = EVENT_SET_OUTPUTFORMAT;
	msg.ext1 = format;

	//LOGWYJ("screenrecorder_set_format in ScreenRecord_client");
	
	ret = write(sockFd, &msg, sizeof(SR_EVENT_S));
	if (ret <= 0)
	{
		LOGE("Send failed with ret=%d, error:%s", ret, strerror(errno));
		return -1;
	}
	return 0;
}

int screenrecorder_set_size(int sockFd, int width, int height)
{
	int ret;
	SR_EVENT_S msg;
	msg.evt = EVENT_SET_OUTPUTSIZE;
	msg.ext1 = width;
	msg.ext2 = height;

	//LOGWYJ("screenrecorder_set_size in ScreenRecord_client");
		
	ret = write(sockFd, &msg, sizeof(SR_EVENT_S));
	if (ret <= 0)
	{
		LOGE("Send failed with ret=%d, error:%s", ret, strerror(errno));
		return -1;
	}
	return 0;
}

typedef struct PARA_S
{
	int listenFd;
	LISTENFUNC func;
	void *data;
}Para_S;

void *ListenFunc(void *para)
{
	int ret;
	int fd;
	LISTENFUNC func;
	void *data;
	char buff[256];

	//LOGWYJ("ListenFunc------");
	
	if (!para)
	{
		LOGE("ListenFunc  para NULL");
		return NULL;
	}
	
	Para_S *data_s = (Para_S *)para;
	fd = data_s->listenFd;
	func = data_s->func;
	data = data_s->data;
	free(para);

	//LOGWYJ("ListenFunc--wait for disconnection,fd=%d", fd);
	ret = read(fd, buff, sizeof(buff));
	if ((ret <= 0)&&(!strncmp(buff, DISCONNECTION_MSG_STRING, sizeof(DISCONNECTION_MSG_STRING))))
	{
		LOGE("Recv msg FAILED in ListenFunc");
	}

	//LOGWYJ("ListenFunc-ret=%d-buff:%s----",ret, buff);
	if (func)
	{
		func(data);
	}
	
	return NULL;

}

int screenrecorder_start(int sockFd, int connFd, LISTENFUNC func, void *data)
{
	int ret;
	SR_EVENT_S msg;
	msg.evt = EVENT_START;

	//LOGWYJ("screenrecorder_start in ScreenRecord_client");
	
	ret = write(sockFd, &msg, sizeof(SR_EVENT_S));
	if (ret <= 0)
	{
		LOGE("Send failed with ret=%d, error:%s", ret, strerror(errno));
		return -1;
	}

	Para_S *para = (Para_S *)malloc(sizeof(Para_S));
	para->listenFd = connFd;
	para->func = func;
	para->data = data;
	pthread_attr_t attr;
	pthread_t threadID;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);	
	ret = pthread_create(&threadID, (const pthread_attr_t *) &attr, ListenFunc, para);
	pthread_attr_destroy(&attr);
	if (0 != ret)
	{
		LOGE("Create a thread for socketclient Failed");
		free(para);
	}
	
	return 0;
}


int screenrecorder_stop(int sockFd)
{
	int ret;
	SR_EVENT_S msg;
	msg.evt = EVENT_STOP;

	//LOGWYJ("screenrecorder_stop in ScreenRecord_client");
	
	ret = write(sockFd, &msg, sizeof(SR_EVENT_S));
	if (ret <= 0)
	{
		LOGE("Send failed with ret=%d, error:%s", ret, strerror(errno));
		return -1;
	}
	return 0;
}

int screenrecorder_deinit(int connFd, int cmdFd)
{

	//LOGWYJ("screenrecorder_deinit in ScreenRecord_client");
		
	close(cmdFd);
	close(connFd);
	return 0;
}




