    
#include "mobilephone.h"

MOBILEPHONE_VAR * mobilephone_var;

int main(int argc,char * argv[])
{
    //Define the variables
    int i,ret;
    int len;
    char buff[4096];
    int highsock;
    int readsocks;
    int total_bytes;
    int recv_bytes;
    int sent_bytes;
    int shall_sent_bytes;
    int udp_recv_sock;    
    struct sockaddr_in addr;
    
    //Initialize variables
    ret = 1;
    highsock = 0;
    readsocks = 0;
    total_bytes = 0;
    sent_bytes = 0;
    shall_sent_bytes = 0;
    len = 4096;

    udp_recv_sock = socket(AF_INET,SOCK_DGRAM,0);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(3938);
    //bind(udp_recv_sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
    
    mobilephone_var = initialization();

    //Do job!
    ////////////////////////////////////////////////
    mobilephone_var->tcp_server.servaddr.sin_port = htons(TPC_SERVER_PORT);
    mobilephone_var->tcp_server.servaddr.sin_addr.s_addr = inet_addr("192.168.6.168");
    mobilephone_var->tcp_server.listen_fd= socket(AF_INET,SOCK_STREAM,0);
    
    bind(mobilephone_var->tcp_server.listen_fd,\
        (struct sockaddr *)&mobilephone_var->tcp_server.servaddr,\
        sizeof(struct sockaddr));
    
    listen(mobilephone_var->tcp_server.listen_fd,10);

    recv_bytes = recvfrom(udp_recv_sock, buff, len, 0, (struct sockaddr*)&addr, NULL);
    printf("%d\n",recv_bytes);

    ret  = OS_thread_create((OS_THREAD_FUNC)pthread_func,NULL);
        
    while(1)
    {
        build_select_list(&highsock);
        
        readsocks = select(highsock+1,&(mobilephone_var->read_fds),0,0,NULL);
        
        if(readsocks < 0)
        {
           printf ("[ERROR] main select %d:%s\n", errno, strerror(errno));
           continue;
        }

        for ( i = 0; i < MAX_CONNECT; i++)
        {
            //Mutex
            ret = OS_mutexTake(mobilephone_var->mutex_id);
            if((mobilephone_var->tcp_client)[i].state == CLIENT_CONNECT_BUSY)
            {  
                if(FD_ISSET((mobilephone_var->tcp_client)[i].accept_fd,&(mobilephone_var->read_fds)))
                {
                    CLOSESOCKET((mobilephone_var->tcp_client)[i].accept_fd);
                    memset(&(mobilephone_var->tcp_client)[i],0,sizeof((mobilephone_var->tcp_client)[i]));
                    (mobilephone_var->tcp_client)[i].index = i;
                    mobilephone_var->tcp_server.connect_count--;
                    
                    ret = OS_mutexGive(mobilephone_var->mutex_id);
                    continue;
                }
                ret = OS_mutexGive(mobilephone_var->mutex_id);
                total_bytes = 0;

                //接收数据函数
                //len 是接收数据长度，在前面获得
                recv_bytes = recvfrom(udp_recv_sock, buff, len, 0, NULL, NULL);
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
            			//*err = errno;
            			return sent_bytes;
            		}

            		total_bytes += sent_bytes;
            		shall_sent_bytes -= sent_bytes;
            	}
        	    //multi_sock_assert(total_bytes == len);
            }
            else    ret = OS_mutexGive(mobilephone_var->mutex_id);
        }
    }
    ////////////////////////////////////////////////

    //Deinitialize the variables
    deinitialization(mobilephone_var);
    pthread_exit(NULL);
    return 0;
}

/**********************************************
int udp_sock_init()
{
	int udp_recv_sock, value, ret;

	struct sockaddr_in addr;
	udp_recv_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("192.168.6.168");
	addr.sin_port = htons(7788);
	ret = bind(udp_recv_sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));

	
	return udp_recv_sock;
}
*************************************************/

MOBILEPHONE_VAR * initialization()
{
    MOBILEPHONE_VAR * mobilephone_var = malloc(sizeof(MOBILEPHONE_VAR));
    memset(mobilephone_var,0,sizeof(MOBILEPHONE_VAR));

    mobilephone_var->mutex_id = OS_mutexCreate();
    mobilephone_var->sem_id = OS_semCreate(1);
    mobilephone_var->msgq_id = OS_msgqCreate(10,4);
        
    return mobilephone_var;
}

void* pthread_func(void * p_arg)
{
    int idx;
    int sin_size = sizeof(struct sockaddr_in);
    
    while(!mobilephone_var->g_exit_flag)
    {
        //ret = OS_mutexTake(mobilephone_var->mutex_id);
        idx = get_idle_client();

        (mobilephone_var->tcp_client)[idx].accept_fd = \
                accept(mobilephone_var->tcp_server.listen_fd,NULL,(socklen_t *)&sin_size);

        if((mobilephone_var->tcp_client)[idx].accept_fd < 0)
            continue;  

        if(mobilephone_var->tcp_server.connect_count > MAX_CONNECT)
        {
            CLOSESOCKET((mobilephone_var->tcp_client)[idx].accept_fd);
            continue;
        }

        (mobilephone_var->tcp_client)[idx].state = CLIENT_CONNECT_BUSY;

        mobilephone_var->tcp_server.connect_count++;
        //ret = OS_mutexGive(mobilephone_var->mutex_id);
    }
    
    return NULL;
}

int get_idle_client()
{
	int i;
	
	for (i = 0; i < MAX_CONNECT; i++)
	{
		if ((mobilephone_var->tcp_client)[i].state == CLIENT_CONNECT_IDLE)
		{
			return i;
		}
	}
	//all clients busy
	return -1;
}

void build_select_list(int * highsock)
{
    int i,ret;
    *highsock = 0;

    FD_ZERO(&(mobilephone_var->read_fds));
    
    ret = OS_mutexTake(mobilephone_var->mutex_id);
    for(i=0; i < MAX_CONNECT; i++)
    {
        
        if((mobilephone_var->tcp_client)[i].state == CLIENT_CONNECT_BUSY)
        {
            FD_SET((mobilephone_var->tcp_client)[i].accept_fd,&(mobilephone_var->read_fds));
            if(*highsock < (mobilephone_var->tcp_client)[i].accept_fd)
                *highsock = (mobilephone_var->tcp_client)[i].accept_fd;
        }      
    }
    ret = OS_mutexGive(mobilephone_var->mutex_id);
}

void deinitialization(MOBILEPHONE_VAR * mobilephone_var)
{
    free(mobilephone_var);
}




