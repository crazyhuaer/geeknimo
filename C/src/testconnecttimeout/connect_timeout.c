
#include "connect_timeout.h"

#define SERVER_ADDR					"192.111.0.194"
#define SERVER_PORT					5555

int main(int argc,char * argv[])
{
    struct timeval start_time,end_time;
    int sec,usec;
    int tcp_sock,ret,value;
    struct sockaddr_in addr, dest;


    sec = 0;
    usec = 0;

    tcp_sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    value = 1;
    ret = setsockopt(tcp_sock,SOL_SOCKET,SO_REUSEADDR,(const char *)&value,sizeof(int));
    if(ret < 0)
    {
        printf("[FATAL] setsockopt SO_REUSERADDR %d:%s\n",errno,strerror(errno));
        CLOSESOCKET(tcp_sock);
        exit(-1);
    }
    else
    {
        value = 5*1024;         
        ret = setsockopt(tcp_sock,SOL_SOCKET,SO_RCVBUF,&value,sizeof(value));

        if(ret < 0)
        {
            printf("[FATAL] setsockopt SOCK_RCVBUF %d:%s\n",errno,strerror(errno));
            CLOSESOCKET(tcp_sock);
            exit(-1);
        }
        else
        {
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = htonl(INADDR_ANY);
            addr.sin_port = htons(5555);

            ret = bind(tcp_sock,(struct sockaddr *)&addr,sizeof(struct sockaddr_in));
            if(ret < 0)
            {
                printf("[FATAL] bind %d:%s\n",errno,strerror(errno));
                CLOSESOCKET(tcp_sock);
                exit(-1);
            }
            else
            {
                dest.sin_family = AF_INET;
                dest.sin_addr.s_addr = inet_addr(SERVER_ADDR);
                dest.sin_port = htons(SERVER_PORT);

                gettimeofday(&start_time,NULL);
                ret = connect(tcp_sock,(struct sockaddr *)&dest,sizeof(struct sockaddr_in));
                gettimeofday(&end_time,NULL);
                if(ret < 0)
                {
                    printf("[FATAL] connect %d:%s\n",errno,strerror(errno));
                    CLOSESOCKET(tcp_sock);    
                }
                else
                {
                    printf("connect success.\n");
                }

                sec = end_time.tv_sec - start_time.tv_sec;
                usec = end_time.tv_usec - start_time.tv_usec;

                printf("connect consume time:==sec:%d,usec:%d==\n",sec,usec);
                
            }
        }
        
    }

    return 0;
}
