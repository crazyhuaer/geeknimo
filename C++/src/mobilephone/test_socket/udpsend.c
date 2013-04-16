    
#include "udpsend.h"

#define UDP_SEND_IP "192.168.6.168"
#define UDP_SEND_PORT 8000

int main(int argc,char * argv[])
{
    //Define the variables
    GLOBAL_VAR * global_var;
    int send_bytes;
    char send_data[] = "hello";
    //char send_data[4096];
    
    //Initialize variables
    global_var = initialization();


    //Do job!
    ////////////////////////////////////////////////
    while(1)
    {
        send_bytes = sendto(global_var->udp_send_sock,send_data,50,0,\
                            (struct sockaddr *)&global_var->udp_send_addr,sizeof(struct sockaddr)); 

        printf("recv_bytes:%d\n",send_bytes);
        
        SLEEP(1000);
    }
    ////////////////////////////////////////////////

    //Deinitialize the variables
    deinitialization(global_var);
    pthread_exit(NULL);
    return 0;
}

GLOBAL_VAR * initialization()
{
    int ret,value;
    GLOBAL_VAR * global_var = malloc(sizeof(GLOBAL_VAR));

    memset(global_var,0,sizeof(GLOBAL_VAR));

    global_var->mutex_id = OS_mutexCreate();
    global_var->sem_id = OS_semCreate(1);
    global_var->msgq_id = OS_msgqCreate(10,4);

    //////////////////////////////
    global_var->udp_send_sock = socket(AF_INET,SOCK_DGRAM,0);
    global_var->udp_send_addr.sin_family = AF_INET;
    global_var->udp_send_addr.sin_port = htons(UDP_SEND_PORT);
    global_var->udp_send_addr.sin_addr.s_addr = inet_addr(UDP_SEND_IP);

    value = 1;
    ret = setsockopt(global_var->udp_send_sock,SOL_SOCKET,SO_REUSEADDR,\
                    (const char *)&value,sizeof(int));
    value = 5*1024;
    ret = setsockopt(global_var->udp_send_sock,SOL_SOCKET,SO_SNDBUF,&value,sizeof(int));
    //ret = setsockopt(global_var->udp_send_sock,SOL_SOCKET,SO_RCVBUF,&value,sizeof(int));

    bind(global_var->udp_send_sock,(struct sockaddr *)&global_var->udp_send_addr,sizeof(struct sockaddr));

    //////////////////////////////    
    return global_var;
}

void* pthread_func(void * p_arg)
{

    return NULL;
}


void deinitialization(GLOBAL_VAR * global_var)
{
    free(global_var);
}




