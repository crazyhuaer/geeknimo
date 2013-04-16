/*
 * =====================================================================================
 *
 *       Filename:  suspend_jar.cpp
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
#include "suspend_jar.h"

#define MAX_LENGTH          256
#define SERVER_IP           "127.0.0.1"
#define SERVER_PORT         5588
#define SHARED_MEMORY_SIZE  (4*1024) 

HANDLE config_id;
char * create_share_memory(int key, int size){
	
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
    
    memset(mem_addr,0,size);
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
    OS_shmclose(config_id);
	return 0;
}


int main(int argc, const char *argv[]){

    // for our
    int     circle;
    int     check_times;
    char    command[4*1024];

    // for share memory
	int key;
	int ret;
	char *shared_mem;
     pid_t pid = getpid();

    // for socket
    int         send_data_len;
    int         client_sockfd;
    struct      sockaddr_in server_addr;
    socklen_t   server_len;    

    // for our init
    check_times = 0;

    // got the argv[]
    memset(command,0,4*1024);
    strcat(command,"1");
    strcat(command,"jar ");
    for(circle = 1; circle < argc;circle++){
        strcat(command,argv[circle]);
        strcat(command," ");
    }
    //printf("%s\n",command);
    
    // init the share memory and log
    OS_logInit(NULL,0,1);
    key = pid;
    printf("key:%d\n",key);
    shared_mem = create_share_memory(key, SHARED_MEMORY_SIZE);
    	if(shared_mem == NULL)
	{
		OS_log(LVL_ERR,0,"get shared memory failed");
		return -1;
	}else{
        strcpy(shared_mem,command);
	}

    // init the socket
    bzero(&server_addr,sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // build the socket and do job
    if( inet_pton(AF_INET,SERVER_IP,&server_addr.sin_addr) <= 0){
        ret = close_share_memory(shared_mem);
        perror("inet_pton error");
        exit(1);
    }else{
        client_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        server_len = sizeof(server_addr);
        if( connect(client_sockfd,(struct sockaddr *)&server_addr,server_len) == -1){
            ret = close_share_memory(shared_mem);
            perror("connect error");
            exit(1);
        }else{
            char message_send[MAX_LENGTH];

            sprintf(message_send,"%d",key);

            send_data_len = 0;
            send_data_len = sendto(client_sockfd,message_send,MAX_LENGTH,0,\
                                (struct sockaddr *)&server_addr,sizeof(server_addr));

            if(send_data_len < MAX_LENGTH){
                printf("leave some data to send.");
            }else{
                while(shared_mem[0] && check_times++ < 100){
                    // check the status              
                    usleep(100000);
                }          
            }       
        }
    }

    ret = close_share_memory(shared_mem);
	if(ret < 0)
	{
		OS_log(LVL_ERR,0,"close the shared memory");
		return -1;
	}

    if(check_times > 100){
        printf("jar run 10s,error.\n");
    }
   
    return 0;
}
