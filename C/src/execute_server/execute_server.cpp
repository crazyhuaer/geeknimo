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

#define MAX_LENGTHS (4096*10)
#define SERVER_PORT 5588

int main(int argc, const char *argv[]){

    // init the socket
    int           sock_fd;
    struct        sockaddr_in server_addr,client_addr;

    int           return_status;
    int           receive_data_length;
    socklen_t     sockaddr_len;

    // set the socket
    sock_fd = socket(AF_INET,SOCK_DGRAM,0);
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    server_addr.sin_port = htons(SERVER_PORT);

    sockaddr_len = sizeof(server_addr);

    // build the socket
    return_status = bind(sock_fd,(struct sockaddr *)&server_addr,sockaddr_len);
    if(return_status == -1){
        printf("bind error,%d\n",errno);
        exit(1);
    }else{

        char message[MAX_LENGTHS];

        // do job
        while(1){
            receive_data_length = recvfrom(sock_fd,message,MAX_LENGTHS,0,(sockaddr *)&client_addr,&sockaddr_len);

            if(receive_data_length < 0){
                continue;
            }else{
                // revieve the command,do that.
                printf("%s\n",message);
            }
        }
    }
    
    return 0;
}
