
#ifndef _SELECT_MODE_H_
#define _SELECT_MODE_H_ 

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

int localsocketfd;
int connsocketfd;
PTHREAD_PARA_S *para;
pthread_mutex_t p_lock=PTHREAD_MUTEX_INITIALIZER;

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
