#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <error.h>
#include <sys/un.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define SERVER_PATH "/tmp/myserver"

int send_to_server(int connect_socket,char * buff);

int main(int argc,char * argv[])
{
    int ret;
    int readfile_fd;
    char senddata[4096];
    char readdata[4096];
	int flag,ret_bytes;
    int listenfd,connfd;
    socklen_t chilen;
    struct sockaddr_un cliaddr,servaddr;

    ret_bytes = 1;
    memset(senddata,0,4096);
    listenfd = socket(AF_UNIX,SOCK_STREAM,0);
    unlink(SERVER_PATH);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path,SERVER_PATH);

    ret = bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    
    ret = listen(listenfd,1);

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
            printf("\n=====Connect Sucessful=====\n");
    
            
            //¿ªÎÄ¼þ£¬Ð´buff    send.html
            readfile_fd = open("qinqin.mpg",O_RDONLY);
            if(readfile_fd < 0)
            {
                perror("open the file error..");
                exit(1);
            }
            else
            {
                while(ret_bytes > 0)
                {
                    //usleep(3*100);
                    ret_bytes = read(readfile_fd,readdata,4096);
                    if(ret_bytes < 0)
                    {
                        perror("read the file error..");
                        exit(1);
                    }
                    else
                    {
                        ret = send_to_server(connfd,readdata);
                        if(ret < 0)
                        {
                            perror("send to server error..");
                            exit(1);
                        }
                    }
                }
                printf("\nSend Over!\n");
            }     
        }
    }   

    return 0;
}


int send_to_server(int connect_socket,char * buff)
{
	int ret;
	ret = write(connect_socket,buff,4096);

	if(ret < 0)
	{
		printf("[FATAL]..write to server\n");
		return -1;
	}
    //printf("sent to socket %d\n",ret);
	return 0;
}





