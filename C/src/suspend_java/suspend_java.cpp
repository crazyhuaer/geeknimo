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
#define COMMAND_LENGTHS     (4*1024)
#define SLEEP_TIME_COUNT    100
#define SLEEP_TIME_UNIT     100000
#define THE_MAX_TIME_EXIT_THREAD    100

HANDLE config_id;
char *shared_mem = NULL;
int system_ret;
char    pthread_args;


int check_process_exist_ex(char * prog_name,int *p_pid,int min_pid)
{
    int proc_pid;
    char tmpbuf[256];

    DIR              *pDir ;
    struct dirent    *ent  ;
    FILE *fd;

    pDir = opendir("/proc");

    while ((ent=readdir(pDir))!=NULL)
    {
        if (ent->d_type & DT_DIR)
        {
            if ((ent->d_name[0] >= '1') &&(ent->d_name[0] <= '9'))
            {
                proc_pid = atoi(ent->d_name);

                if (proc_pid > min_pid)
                {
                    sprintf(tmpbuf,"/proc/%s/cmdline",ent->d_name);
                    fd = fopen(tmpbuf,"rb");
                    if (fd)
                    {
                        tmpbuf[0] = 0;
                        fread(tmpbuf, 1, sizeof(tmpbuf), fd);
                        if (tmpbuf[0])
                        {
                            if (strstr(tmpbuf,prog_name))
                            {
                                if (p_pid)
                                    *p_pid = proc_pid;

                                closedir(pDir);
                                return 1;           // found the process
                            }
                        }
                        fclose(fd);
                    }
                    else
                        printf("open %s failed!\n",tmpbuf);
                }
            }
        }
    }

    closedir(pDir);
    return 0;
}

char * create_share_memory(int key, int size)
{
	
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
    if(share_memory == NULL)
    {
        return -1;
    }
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

void* pthread_func(void * p_arg)
{
    system_ret = system((char *)p_arg);    
    pthread_args = '1';
    return NULL;
}

int main(int argc, const char *argv[])
{

    // for our
    int     i;
    int     circle;
    int     check_times;
    char    command[COMMAND_LENGTHS];

    char * p_real_cmd;

    // pthread
    int     thread_pid;
    char    kill_command[256];
    char    kill_name[256];

    // for share memory
	int key;
	int ret;

    // for socket
    
    char message_send[MAX_LENGTH];
    int         send_data_len;
    int         client_sockfd;
    struct      sockaddr_in server_addr;
    socklen_t   server_len;    

    pid_t pid;
    int monitor_time_cnt;

    // signal sigint
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        OS_log(LVL_ERR,0,"can't catch SIGINT");


    if(strstr(argv[1],"--help"))
    {
        printf("this is serial_client\n");
        return 0;
    }

    if(!check_process_exist_ex("server_serial",&thread_pid,500))
    {
        printf("\n\npls running server_serial firstly!\n\n");
        return -1;
    }


    // init the share memory and log
    OS_logInit(NULL,0,1);


    pid = getpid();
    pthread_args = '0';

    
    
    // for our init
    check_times = 0;

    // got the argv[]
    //memset(command,0,4*1024);
    strcat(command,"1");
    for(circle = 0; circle < argc;circle++)
    {
        strcat(command,argv[circle]);
        strcat(command," ");
    }

    key = pid;
    //printf("key:%d\n",key);
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
            usleep(SLEEP_TIME_UNIT);
            if(check_times++ > SLEEP_TIME_COUNT)
            {
                check_times = 0;
                printf("this program run 10s,pid=%d\n",key);
            }
        }          
    }       

    p_real_cmd = command +1;
    
    if(!memcmp(p_real_cmd,"jar",3))
    {
        p_real_cmd[2]='1';
        strcpy(kill_name,"ja1");
    }
    else if(!memcmp(p_real_cmd,"java",4))
    {
        p_real_cmd[3]='1';
        strcpy(kill_name,"jav1");
    }
    else
    {
        printf("cmd error:\n %s\n",p_real_cmd);
    }

    while(pthread_args != '1')
    {
        system_ret = 0;
        thread_pid = 0;
        OS_thread_create((OS_THREAD_FUNC)pthread_func,(void *)p_real_cmd);
        

        usleep(SLEEP_TIME_UNIT);

        

   #if 0     
        if((ret == 0)&&(pthread_args == '0'))
        {
            //说明没有找到应该存在的进程，这是不应该出现的现象。
            printf("\n running %s, but process not exist!\n",kill_name);
            sleep(1);
            system_ret = -1;
            break;
        }
   #endif
   
        if(!strcmp(kill_name,"ja1"))
        {
            monitor_time_cnt = THE_MAX_TIME_EXIT_THREAD;
            printf("\nkill_name = ja1\n");
        }
        else
        {
            monitor_time_cnt = 7*THE_MAX_TIME_EXIT_THREAD;
            printf("\nkill_name = jav1\n");
        }
            
        for(i=0;(i<monitor_time_cnt)&&(pthread_args == '0');i++)
        {
            usleep(SLEEP_TIME_UNIT);
            if(!thread_pid)
            {
                check_process_exist_ex(kill_name,&thread_pid,500);
            }
            // if pthread_args = '1' break;
        }
        
        if(pthread_args == '1')
        {
            break;
        }
        else
        {
            if(thread_pid)
            {
                sprintf(kill_command,"kill -9 %d",thread_pid);
                system(kill_command);
                printf("\n\nfound %s block, kill pid %d\n",kill_name,thread_pid);
            }
            else
            {
                printf("\n running %s, but process not exist!\n",kill_name);
            }

            sleep(1);
            //因为kill掉system拉起的线程后，而使
            if((pthread_args=='1')&&thread_pid)
                pthread_args = '0';
            else
            {
                printf("\nkill the thread,but pthread_args!=1 \n");
            }
        }
    }
    

    //ret = system(p_real_cmd);

    shared_mem[0] = '2';
    
    close_share_memory(shared_mem);
    
   
    return system_ret;
}
