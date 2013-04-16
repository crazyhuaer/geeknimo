#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc,char * argv[])
{
	int socket_fd;
	struct sockaddr_in sock_addr;
	
	socket_fd = socket(AF_INET,SOCK_DGRAM,0);
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sock_addr.sin_port = htons(8000);


	while(1)
	{
		//Send to client
		;
	}
	printf("jjjj");

	return 0;
}
