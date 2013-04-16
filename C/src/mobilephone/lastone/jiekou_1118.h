#ifndef _JIEKOU_H_
#define _JIEKOU_H_
    /*********Header Files********/
    //Common Files
    #include <stdio.h>			//printf
    #include <stdlib.h>		    //abort
    #include <string.h>		    //memset
 
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

    //Someone
    #include <unistd.h>
    #include <stddef.h>
    #include <sys/un.h>
    #include <sys/stat.h>
    #include <pthread.h>
    
    /*********Macro Define*********/
    //Common Define
    #define  DEBUG_STATUS       1

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

pthread_mutex_t q_lock;

    //Function Prototype(Global function)
#ifdef __cplusplus
    extern "C" 
    {
#endif

/******************************************
连接localsocket,成功返回0，失败返回-1
*******************************************/
void init_flag(int *flag);

int connect_local(char *path,int *con_socket);

//设置帧的大小
int init_size(int connect_socket,int heigh,int width);

//设置视频的帧率
int init_rate(int connect_socket,int rate);

//设置视频的格式
int init_format(int connect_socket,int format);

//开始录制
int start_record(int mode,char * filename,int localsocket,int port,int *flag);

//停止录制
void stop_record(int *flag,char * path);

#ifdef __cplusplus
     }
#endif


#endif  // _JIEKOU_H_
