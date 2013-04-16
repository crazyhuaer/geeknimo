/*
 * =====================================================================================
 *
 *       Filename:  httprecv.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/28/2012 09:02:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  BackGarden_Straw.Neo (BackGarden_Straw), 20549304@163.com
 *   Organization:  BackGarden_Straw
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//#define SERVER_IP "192.168.6.211"

int main(int argc, const char *argv[])
{
	
	int sock;
	int ret ;
	char * buff[4096];
	struct sockaddr_in connectsock;

    char request[1024];

    memset(request,0,1024);

	sock = socket(AF_INET,SOCK_STREAM,0);
    connectsock.sin_family = AF_INET;
	connectsock.sin_addr.s_addr = inet_addr(INADDR_ANY);
	connectsock.sin_port = htons(1234);
    
    ret = recv( sock, request, sizeof( request ), 0 );
    printf( request );
    
	if(connect(sock,(struct sockaddr*)&connectsock,sizeof(struct sockaddr)))
	{
		while(1)
		{
			ret = recv(sock,buff,4096,0);
			printf("ret is %d\n",ret);
		}
	}
	else
	{
		printf("Error..Connect\n");
	}

	return 0;
}
