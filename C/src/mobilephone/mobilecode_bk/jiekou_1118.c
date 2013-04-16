

#include "jiekou_1118.h"

#define MAX_LENGTH 4096
#define MAX_CONNECT 10
#define C_PATH "/tmp/123"

int connect_local(char *PATH,int *con_socket)
{
    int cfd;
    struct sockaddr_un ser_addr;

    if((cfd = socket(AF_UNIX,SOCK_STREAM,0)) == -1)
    {
        perror("fail to create socket");
        return -1;
    }
    *con_socket = cfd;

    memset(&ser_addr,0,sizeof(ser_addr));
    ser_addr.sun_family = AF_UNIX;
    strcpy(ser_addr.sun_path,PATH);

    if(connect(cfd,(struct sockaddr*)&ser_addr,sizeof(struct sockaddr))<0)
    {
        perror("fail to connect");
        return -1;  
    }
    return 0;
}

int read_localsocket(int localsocket,char * buff,int len)
{
    if(!read(localsocket,buff,len))return -1; 
    return 0;
}

int init_all(int *flag)
{
    //用于设置是否退出录制
    *flag = 0;
}

//设置帧的大小
int init_size(int connect_socket,int heigh,int width)
{
    int ret;
    ret = write(connect_socket,&heigh,sizeof(heigh));
    if(ret < 0)
    {
        PERROR("[FATAL]..write to heigh ");
       return -1;
    }

    ret = write(connect_socket,&width,sizeof(width));
    if(ret < 0)
    {
        PERROR("[FATAL]..write to width ");
       return -1;
    }
    return 0;
}

//设置视频的帧率
int init_rate(int connect_socket,int rate)
{
    int ret;
    ret = write(connect_socket,&rate,sizeof(rate));
    if(ret < 0)
    {
        PERROR("[FATAL]..write to rate ");
       return -1;
    }
    return 0;
}

//设置视频的格式
int init_format(int connect_socket,int format)
{
    int ret;
    ret = write(connect_socket,&format,sizeof(format));
    if(ret < 0)
    {
        PERROR("[FATAL]..write to format ");
       return -1;
    }
    return 0;
}


