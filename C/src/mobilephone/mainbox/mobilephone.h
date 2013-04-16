
#ifndef _MOBILEPHONE_H_
#define _MOBILEPHONE_H_
    
    #include "header.h"

    //OS_LIB Header Files
    #include <os_sem.h>
    #include <os_cli.h>
    #include <os_log.h>
    #include <os_msgq.h>
    #include <os_mutex.h>
    #include <os_thread.h>
    #include <os_global.h>
    
    //mobilephone include 
    #include <sys/select.h>

    /*
    #include <queue.h>
    #include <os_cli.h>
    #include <os_log.h>
    #include <os_sem.h>
    #include <os_shm.h>
    #include <os_msgq.h>
    #include <os_rbuf.h>
    #include <os_mutex.h>
    #include <os_utils.h>
    #include <os_vmsgq.h>
    #include <os_global.h>
    #include <os_thread.h>
    */

    #define MAX_CONNECT 10
    #define TPC_SERVER_PORT 3939
    
    /******************/
    //Struct Define 
    enum
    {
        CLIENT_CONNECT_IDLE,
        CLIENT_CONNECT_BUSY
    };
    
    typedef struct 
    {
        struct sockaddr_in servaddr;
        int port;
        int connect_count;
        int listen_fd;
    }TCP_SERVER;
    
    typedef struct
    {
        char *addr;
        int port;
        int state;
        int index;
        int accept_fd;
    }TCP_CLIENT;
    
    typedef struct
    {
        char * mutex_id;
        char * sem_id;  
        char * msgq_id;

        int g_exit_flag;
        fd_set read_fds;
        TCP_SERVER tcp_server;
        TCP_CLIENT tcp_client[MAX_CONNECT];
        
    }MOBILEPHONE_VAR;

    /******************/
    //Function Prototype
    #ifdef __cplusplus
        extern "C" 
        {
    #endif

    MOBILEPHONE_VAR * initialization();

    void * pthread_func(void *p_arg);
    int get_idle_client();
    void build_select_list(int *highsock);
    
    void deinitialization(MOBILEPHONE_VAR * init_hld);

    #ifdef __cplusplus
        }
    #endif

#endif // _MOBILEPHONE_H_