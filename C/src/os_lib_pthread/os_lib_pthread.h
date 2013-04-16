
#ifndef _OS_LIB_PTHREAD_H_
#define _OS_LIB_PTHREAD_H_
    
    #include "header.h"

    //OS_LIB Header Files
    #include <os_sem.h>
    #include <os_cli.h>
    #include <os_log.h>
    #include <os_msgq.h>
    #include <os_mutex.h>
    #include <os_thread.h>
    #include <os_global.h>
    

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
   
    /******************/
    //Struct Define
    typedef struct
    {
        int count;
    }Animal;
    
    typedef struct
    {
        int while_flag;
        char * mutex_id;
        char * sem_id;  
        char * msgq_id;
        Animal anmial_id[3];
    }OS_LIB_PTHREAD_VAR;

    /******************/
    //Function Prototype
    #ifdef __cplusplus
        extern "C" 
        {
    #endif

    OS_LIB_PTHREAD_VAR * initialization();

    void * pthread_func(void *);

    void cli_printf(int id);
    
    void deinitialization(OS_LIB_PTHREAD_VAR * init_hld);

    #ifdef __cplusplus
        }
    #endif

    //application var
    //OS_LIB_PTHREAD_VAR * os_lib_pthread_var;

#endif // _OS_LIB_PTHREAD_H_