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
#include "suspend_java.h"

int main(int argc,char *argv[]){

    struct sockaddr_un address;
    int sockfd;
    int len;
    int i, bytes;
    int result;

    char receive_data;

    if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
            perror ("socket");
            exit (EXIT_FAILURE);
    }

    address.sun_family = AF_UNIX;
    strcpy (address.sun_path, "server_socket");
    len = sizeof (address);

    result = connect (sockfd, (struct sockaddr *)&address, len);
    if (result == -1) {
        printf ("ensure the server is up\n");
        perror ("connect");
        exit (EXIT_FAILURE);
    }

    for (i = 0; i < 5; i++) {
        if ((bytes = write(sockfd, &receive_data, 1)) == -1) {
            perror ("write");
            exit (EXIT_FAILURE);
        }
    }
    
    close (sockfd);

    return 0;
}
