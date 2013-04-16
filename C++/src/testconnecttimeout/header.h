#ifndef _HEADER_H_
#define _HEADER_H_

    /*********Header Files********/
    //Common Files
    #include <stdio.h>			//printf
    #include <stdlib.h>		    //abort
    #include <string.h>		    //memset
 
    //Exception Files
#ifdef WIN32
    #include <winsock2.h>
#else
    #include <errno.h>
    #include <fcntl.h>
    #include <net/if.h>
    #include <unistd.h>		    //close
    #include <signal.h>		    //signal
    #include <libgen.h>         //parse pathname
    #include <pthread.h>	    //pthread_create 
    #include <sys/time.h>
    #include <sys/ioctl.h>
    #include <arpa/inet.h>		//htonl
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

    /******************/
    //Struct Define
    typedef struct
    {

    }GLOBAL_VAR;

    /******************/
    //Function Prototype(Global function)
#ifdef __cplusplus
    extern "C" 
    {
#endif

//    char * senddata_init(char *ipaddr,unsigned int port);
//    int senddata_loop(char *senddata_hld);
//    void senddata_deinit(char *senddata_hld);

#ifdef __cplusplus
     }
#endif

    //Global variable
    GLOBAL_VAR global_var;

#endif  // _HEADER_H_