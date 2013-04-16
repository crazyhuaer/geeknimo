
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_CONNECT 10
#define SEND_BUFFER 4096
#define SERVER_PATH "/tmp/myserver"


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


int sockfd;
int g_flag=0;
MOBILEPHONE_VAR *mobilephone_var;
pthread_mutex_t q_lock=PTHREAD_MUTEX_INITIALIZER;

MOBILEPHONE_VAR * initialization()
{
    MOBILEPHONE_VAR * mobilephone_var = (MOBILEPHONE_VAR *)malloc(sizeof(MOBILEPHONE_VAR));
    memset(mobilephone_var,0,sizeof(MOBILEPHONE_VAR));        
    return mobilephone_var;
}
	
int get_idle_client(MOBILEPHONE_VAR *mobilephone_var)
{
	int i;
	
	for (i = 0; i < MAX_CONNECT; i++)
	{
		if ((mobilephone_var->tcp_client)[i].state == CLIENT_CONNECT_IDLE)
		{
			return i;
		}
	}
	return -1;
}

void* pthread_func(void * p_arg)
{
    int idx;
	int ret;

////////////////////////////////////////////////////////////
    char http_recieve[4096];
////////////////////////////////////////////////////////////
    
	struct sockaddr_in cin;
    int sin_size = sizeof(struct sockaddr_in);

////////////////////////////////////////////////////////////
    memset(http_recieve,0,4096);
////////////////////////////////////////////////////////////

    MOBILEPHONE_VAR * mobilephone_var = (MOBILEPHONE_VAR *)p_arg;
    
    while(!mobilephone_var->g_exit_flag)
    {
        idx = get_idle_client(mobilephone_var);
        printf("mobilephone_var->tcp_server.listen_fd:%d\n",mobilephone_var->tcp_server.listen_fd);
        (mobilephone_var->tcp_client)[idx].accept_fd = \
                accept(mobilephone_var->tcp_server.listen_fd,\
				(struct sockaddr*)&cin,(socklen_t *)&sin_size);
        printf("pthread_func111111111\n");
        if((mobilephone_var->tcp_client)[idx].accept_fd < 0)
            continue;  
        if(mobilephone_var->tcp_server.connect_count > MAX_CONNECT)
        {
            close((mobilephone_var->tcp_client)[idx].accept_fd);
            continue;
        }
         
		if(mobilephone_var->tcp_server.connect_count >= 1)
		{
			close((mobilephone_var->tcp_client)[idx].accept_fd);
			continue;
		}
		//printf("VLC connect now!\n");
		//Content-Type: text/html   video/mpeg-2


////////////////////////////////////////////////////////////
        ret = read((mobilephone_var->tcp_client)[idx].accept_fd,http_recieve,4096);
        printf("accept ret:%d,%s\n",ret,http_recieve);
        if(ret <= 0)continue;
////////////////////////////////////////////////////////////

		char http_header[] = "HTTP/1.1 200 OK\r\nContent-Type: video/mpeg-2\r\n\r\n";
		ret = send( (mobilephone_var->tcp_client)[idx].accept_fd, \
						http_header, strlen( http_header ), 0 );
		if(ret < 0)
		{
			//LOGE("[Mobile]accept error,http header send error");
			close((mobilephone_var->tcp_client)[idx].accept_fd);
			continue;
		}

        if (fcntl((mobilephone_var->tcp_client)[idx].accept_fd,F_SETFL, O_RDONLY|O_NONBLOCK) < 0) 
        { 
            close((mobilephone_var->tcp_client)[idx].accept_fd);
			continue;
        }
		pthread_mutex_lock(&q_lock);
        printf("send http header:%s\n",http_header);
    
		mobilephone_var->tcp_server.connect_count++;
		(mobilephone_var->tcp_client)[idx].state = CLIENT_CONNECT_BUSY;
		pthread_mutex_unlock(&q_lock);
    }
    
    return NULL;
}


void build_select_list(int * highsock,MOBILEPHONE_VAR * mobilephone_var)
{
    int i;
    *highsock = 0;

    FD_ZERO(&(mobilephone_var->tcp_server.read_fds));

    pthread_mutex_lock(&q_lock);
    for(i=0; i < MAX_CONNECT; i++)
    {  
        if((mobilephone_var->tcp_client)[i].state == CLIENT_CONNECT_BUSY)
        {
            FD_SET((mobilephone_var->tcp_client)[i].accept_fd,\
					&(mobilephone_var->tcp_server.read_fds));
				
            if(*highsock < (mobilephone_var->tcp_client)[i].accept_fd)
                *highsock = (mobilephone_var->tcp_client)[i].accept_fd;
        }      
    }
    pthread_mutex_unlock(&q_lock);
}

void deinitialization(MOBILEPHONE_VAR * mobilephone_var)
{
    free(mobilephone_var);
}

