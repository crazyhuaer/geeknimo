/*
 * =====================================================================================
 *
 *       Filename:  Execute_server.cpp
 *
 *    Description:  Suspend the java process and jar process.
 *
 *        Version:  1.0
 *        Created:  04/15/2013 10:52:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  BackGarden_Straw.Neo (BackGarden_Straw), 20549304@163.com
 *   Organization:  BackGarden_Straw
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "Execute_server.h"

#define MAX_LENGTHS (4096*10)
#define SERVER_PORT 5588
#define SHARED_MEMORY_SIZE (4*1024)

char * create_share_memory(int key, int size){
	HANDLE config_id;
	char *mem_addr;

	config_id = OS_shmget(key,size);
	if(config_id < 0)
	{
		OS_log(LVL_ERR,0,"OS_configConnect: OS_shmget error--shared memory not exit");
		return NULL;
	}
	
	mem_addr = (char *)OS_shmat(config_id);
	if(mem_addr < 0)
	{
		OS_log(LVL_ERR,0,"OS_configConnect: bind the shared memory error");
		return NULL;
	}
    
    return mem_addr;
}

int close_share_memory(char * share_memory){
	int ret;
	ret = OS_shmdt(share_memory);
	if(ret < 0)
	{
		OS_log(LVL_ERR, 0, "disconnect the shared memory failed");
		return -1;
	}
	return 0;
}

int main(int argc, const char *argv[]){

    // for share memory
    char * shared_mem;
    char receive_command[SHARED_MEMORY_SIZE];

    // init the share memory and log   
    OS_logInit(NULL,0,1);           

    // init the socket
    int           sock_fd;
    struct        sockaddr_in server_addr,client_addr;

    int           return_status;
    int           receive_data_length;
    socklen_t     sockaddr_len;

    long          receive_key;

    // set the socket
    sock_fd = socket(AF_INET,SOCK_DGRAM,0);
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    server_addr.sin_port = htons(SERVER_PORT);

    sockaddr_len = sizeof(server_addr);

    // build the socket
    return_status = bind(sock_fd,(struct sockaddr *)&server_addr,sockaddr_len);
    if(return_status == -1){
        printf("bind error,%d\n",errno);
        exit(1);
    }else{

        char message[MAX_LENGTHS];

        // do job
        while(1){
            memset(message,MAX_LENGTHS,0);
            memset(receive_command,MAX_LENGTHS,0);
            
            receive_data_length = recvfrom(sock_fd,message,MAX_LENGTHS,0,(sockaddr *)&client_addr,&sockaddr_len);

            if(receive_data_length < 0){
                continue;
            }else{
                // revieve the command,do that.
                printf("message:%s\n",message);
                receive_key = strtol(message,(char **)NULL,10);        
                printf("receive_key:%ld\n",receive_key);
                
                // read the share memory
                shared_mem = create_share_memory(receive_key, SHARED_MEMORY_SIZE);

                if(shared_mem == NULL)
                {
                    OS_log(LVL_ERR,0,"get shared memory failed");
                    return -1;
                }else{
                    //strcpy(shared_mem,command);
                    strncpy(receive_command, shared_mem, n);
                    printf("shared_mem:%s\n",shared_mem);
                    sleep(5);
                    shared_mem[0] = 0;
                }
                          
                
            }
        }
    }
    
    return 0;
}