MOBILEPHONE_VAR * initialization()
{
    MOBILEPHONE_VAR * mobilephone_var = malloc(sizeof(MOBILEPHONE_VAR));
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
    struct sockaddr_in cin;
    int sin_size = sizeof(struct sockaddr_in);
    MOBILEPHONE_VAR * mobilephone_var = (MOBILEPHONE_VAR *)p_arg;
    
    while(!mobilephone_var->g_exit_flag)
    {

        idx = get_idle_client(mobilephone_var);
        (mobilephone_var->tcp_client)[idx].accept_fd = \
                accept(mobilephone_var->tcp_server.listen_fd,(struct sockaddr*)&cin,(socklen_t *)&sin_size);
        if((mobilephone_var->tcp_client)[idx].accept_fd < 0)
            continue;  
        if(mobilephone_var->tcp_server.connect_count > MAX_CONNECT)
        {
            CLOSESOCKET((mobilephone_var->tcp_client)[idx].accept_fd);
            continue;
        }

        (mobilephone_var->tcp_client)[idx].state = CLIENT_CONNECT_BUSY;
        mobilephone_var->tcp_server.connect_count++;
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
            FD_SET((mobilephone_var->tcp_client)[i].accept_fd,&(mobilephone_var->tcp_server.read_fds));
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

int httpserver(int localsocket,int port)
{
    int i,ret;
    int len;
    char buff[4096];
    int highsock;
    int readsocks;
    int total_bytes;
    int recv_bytes;
    int sent_bytes;
    int shall_sent_bytes;

    pthread_t tidp;
    
    struct timeval tv;

    MOBILEPHONE_VAR *mobilephone_var;
    
    //Initialize variables
    ret = 1;
    highsock = 0;
    readsocks = 0;
    total_bytes = 0;
    sent_bytes = 0;
    shall_sent_bytes = 0;

    mobilephone_var = initialization();
    mobilephone_var->tcp_server.servaddr.sin_family = AF_INET;
    mobilephone_var->tcp_server.servaddr.sin_port = htons(port);
    mobilephone_var->tcp_server.servaddr.sin_addr.s_addr = INADDR_ANY;
    mobilephone_var->tcp_server.listen_fd= socket(AF_INET,SOCK_STREAM,0);
    bind(mobilephone_var->tcp_server.listen_fd,(struct sockaddr*)&(mobilephone_var->tcp_server.servaddr),sizeof(mobilephone_var->tcp_server.servaddr));
    listen(mobilephone_var->tcp_server.listen_fd,10);
    ret = pthread_create(&tidp,NULL,pthread_func,(void *)mobilephone_var);

    if(ret < 0)
    {
        printf("create thread is failed!\n");
        return -1;
    }
    while(!(*flag))
    {
        tv.tv_sec = 2;
        tv.tv_usec = 0;   
        build_select_list(&highsock,mobilephone_var);
        readsocks = select(highsock+1,&(mobilephone_var->tcp_server.read_fds),0,0,&tv);
        if(readsocks < 0)
        {
           printf ("[ERROR] main select %d:%s\n", errno, strerror(errno));
           continue;
        }
        for ( i = 0; i < MAX_CONNECT; i++)
        {
            pthread_mutex_lock(&q_lock);
            if((mobilephone_var->tcp_client)[i].state == CLIENT_CONNECT_BUSY)
            {  
                if(FD_ISSET((mobilephone_var->tcp_client)[i].accept_fd,&(mobilephone_var->tcp_server.read_fds)))
                {
                    CLOSESOCKET((mobilephone_var->tcp_client)[i].accept_fd);
                    memset(&(mobilephone_var->tcp_client)[i],0,sizeof((mobilephone_var->tcp_client)[i]));
                    (mobilephone_var->tcp_client)[i].index = i;
                    mobilephone_var->tcp_server.connect_count--;
                    
                    pthread_mutex_unlock(&q_lock);
                    continue;
                }
                pthread_mutex_unlock(&q_lock);
                total_bytes = 0;
                //接收从localsocket中得到的数据
                recv_bytes = read(localsocket,buff,50);
                /******************************/
                printf("%d\n",recv_bytes);
                /*******************************/
                
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
            			return sent_bytes;
            		}
            		total_bytes += sent_bytes;
            		shall_sent_bytes -= sent_bytes;
            	}
            }
            else    
                pthread_mutex_unlock(&q_lock);
        }
    } 
    deinitialization(mobilephone_var);
    return 0;
}

int localwrite(char * pathname,int localsocket)
{
    int fd;
    int n,m;
    int status;
    char buff[4096];
    int recv_bytes;

    status = 0;
    m = 0;
    
    while(1)
    {
        recv_bytes = read(localsocket,buff,4096);
        fd = open(pathname,O_RDWR|O_CREAT|O_APPEND,0777);
        if(fd < 0)
        {
            perror("failed to open");
            status = -1;
            break;
        }

        while(n = write(fd,buff,recv_bytes) && m < recv_bytes)
        {
            if( n < 0)
            {
                perror("failed to write");
                status = -2;
                break;
            }
            m += n;
        }

    }
    close(fd);
    return status;
}

int start_record(int mode,char * filename,int localsocket,int port,int *flag)
{
    int ret;
    ret = 0;
    if(mode == 1)
    {   
        ret = localwrite(filename,localsocket,flag);
        if(ret < 0)
        {
            printf("localwrite failed!\n");
            exit(1);
        }
    }
    if(mode == 2)
    {
        ret = httpserver(localsocket,port,flag);
        if(ret < 0)
        {
            printf("httpserver failed!\n");
            exit(1);
        }
    } 
    return ret;
}

void stop_record(int *flag,char * path)
{
    *flag = 1;
    unlink(path);
}

int main(int argc,char * argv[])
{
    int ret;
    /***********************************************/
   
    int con_socket;
    char *PATH = "/home/123";
    char *filename = "/mnt/hgfs/share/1";
    int port = 8000;
    int mode = 2;
    int flag = 0;

    
    /***********************************************/
    ret = connect_local(PATH,&con_socket);
    if(ret < 0)
    {
        printf("error connect jbm\n");
        exit(1);
    }
   
    start_record(mode,filename,con_socket,port,&flag);
    return 0;
}
