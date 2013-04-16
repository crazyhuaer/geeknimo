#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <error.h>
#include <sys/un.h>
#include <errno.h>

#define SERVER_PATH "/tmp/myserver"

int send_to_server(int connect_socket,char * buff);

int main(int argc,char * argv[])
{
    int ret;
    char senddata[1024] = "hello,world!";
    char recvdata[1024];
	int flag,ret_bytes;
    int listenfd,connfd;
    socklen_t chilen;
    struct sockaddr_un cliaddr,servaddr;

    memset(recvdata,0,1024);
    listenfd = socket(AF_UNIX,SOCK_STREAM,0);
    unlink(SERVER_PATH);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path,SERVER_PATH);

    ret = bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    
    ret = listen(listenfd,0);

    chilen = sizeof(cliaddr);

    flag = 0;
    while(!flag)
    {
        if((connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&chilen)) < 0 )
        {
            if(errno == EINTR)
            {
                continue;
            }
            else
            {
                //printf("accept error.\n");
				continue;
            }
        }
        else
        {
            printf("=====Connect Sucessful=====\n");
            while(!flag)
            {
                if((ret_bytes = read(connfd,recvdata,4)) <0)
                    continue;
                else
                {
                    switch(recvdata[0])
                    {
                        case 0:
                            printf("=====Video size is set.=====\n");
                            read(connfd,recvdata,4);
                            printf("%d %d %d %d\n",recvdata[0],recvdata[1],recvdata[2],recvdata[3]);
                            printf("====video heigh is:%d====\n",recvdata[1]*256+recvdata[0]);
                            read(connfd,recvdata,4);
                            printf("%d %d %d %d\n",recvdata[0],recvdata[1],recvdata[2],recvdata[3]);
                            printf("====video width is:%d====\n",recvdata[1]*256+recvdata[0]);
                            break;
                        case 1:
                            printf("=====Video rate is set.=====\n");
                            read(connfd,recvdata,4);
                            printf("====Video rate is:%d====\n",recvdata[0]);
                            break;
                        case 2:
                            printf("=====Video format is set.=====\n");
                            read(connfd,recvdata,4);
                            printf("====Video format is:%d====\n",recvdata[0]);
                            flag = 1;
                            break;
                        case 3:
                            printf("=====Start transport video data.=====\n");
                            break;
                        default:
							flag = 0; 
                    }
                }
            }
            
            while(!flag)
            {
                usleep(300);
                ret_bytes = write(connfd,senddata,strlen(senddata)+1);
            }
            
        }
    }   

    return 0;
}


int send_to_server(int connect_socket,char * buff)
{
	int ret;
	ret = write(connect_socket,buff,strlen(buff)+1);

	if(ret < 0)
	{
		printf("[FATAL]..write to server\n");
		return -1;
	}
	return 0;
}