void * httpserver_thread(void *para)
{
    int i,ret;
    char buff[SEND_BUFFER];
    int highsock;
    int readsocks;
    int total_bytes;
    int recv_bytes;
    int sent_bytes;
    int shall_sent_bytes;
    char request[4096];
  
    pthread_t tidp;
    
    struct timeval tv;
    
    //Initialize variables
    ret = 1;
    highsock = 0;
    readsocks = 0;
    total_bytes = 0;
    sent_bytes = 0;
    shall_sent_bytes = 0;
    memset(request,0,4096);
    
    mobilephone_var = initialization();
    mobilephone_var->tcp_server.servaddr.sin_family = AF_INET;
    mobilephone_var->tcp_server.servaddr.sin_port = htons(*(int *)para);
    mobilephone_var->tcp_server.servaddr.sin_addr.s_addr = INADDR_ANY;
    mobilephone_var->tcp_server.listen_fd= socket(AF_INET,SOCK_STREAM,0);

    ret = setsockopt(mobilephone_var->tcp_server.listen_fd,SOL_SOCKET,\
                    SO_REUSEADDR,(char *)&ret,sizeof(ret));
    
    bind(mobilephone_var->tcp_server.listen_fd,(struct sockaddr*)&(mobilephone_var->tcp_server.servaddr),sizeof(mobilephone_var->tcp_server.servaddr));
    listen(mobilephone_var->tcp_server.listen_fd,10);
    ret = pthread_create(&tidp,NULL,pthread_func,(void *)mobilephone_var);

    if(ret < 0)
    {
        printf("create thread is failed!\n");
        return NULL;
    }
	
    while(!g_flag)
    {
        tv.tv_sec = 0;
        tv.tv_usec = 50*1000;   
        build_select_list(&highsock,mobilephone_var);

        recv_bytes = read(sockfd,buff,SEND_BUFFER);
        //printf("recv_bytes:%d\n",recv_bytes);       
        
        readsocks = select(highsock+1,&(mobilephone_var->tcp_server.read_fds),0,0,&tv);
        
        if(readsocks < 0)
        {
           printf ("[ERROR] main select %d:%s\n", errno, strerror(errno));
           continue;
        }
        for ( i = 0; i < MAX_CONNECT; i++)
        {
            if((mobilephone_var->tcp_client)[i].state == CLIENT_CONNECT_BUSY)
            { 
                if((ret = recv((mobilephone_var->tcp_client)[i].accept_fd, \
                            request, sizeof( request ), 0 )) == 0)
                {
                    close((mobilephone_var->tcp_client)[i].accept_fd);
                    memset(&(mobilephone_var->tcp_client)[i],0,sizeof((mobilephone_var->tcp_client)[i]));
                    (mobilephone_var->tcp_client)[i].index = i;
                    mobilephone_var->tcp_server.connect_count--;
               
                    continue;
                }
                //printf("recv string:%s\n",request);
               
                total_bytes = 0;
                //接收从localsocket中得到的数据
                //usleep(33*1000);
                //ret = recv( (mobilephone_var->tcp_client)[i].accept_fd, request, sizeof( request ), 0 );
                
        	    shall_sent_bytes = recv_bytes;
				
           		while (total_bytes < recv_bytes)
            	{ 

            		sent_bytes = send((mobilephone_var->tcp_client)[i].accept_fd, buff, \
                                        shall_sent_bytes, 0); 

            		if (sent_bytes == 0 && (errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN))
            		{
            			printf ("[WAR] sent_bytes %d, errno%d:%s\n", sent_bytes, errno, strerror(errno));
            			continue;
            		}
            		else if (sent_bytes <= 0)
            		{
                        printf("[FATAL]...%d,%s!!!\n",errno,strerror(errno));
            			return NULL;
            		}
            		total_bytes += sent_bytes;
            		shall_sent_bytes -= sent_bytes;
                    //printf("\trecv_bytes:%d total_bytes:%d\n",recv_bytes,total_bytes);
            	}	
            }  
                
        }
    } 
    deinitialization(mobilephone_var);
    return NULL;
}

int httpserver(int *port)
{
	int ret;
	pthread_t localpid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);	
	ret = pthread_create(&localpid, (const pthread_attr_t *)&attr,httpserver_thread,(void *)port);
	pthread_attr_destroy(&attr);

	return 0;
}

int main(int argc,char * argv[])
{
    int ret;
    int port;
  
    struct sockaddr_un  server_addr;

    port = 1234;
    sockfd = socket(AF_LOCAL,SOCK_STREAM,0);
    bzero(&server_addr,sizeof(server_addr));

    server_addr.sun_family = AF_LOCAL;

    strcpy(server_addr.sun_path,SERVER_PATH);
    ret = connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    
    if(ret == 0)
    {
		ret = httpserver(&port);
		if(ret < 0)
		{
			perror("httpserver error..");
			exit(1);
		}
        while(1);
    }
    
    return 0;
}
