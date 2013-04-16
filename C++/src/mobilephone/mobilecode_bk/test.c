    /*********Header Files********/
    //Common Files
    #include <stdio.h>			//printf
    #include <stdlib.h>		    //abort
    #include <string.h>		    //memset
    #include <selectmode.h>
    #include <ScreenRecorder_client.h>
    
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


int main(int argc,char * argv[])
{
    int ret;
    int port;
    int mode;
    char * path = "/var/myfile";

    ret = 0;
    mode = 1;
    port = 8080;
    ret = init_localsocket();
    if(ret < 0)
        PERROR("[FATAL]..init localsocket error!");

    ret = init_rate(20);
    if(ret < 0)
        PERROR("[FATAL]..init rate error!");

    ret = init_size(800,600);
    if(ret < 0)
        PERROR("[FATAL]..init size error!");

    ret = init_format(4);
    if(ret < 0)
        PERROR("[FATAL]..init format error!"); 

    ret = start_record();
    if(ret < 0)
        PERROR("[FATAL]..start_record error!");

    if(mode == 0)
    {
        ret = localwrite(path);
        if(ret < 0)
            PERROR("[FATAL]..localwrite error!");
    }

    if(mode == 1)
    {
        ret = httpserver(port);
        if(ret < 0)
            PERROR("[FATAL]..httpserver error!");
    }
    
    ret = stop_record();
    if(ret < 0)
        PERROR("[FATAL]..stop_record error!");

    ret = deinit_localsocket();
    if(ret < 0)
        PERROR("[FATAL]..deinit_localsocket error!");

    return 0;
}
