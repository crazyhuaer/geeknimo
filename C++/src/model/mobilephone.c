
#include "mobilephone.h"

#define TEST_SOURCE_NUM 1

int main(int argc,char * argv[])
{
    //define the variables
    int ret;
    MOBILEPHONE_VAR * mobilephone_var;
    
    //initialize variables
    ret = 1;
    mobilephone_var = initialization();
    
    //Model
    /*======= Test  =======*/
    #if (TEST_SOURCE_NUM == 0) 

    #endif
    /*======= End Test  =======*/ 

    /*======= Test Mobile =======*/
    #if (TEST_SOURCE_NUM == 1) 
    
    #endif
    /*======= End Test Mobile =======*/ 

    //deinitialize the variables
    deinitialization(mobilephone_var);
    pthread_exit(NULL);
    return 0;
}

MOBILEPHONE_VAR * initialization()
{
    MOBILEPHONE_VAR * mobilephone_var = malloc(sizeof(MOBILEPHONE_VAR));
    memset(mobilephone_var,0,sizeof(MOBILEPHONE_VAR));

    mobilephone_var->mutex_id = OS_mutexCreate();
    mobilephone_var->sem_id = OS_semCreate(1);
    mobilephone_var->msgq_id = OS_msgqCreate(10,4);

    return mobilephone_var;
}

void* pthread_func(void * p_arg)
{
    int ret;
    ret = 1;
    return NULL;
}

void deinitialization(MOBILEPHONE_VAR * mobilephone_var)
{
    free(mobilephone_var);
}



