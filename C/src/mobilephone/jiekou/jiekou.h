#ifndef _JIEKOU_H_
#define _JIEKOU_H_

    /*********Header Files********/
    //Common Files
    #include <stdio.h>			//printf
    #include <stdlib.h>		    //abort
    #include <string.h>		    //memset
 
    //Exception Files
#ifdef WIN32
    #include <winsock2.h>
#else
    #include <time.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <net/if.h>
    #include <unistd.h>		    //close
    #include <signal.h>		    //signal
    #include <libgen.h>         //parse pathname
    #include <pthread.h>	    //pthread_create   
    #include <sys/ioctl.h>
    #include <arpa/inet.h>		//htonl
    #include <sys/types.h>
    #include <sys/socket.h>	    //socket
    #include <netinet/tcp.h>	//SOL_TCP
#endif  /* #ifdef WIN32*/

    /*********Macro Define*********/
    //Common Define
    #define  DEBUG_STATUS       1

    //Exception Define
#ifdef WIN32
    #define socklen_t		int
    #define SLEEP(x)		Sleep(x)
    #define CLOSESOCKET		closesocket
    #define PERROR(x)		printf("%s%d",x,WSAGetLastError())
#else
    #define CLOSESOCKET		    close
    #define SLEEP(x)	          usleep(1000*x)
    #define PERROR(x)	          perror(x)
#endif    /* #ifdef WIN32 */



    //Function Prototype(Global function)
#ifdef __cplusplus
    extern "C" 
    {
#endif

    int init(int video_size,int video_rate,int video_format);

    int start_record(int mode);

    int stop_record();

    int localwrite(char * pathname);
    int httpserver(struct sockaddr_in * p_struct);

    int read_localsocket(char * buff,int len);

#ifdef __cplusplus
     }
#endif


#endif  // _JIEKOU_H_