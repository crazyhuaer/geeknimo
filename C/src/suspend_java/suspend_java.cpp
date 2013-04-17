/*
 * =====================================================================================
 *
 *       Filename:  suspend_java.cpp
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
#include "suspend_java.h"

#define MAX_LENGTH          256
#define SERVER_IP           "127.0.0.1"
#define SERVER_PORT         5588
#define SHARED_MEMORY_SIZE  (4*1024) 

HANDLE config_id;
char *shared_mem;
char * create_share_memory(int key, int size){
	
	char *mem_addr;

	config_id = OS_shmget(key,size);
	if(config_id < 0)
	{
		//OS_log(LVL_ERR,0,"OS_configConnect: OS_shmget error--shared memory not exit");
		printf("OS_configConnect: OS_shmget error--shared memory not exit");
		return NULL;
	}
	
	mem_addr = (char *)OS_shmat(config_id);
	if(mem_addr < 0)
	{
		//OS_log(LVL_ERR,0,"OS_configConnect: bind the shared memory error");
		printf("OS_configConnect: bind the shared memory error");
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
		//OS_log(LVL_ERR, 0, "disconnect the shared memory failed");
		printf("disconnect the shared memory failed");
		return -1;
	}
    OS_shmclose(config_id);
	return 0;
}

void sig_handler(int signo)
{
    int ret;
    if (signo == SIGINT)
    {
        ret = close_share_memory(shared_mem);
        	if(ret < 0)
        	{
        		//OS_log(LVL_ERR,0,"close the shared memory");
        		printf("close the shared memory");
        		return;
        	}  
    }
    return;
}

int main(int argc, const char *argv[])
{

    // for our
    int     circle;
    int     check_times;
    char    command[4*1024];
    timeval starttime,endtime;
    int  ms_use;
    char * p_real_cmd;

    // for share memory
	int key;
	int ret;
	
     

    // for socket
    int         send_data_len;
    int         client_sockfd;
    struct      sockaddr_in server_addr;
    socklen_t   server_len;    

    pid_t pid;

    // signal sigint
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        OS_log(LVL_ERR,0,"can't catch SIGINT");


    if(strstr(argv[1],"--help"))
    {
        printf("this is serial_client\n");
        //return 0;
    }


    // init the share memory and log
    OS_logInit(NULL,0,1);


    pid = getpid();

    
    // for our init
    check_times = 0;
    gettimeofday(&starttime,0);

    // got the argv[]
    //memset(command,0,4*1024);
    strcat(command,"1");
    for(circle = 0; circle < argc;circle++)
    {
        strcat(command,argv[circle]);
        strcat(command," ");
    }

    key = pid;
    printf("key:%d\n",key);
    shared_mem = create_share_memory(key, SHARED_MEMORY_SIZE);
    	if(shared_mem == NULL)
	{
		OS_log(LVL_ERR,0,"get shared memory failed");
		return -1;
	}
     else
	{
        strcpy(shared_mem,command);
	}

    // init the socket
    bzero(&server_addr,sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // build the socket and do job
    if( inet_pton(AF_INET,SERVER_IP,&server_addr.sin_addr) <= 0)
    {
        ret = close_share_memory(shared_mem);
        perror("inet_pton error");
        return -1;
    }
    
        client_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        server_len = sizeof(server_addr);

            char message_send[MAX_LENGTH];

            sprintf(message_send,"%d",key);

            send_data_len = 0;
            send_data_len = sendto(client_sockfd,message_send,MAX_LENGTH,0,\
                                (struct sockaddr *)&server_addr,sizeof(server_addr));

            if(send_data_len < MAX_LENGTH)
            {
                printf("leave some data to send.");
            }
            else
            {
                while(shared_mem[0])
                {
                    // check the status              
                    usleep(100000);
                    if(check_times++ > 100)
                    {
                        check_times = 0;
                        printf("this program run 10s\n");
                    }
                }          
            }       


    p_real_cmd = command +1;
    
    if(!memcmp(p_real_cmd,"jar",3))
    {
        p_real_cmd[2]='1';
    }
    else if(!memcmp(p_real_cmd,"java",4))
    {
        p_real_cmd[3]='1';
    }
    else
    {
        printf("cmd error:\n %s\n",p_real_cmd);
    }

    ret = system(p_real_cmd);

    shared_mem[0] = '2';
    
    close_share_memory(shared_mem);
	
    gettimeofday(&endtime,0);
    ms_use = (endtime.tv_sec - starttime.tv_sec)*1000 + (endtime.tv_usec - starttime.tv_usec)/1000;
    printf("timeuse %d (ms)\n",ms_use);
    
   
    return 0;
}
