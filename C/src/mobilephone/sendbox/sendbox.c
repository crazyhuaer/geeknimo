    
#include "sendbox.h"

#define SERVER_PORT 3938

int main(int argc,char * argv[])
{
    //Define the variables
    int send_data_length;
    GLOBAL_VAR * global_var;
    
    //Initialize variables
    global_var = initialization();


	for (i = 0; i < number_count; i++) 
	{
		/* code */
	}



    //Do job!
    ////////////////////////////////////////////////
    while(1)
    {
        send_data_length = sendto(global_var->socket_fd, global_var->send_data, \
                  strlen(global_var->send_data),0,(struct sockaddr *)&global_var->server_addr,\
                  sizeof(struct sockaddr));
        if(send_data_length > 0)printf("%s\n",global_var->send_data);
        else PERROR("Send Error!");
        sleep(1);  
    }
    ////////////////////////////////////////////////

    //Deinitialize the variables
    deinitialization(global_var);
    pthread_exit(NULL);
    return 0;
}

GLOBAL_VAR * initialization()
{
    int addr_len,ret,value;

    addr_len = sizeof(struct sockaddr);

    GLOBAL_VAR * global_var = malloc(sizeof(GLOBAL_VAR));
    memset(global_var,0,sizeof(GLOBAL_VAR));

    global_var->mutex_id = OS_mutexCreate();
    global_var->sem_id = OS_semCreate(1);
    global_var->msgq_id = OS_msgqCreate(10,4);

    if( (global_var->socket_fd = socket(AF_INET,SOCK_DGRAM,0) ) == -1)
    {
        PERROR("[FATAL]..Socket is not establish.");
        exit(1);
    }

    global_var->send_data = "=====Send Sucessful=====\n";
    global_var->server_addr.sin_family = AF_INET;
    global_var->server_addr.sin_port = htons(SERVER_PORT);
    global_var->server_addr.sin_addr.s_addr = inet_addr("192.168.6.211");

	value = 1;
	ret = setsockopt(global_var->socket_fd, SOL_SOCKET, SO_REUSEADDR, (const char *)&value, sizeof(int));

	value = 5 * 1024;
	ret = setsockopt(global_var->socket_fd, SOL_SOCKET, SO_SNDBUF,  &value, sizeof(value));

    bind(global_var->socket_fd,(struct sockaddr *)&global_var->server_addr,addr_len);
    
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
