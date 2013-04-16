    
#include "recvbox.h"

#define SERVER_IP "192.168.6.168"
#define SERVER_UDP_PORT 3938
#define SERVER_TCP_PORT 3939

int main(int argc,char * argv[])
{
    //Define the variables
    int recv_bytes;
    GLOBAL_VAR * global_var;
    
    //Initialize variables
    global_var = initialization();

    //Do job!
    ////////////////////////////////////////////////
	while (1)
	{
		recv_bytes = recv(global_var->socket_fd,global_var->recv_buff, 4096, 0);
        
        
		if (recv_bytes == 0 && (errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN))
		{
			printf ("[WAR] recv_bytes %d, errno%d:%s\n", recv_bytes, errno, strerror(errno));
			continue;
		}
		else if (recv_bytes <= 0)
		{
			printf ("[ERROR] recv_bytes %d, errno%d:%s\n", recv_bytes, errno, strerror(errno));
			return recv_bytes;
		}
		else
		{
			printf("Recieve Data:%s\n",global_var->recv_buff);
		}
	}
        

    ////////////////////////////////////////////////

    //Deinitialize the variables
    deinitialization(global_var);
    pthread_exit(NULL);
    return 0;
}

GLOBAL_VAR * initialization()
{
    int  value, ret;
    GLOBAL_VAR * global_var = malloc(sizeof(GLOBAL_VAR));
    memset(global_var,0,sizeof(GLOBAL_VAR));

    global_var->mutex_id = OS_mutexCreate();
    global_var->sem_id = OS_semCreate(1);
    global_var->msgq_id = OS_msgqCreate(10,4);

//////////////////////////////

	global_var->socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	value = 1;
	ret = setsockopt(global_var->socket_fd, SOL_SOCKET, SO_REUSEADDR, (const char *)&value, sizeof(int));
	if (ret < 0)
	{
        PERROR("[FATAL]..setsockopt1");
		CLOSESOCKET(global_var->socket_fd);
		exit(-1);
	}

	value = 5 * 1024;
	ret = setsockopt(global_var->socket_fd, SOL_SOCKET, SO_RCVBUF,  &value, sizeof(value));
	if (ret < 0)
	{
		PERROR("[FATAL]..setsockopt2");
		CLOSESOCKET(global_var->socket_fd);
		exit(-1);
	}
    /*
	global_var->client_addr.sin_family = AF_INET;
	global_var->client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	global_var->client_addr.sin_port = htons(SERVER_UDP_PORT);
    
	ret = bind(global_var->socket_fd, (struct sockaddr *)&global_var->client_addr, sizeof(struct sockaddr_in));
	if (ret < 0)
	{
		PERROR("[FATAL]..Bind");
		CLOSESOCKET(global_var->socket_fd);
		exit(-1);
	}
	*/

	global_var->server_addr.sin_family = AF_INET;
	global_var->server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	global_var->server_addr.sin_port = htons(SERVER_TCP_PORT);
	ret = connect(global_var->socket_fd, (struct sockaddr*)&global_var->server_addr, sizeof(struct sockaddr_in));

	if (ret < 0)
	{
	    PERROR("[FATAL]..Connect");
		CLOSESOCKET(global_var->socket_fd);
		exit(-1);
	}
	printf ("[OK] connect %s:%d successfully\n", SERVER_IP, SERVER_TCP_PORT);

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




