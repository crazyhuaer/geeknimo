
#ifndef _CONNECT_TIMEOUT_H_
#define _CONNECT_TIMEOUT_H_
    
    #include "header.h"

    //OS_LIB Header Files
    #include <queue.h>
    #include <os_global.h>
    #include <os_thread.h>

    
    /******************/
    //Struct Define
    typedef struct
    {
        
    }CONNECT_TIMEOUT_VAR;

    /******************/
    //Function Prototype
    #ifdef __cplusplus
        extern "C" 
        {
    #endif

    CONNECT_TIMEOUT_VAR * initialization();

    void pthread_func(void *);
    
    void deinitialization(CONNECT_TIMEOUT_VAR * connect_timeout_var);

    #ifdef __cplusplus
        }
    #endif

    //application var
    CONNECT_TIMEOUT_VAR * connect_timeout_var;


#endif  //_CONNECT_TIMEOUT_H_

