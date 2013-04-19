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

#define MAX_LENGTHS 256
#define SERVER_PORT 5588
#define SHARED_MEMORY_SIZE (4*1024)

HANDLE config_id;

char * create_share_memory(int key, int size)
{
	
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

int close_share_memory(char * share_memory)
{
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

void sig_handler(int signo)
{
    if (signo == SIGINT)
        exit(1);
}

int  os_system(const char * cmd)
{
    pid_t status;

    status = system(cmd);
    if (status == -1)
        return -1981;
    else if (WIFEXITED(status))
        return WEXITSTATUS(status);

    return -1981;
}

int main(int argc, const char *argv[])
{

    // for share memory
    int     ret;
    char * shared_mem;
    char receive_command[SHARED_MEMORY_SIZE];

    int     total_time_cnt;
    int     jar_count_max;
    int     java_count_max;

    // init the share memory and log   
    OS_logInit(NULL,0,1);           

    // init the socket
    int           sock_fd;
    struct        sockaddr_in server_addr,client_addr;

    int           return_status;
    int           receive_data_length;
    socklen_t     sockaddr_len;
    int          optval;
    long          receive_key;
    int          sleep_var;
    int          ms_time_cnt;

    total_time_cnt = 0;
    jar_count_max = 0;
    java_count_max = 0;
    sleep_var = 0;
    
    if(argc >= 2)
    {
        sleep_var = atoi(argv[1]);
        printf("init sleep time=%d ms\n",sleep_var);
        sleep_var *= 1000;
    }
    
    // signal sigint
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        OS_log(LVL_ERR,0,"can't catch SIGINT");

    // set the socket
    sock_fd = socket(AF_INET,SOCK_DGRAM,0);
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    server_addr.sin_port = htons(SERVER_PORT);
   
    sockaddr_len = sizeof(server_addr);
    
    // build the socket
    return_status = bind(sock_fd,(struct sockaddr *)&server_addr,sockaddr_len);
    if(return_status == -1)
    {
        OS_log(LVL_ERR,0,"bind error");
        exit(1);
    }
    else
    {
        char message[MAX_LENGTHS];

        optval = 1;
        if(setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&optval, sizeof(optval)) < 0)
        {
            OS_log(LVL_WRN, 0,"WARNING--setsockopt SO_REUSEADDR failed");
        }

        optval = 128*1024;
        if(setsockopt(sock_fd, SOL_SOCKET, SO_RCVBUF, (char *)&optval, sizeof(optval)) < 0)
        {
            OS_log(LVL_WRN, 0,"WARNING--setsockopt SO_RCVBUF failed");
        }
        
        // do job
        while(1)
        {
            memset(message,MAX_LENGTHS,0);
            memset(receive_command,MAX_LENGTHS,0);
  
            receive_data_length = recvfrom(sock_fd,message,MAX_LENGTHS,0,(sockaddr *)&client_addr,&sockaddr_len);

            if(receive_data_length < 0)
            {
                continue;
            }
            else
            {
                // revieve the command,do that.
                //printf("message:%s\n",message);
                receive_key = strtol(message,(char **)NULL,10);        
                //printf("receive_key:%ld\n",receive_key);
                
                // read the share memory
                shared_mem = create_share_memory(receive_key, SHARED_MEMORY_SIZE);

                if(shared_mem == NULL)
                {
                    OS_log(LVL_ERR,0,"get shared memory failed");
                    return -1;
                }
                else
                {  
                    printf("%s\n",shared_mem+1);
                    
                    if(shared_mem[0]=='1')
                        shared_mem[0] = 0;
                    else
                    {
                        OS_log(LVL_ERR,0,"something wrong,shared_mem[0]=%d,pid=%s\n",shared_mem[0],message);
                    }

                    ms_time_cnt = 0;
                    total_time_cnt = 0;

                    for(;;)
                    {     
                        if(shared_mem[0]=='2')
                        {
                            printf("\nfinish exec!\n");
                            
                            // count the jar and java
                            if(!memcmp(shared_mem+1,"jar",3))
                            {
                               if( total_time_cnt > jar_count_max)
                               {
                                    jar_count_max = total_time_cnt;
                               }
                            }
                            
                            if(!memcmp(shared_mem+1,"java",4))
                            { 
                               if( total_time_cnt > java_count_max)
                               {
                                    java_count_max = total_time_cnt;
                               }
                            }

                            printf("jar run:%d\n",jar_count_max);
                            printf("java run:%d\n",java_count_max);
                            
                            break;
                        }
                        
                        usleep(100000);
                        total_time_cnt++;
                        ms_time_cnt++;
                        if(ms_time_cnt >= 100)
                        {
                            OS_log(LVL_ERR,0,"running 10 sec not exit!,pid=%s",message);
                            ms_time_cnt = 0;
                        }
                            
                    }
                    
                    ret = close_share_memory(shared_mem);
                    if(sleep_var)
                        usleep(sleep_var);
                }
            }
        }
    }
    
    return 0;
}
