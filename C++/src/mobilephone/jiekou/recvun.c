#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <sys/un.h>
#include <stdio.h>

#define SERVER_PATH "/tmp/myserver"

int main()
{
    int sockfd;
    char recvdata[1024];
    struct sockaddr_un  server_addr;

    sockfd = socket(AF_LOCAL,SOCK_STREAM,0);
    bzero(&server_addr,sizeof(server_addr));

    server_addr.sun_family = AF_LOCAL;

    strcpy(server_addr.sun_path,SERVER_PATH);

    connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
	
    read(sockfd,recvdata,1024);
	


    return 0;
}
