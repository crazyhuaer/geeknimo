
#ifndef _SELECT_MODE_H_
#define _SELECT_MODE_H_ 

    /*********Header Files********/
    //Common Files
    #include <stdio.h>			//printf
    #include <stdlib.h>		    //abort
    #include <string.h>		    //memset
	#include <unistd.h>
	#include <sys/select.h>

    
    //Exception Files
#ifdef WIN32
    #include <winsock2.h>
#else
    #include <time.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <net/if.h>
    #include <unistd.h>		    //close
    #include <signal.h>		    //signal
    #include <libgen.h>         //parse pathname
    #include <pthread.h>	    //pthread_create   
    #include <sys/ioctl.h>
    #include <arpa/inet.h>		//htonl
    #include <sys/types.h>
    #include <sys/socket.h>	    //socket
    #include <netinet/tcp.h>	//SOL_TCP
#endif  /* #ifdef WIN32*/

#include "ScreenRecorder_client.h"

    //Exception Define
#ifdef WIN32
    #define socklen_t		int
    #define SLEEP(x)		Sleep(x)
    #define CLOSESOCKET		closesocket
    #define PERROR(x)		printf("%s%d",x,WSAGetLastError())
#else
    #define CLOSESOCKET		    close
    #define SLEEP(x)	          usleep(1000*x)
    #define PERROR(x)	          perror(x)
#endif    /* #ifdef WIN32 */


enum
{
    CLIENT_CONNECT_IDLE,
    CLIENT_CONNECT_BUSY
};

typedef struct
{
	int connFd;
	int cmdFd;
}PTHREAD_PARA_S;

typedef struct
{
    int connect_count;
    int listen_fd;
    fd_set read_fds;
    struct sockaddr_in servaddr;
}TCP_SERVER;

typedef struct
{
    int index;
    int state;
    int accept_fd;

}TCP_CLIENT;

typedef struct
{
    int g_exit_flag;
    TCP_SERVER tcp_server;
    TCP_CLIENT tcp_client[10];  
}MOBILEPHONE_VAR;

int g_flag;
int localsocketfd;
int connsocketfd;
PTHREAD_PARA_S *para;


void *listenThreadFunc(void *para);

/*初始化封装*/
int init_localsocket();
int init_size(int height,int width);
int init_rate(int rate);
int init_format(int format);

/*开始录制*/
int start_record();

/*写本地本件*/
int localwrite(char * pathname);

/*发送到网络*/
int httpserver(int port);

/*停止录制*/
int stop_record();

/*去初始化封装*/
int deinit_localsocket();


#endif  //_SELECT_MODE_H_
