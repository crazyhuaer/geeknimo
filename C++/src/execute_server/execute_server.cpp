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

int main(int argc, const char *argv[]){

    int     sock_fd;
    struct  sockaddr_in,server_addr,client_addr;

    sock_fd = socket(AF_INET,SOCK_DGRAM,0);
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    
 
    return 0;
}
