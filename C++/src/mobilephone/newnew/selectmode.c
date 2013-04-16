
#include "selectmode.h"

#define MAX_CONNECT 15

pthread_mutex_t q_lock=PTHREAD_MUTEX_INITIALIZER;

int init_localsocket()
{	
    g_flag = 0;
	int ret;
	ret = screenrecorder_init(&localsocketfd,&connsocketfd);
	if (ret < 0)
	    return -1; 
    return 0;
}

int init_size(int height,int width)
{	
    int ret;
    ret = screenrecorder_set_size(localsocketfd, height, width);
	if (ret == -1)
		return -1;
    return 0;
}
int init_rate(int rate)
{
    int ret;
    ret = screenrecorder_set_rate(localsocketfd, rate);
	if (ret == -1)
		return -1;
    return 0;
}
int init_format(int format)
{
    int ret;
    ret = screenrecorder_set_format(localsocketfd, format);
	if (ret == -1)
		return -1;
    return 0;
}

int start_record()
{
    int ret;
    para = (PTHREAD_PARA_S *)malloc(sizeof(PTHREAD_PARA_S));
    ret = screenrecorder_start(localsocketfd, connsocketfd, (LISTENFUNC)listenThreadFunc, para);
	if (ret == -1)
		return -1;
    return 0;
}

int localwrite(char * pathname)
{
    int fd;
    int n,m;
    int status;
    char buff[4096];
    int recv_bytes;

    status = 0;
    m = 0;
    
    while(!g_flag)
    {
        recv_bytes = read(localsocketfd,buff,4096);
        fd = open(pathname,O_RDWR|O_CREAT|O_APPEND,0777);
        if(fd < 0)
        {
            perror("failed to open");
            status = -1;
            break;
        }

        while((n = write(fd,buff,recv_bytes)) && (m < recv_bytes))
        {
            if( n < 0)
            {
                perror("failed to write");
                status = -2;
                break;
            }
			if(m < recv_bytes)
			{
				status = -3;
				break;
			}
			m += n;
        }

		if(status < 0) break;

    }
    close(fd);
    return status;
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

int httpserver(int port)
{
    int i,ret;
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
	
    while(!g_flag)
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
                recv_bytes = read(localsocketfd,buff,50);
                /******************************/
                
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

int stop_record()
{
    int ret;
    g_flag = 1;
	ret = screenrecorder_stop(localsocketfd);
    
	if (ret == -1)
		return -1;
	return 0;
}

int deinit_localsocket()
{
    int ret;
    free(para);
    ret = screenrecorder_deinit(connsocketfd, localsocketfd);
    
	if (ret == -1)
		return -1;
	return 0;
}

