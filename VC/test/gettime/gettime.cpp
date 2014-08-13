// gettime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <Winsock2.h>

#ifdef   WIN32   
#define   LOCALTIME_R(t)     localtime((t))   
#else   
#define   LOCALTIME_R(t)     localtime_r((t),   (struct   tm   *)&tmres)   
#endif   

#define bzero(a, b) memset(a, 0, b)

#define REMOTE_IP "192.168.1.104" 
#define REMOTE_PORT 8888
#define MAX_SIZE 43

int  fd_sock;
char buf[MAX_SIZE];
struct tm l_time;

void local_time(char* buf,char* ip)
{
	struct   tm   *st_tm;   
	time_t   long_time;   
	time(&long_time   );                             /*   Get   time   as   long   integer.   */   
	st_tm   =   LOCALTIME_R(   &long_time   );   /*   Convert   to   local   time.   */   

	sprintf(buf,"%s:%d-%d-%d %d:%d:%d.%ld\n",
		ip,
		st_tm->tm_year + 1900,
		st_tm->tm_mon + 1,
		st_tm->tm_mday,
		st_tm->tm_hour,
		st_tm->tm_min,
		st_tm->tm_sec);
}

int main(int argc, char* argv[])
{
	int err;
	WSADATA wsaData;
	WORD wVersionRequested;
	PHOSTENT hostinfo;
	char *ip;
	char name[255];
	char *serverIp;

	serverIp = (char *)malloc(16*sizeof(char));

	printf("Please input the server IP address(example:192.168.1.104):\n");
	scanf("%s",serverIp);
	

	wVersionRequested = MAKEWORD( 1, 1 );

	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		return 0;
	}

	if ( LOBYTE( wsaData.wVersion ) != 1 ||
		HIBYTE( wsaData.wVersion ) != 1 ) {
		WSACleanup( );
		return 0;
	}

	if( gethostname ( name, sizeof(name)) == 0)
	{
		if((hostinfo = gethostbyname(name)) != NULL)
		{
			ip = inet_ntoa (*(struct in_addr *)*hostinfo->h_addr_list);
		}
    }

	//printf("ip:%s,sizeof(ip):%d\n",ip,sizeof(ip));

	SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=inet_addr("192.168.1.104");
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(REMOTE_PORT);
	connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));

	int  retByte = 0;

	do 
	{
		bzero(buf, MAX_SIZE);
		local_time(buf,ip);
		printf("%s,sizeof(buf):%d\n",buf,sizeof(buf));
		retByte = sendto(sockClient, buf, MAX_SIZE, 0, (struct sockaddr*) &addrSrv,sizeof(addrSrv));
		printf("retByte:%d\n",retByte);
		Sleep(1000);
	} while (retByte > 0);
			
		//recv(sockClient,recvBuf,50,0);
		//printf("%s\n",recvBuf);

	closesocket(sockClient);
	WSACleanup();
	return 0;
}

