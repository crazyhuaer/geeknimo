/*
 *	Code copyright by wangyunjin 
 *	Date@20120906
 *     For testing the ScreenRecorder_client Interface function
 *
 */

#define LOG_TAG "ScreenRecorder_client_test"

#include <utils/Log.h>
#include <utils/String8.h>
#include <utils/Errors.h>
#include <fcntl.h>
#include <unistd.h>

#include <ScreenRecorder_client.h>
#include <selectmode.h>

typedef struct
{
	int connFd;
	int cmdFd;
}PTHREAD_PARA_S;

int g_flag = 0;

void *listenThreadFunc(void *para)
{
	PTHREAD_PARA_S *data = (PTHREAD_PARA_S *)para;
	LOGWYJ("listenThreadFunc: confd=%d,cmdfd=%d ", data->connFd, data->cmdFd);

	g_flag = 0;
	
	screenrecorder_deinit(data->connFd, data->cmdFd);
	
	free(para);
	return NULL;
}

int test_socket(int cmdFd, int connFd, int secs)
{
	int ret;
	int mode;
	int port = 80;
	char * path = "/tmp/myvideo";

	ret = screenrecorder_set_rate(cmdFd, 20);
	if (ret == -1)
		return -1;

	ret = screenrecorder_set_format(cmdFd, OUTPUT_FORMAT_MPEG_4);
	if (ret == -1)
		return -1;

	ret = screenrecorder_set_size(cmdFd, 1024, 600);
	if (ret == -1)
		return -1;

	PTHREAD_PARA_S *para = (PTHREAD_PARA_S *)malloc(sizeof(PTHREAD_PARA_S));
	para->connFd = connFd;
	para->cmdFd = cmdFd;
	ret = screenrecorder_start(cmdFd, connFd, (LISTENFUNC)listenThreadFunc, para);
	
	if (ret == -1)
		return -1;

	ret = localwrite(cmdFd,path);
	if(ret < 0)
		return -1;

	ret = httpserver(cmdFd,port);
	if(ret < 0)
		return -1;


	sleep(secs);

	ret = screenrecorder_stop(cmdFd);
	if (ret == -1)
		return -1;

	
	return 0;
}


int main()
{
	int connSocketFd, cmdSocketFd;
	int ret, flag;

	LOGI("start ScreenRecorder_client_test");
	flag = 0;
	ret = screenrecorder_init(&connSocketFd,&cmdSocketFd);
	if (ret < 0)
		return -1;
	g_flag = 1;
	test_socket(cmdSocketFd, connSocketFd,10);
	
//LOGWYJ("wait-8S--connSocketFd=%d, cmdSocketFd=%d",connSocketFd, cmdSocketFd);

	while(g_flag)
	{
		//LOGWYJ("wait---");	
		usleep(100*1000);
	}

	LOGI("Test over!!");
	return 0;
}



