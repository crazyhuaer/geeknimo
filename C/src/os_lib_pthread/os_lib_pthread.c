
#include "os_lib_pthread.h"

#define TEST_SOURCE_NUM 7
#define SERVER_PORT 3938

OS_LIB_PTHREAD_VAR * os_lib_pthread_var;

int main(int argc,char * argv[])
{
    int ret;
    
    os_lib_pthread_var = initialization();
    
    //Model
    /*======= Test  =======*/
    #if (TEST_SOURCE_NUM == 0) 

    #endif
    /*======= End Test  =======*/
    
    /*======= Test pthread =======*/
    #if (TEST_SOURCE_NUM == 1) 
        pthread_t pthread_pid;
        pthread_attr_t attr;

        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

        pthread_create(&pthread_pid,&attr,&pthread_func,NULL);
        //pthread_create(&pthread_pid,NULL,(void *)&pthread_func,NULL);

        pthread_attr_destroy(&attr);
        printf("Game Over!\n");
    #endif
    /*======= End Test pthread =======*/
    

    /*======= Test OS_thread_create =======*/
    #if (TEST_SOURCE_NUM == 2)
        OS_LIB_PTHREAD_VAR * os_lib_pthread_var;
        os_lib_pthread_var = initialization();
        printf("while_flag before:%d\n",os_lib_pthread_var->while_flag);
        
        ret = OS_thread_create((OS_THREAD_FUNC)pthread_func,(void *)os_lib_pthread_var);
        printf("while_flag after:%d\n",os_lib_pthread_var->while_flag);

        //while(!os_lib_pthread_var->while_flag);
        //printf("while_flag over:%d\n",os_lib_pthread_var->while_flag);
    #endif
    /*======= End Test OS_thread_create =======*/

    /*======= Test Mutex =======*/
    #if (TEST_SOURCE_NUM == 3) 
        OS_LIB_PTHREAD_VAR * os_lib_pthread_var;

        os_lib_pthread_var = initialization();
  
        printf("while_flag before:%d\n",os_lib_pthread_var->while_flag);
        
        ret = OS_thread_create((OS_THREAD_FUNC)pthread_func,(void *)os_lib_pthread_var);
        //printf("while_flag after:%d\n",os_lib_pthread_var->while_flag);
         
        while(1)
        {
            ret = OS_semTake(os_lib_pthread_var->sem_id);
            ret = OS_mutexTake(os_lib_pthread_var->mutex_id);
            printf("while_flag main:%d\n",os_lib_pthread_var->while_flag++);
            
            if((os_lib_pthread_var->while_flag == 20) || (os_lib_pthread_var->while_flag == -20))
            {
                ret = OS_mutexGive(os_lib_pthread_var->mutex_id);
                break;
            }
            ret = OS_mutexGive(os_lib_pthread_var->mutex_id);
            ret = OS_semGive(os_lib_pthread_var->sem_id);
            SLEEP(200);
        }
        
        ret = OS_mutexDelete(os_lib_pthread_var->mutex_id);
    #endif
    /*======= End Test Mutex =======*/

    /*======= Test  =======*/
    #if (TEST_SOURCE_NUM == 4) 
  
        printf("while_flag before:%d\n",os_lib_pthread_var->while_flag);
        
        ret = OS_thread_create((OS_THREAD_FUNC)pthread_func,(void *)os_lib_pthread_var);
        //printf("while_flag after:%d\n",os_lib_pthread_var->while_flag);
         
        while(1)
        {
            ret = OS_semTake(os_lib_pthread_var->sem_id,3000);
            ret = OS_mutexTake(os_lib_pthread_var->mutex_id);
            printf("while_flag main:%d\n",os_lib_pthread_var->while_flag++);
            
            if((os_lib_pthread_var->while_flag == 20) || (os_lib_pthread_var->while_flag == -20))
            {
                ret = OS_mutexGive(os_lib_pthread_var->mutex_id);
                break;
            }
            ret = OS_mutexGive(os_lib_pthread_var->mutex_id);
            ret = OS_semGive(os_lib_pthread_var->sem_id);
            SLEEP(200);
        }
        deinitialization(os_lib_pthread_var);
        ret = OS_mutexDelete(os_lib_pthread_var->mutex_id);
        ret = OS_semDelete(os_lib_pthread_var->sem_id);
    #endif
    /*======= End Test  =======*/

    /*======= Test msgq =======*/
    #if (TEST_SOURCE_NUM == 5)
        int msg;
        //ret = OS_msgqShow(os_lib_pthread_var->msgq_id);
        
        ret = OS_thread_create((OS_THREAD_FUNC)pthread_func,(void *)os_lib_pthread_var);

        msg = 5;
        
        printf("================\n");
       
        while(1)
        {
            SLEEP(400);
            
            //printf("====%d====\n",OS_msgqGetMsgCnt(os_lib_pthread_var->msgq_id));
            //ret = OS_msgqShow(os_lib_pthread_var->msgq_id);
            ret = OS_msgqRecv(os_lib_pthread_var->msgq_id,&msg);   
            printf("Recv msg is %d\n",*((int *)&msg));
            //ret = OS_msgqShow(os_lib_pthread_var->msgq_id);
    
            //OS_log(LVL_FATAL, 0,"hello");    
        }
        
        ret = OS_msgqDelete(os_lib_pthread_var->msgq_id);
    #endif
    /*======= End Test msgq =======*/

    

    /*======= Test OS_log =======*/
    #if (TEST_SOURCE_NUM == 6) 
        ret = 1;
        
        OS_log(LVL_WRN,0,"[Warning]...");
        OS_log(LVL_TRACE,0,"[Trace]........");

        ret = OS_logGetMask(0);

        printf("main Level is:%d\n",ret);
        
        //OS_logStatus();
        //OS_logHelp();
        
    #endif
    /*======= End Test OS_log =======*/

    /*======= Test OS_log and OS_cli =======*/
    #if (TEST_SOURCE_NUM == 7) 
        ret = 1;

        //OS_log(LVL_INFO,0,"[Information]...");
        //OS_log(LVL_WRN,0,"[Warning]...");
        //OS_log(LVL_ERR,0,"[Error]..."); 
        //OS_log(LVL_FATAL,0,"[Fatal]...");

        ret = OS_thread_create((OS_THREAD_FUNC)pthread_func,(void *)os_lib_pthread_var);

        while(1)
        {
            OS_log(LVL_TRACE,0,"[Trace]Program Start....");
            SLEEP(1000);
        }

    #endif
    /*======= End Test OS_log and OS_cli =======*/
    
    deinitialization(os_lib_pthread_var);
    pthread_exit(NULL);
    return 0;
}

OS_LIB_PTHREAD_VAR * initialization()
{
    int ret;
    OS_LIB_PTHREAD_VAR * os_lib_pthread_var = malloc(sizeof(OS_LIB_PTHREAD_VAR));
    memset(os_lib_pthread_var,0,sizeof(OS_LIB_PTHREAD_VAR));


    os_lib_pthread_var->while_flag = 0;
    os_lib_pthread_var->mutex_id = OS_mutexCreate();
    os_lib_pthread_var->sem_id = OS_semCreate(1);
    os_lib_pthread_var->msgq_id = OS_msgqCreate(10,4);

    (os_lib_pthread_var->anmial_id)[0].count = 1;
    (os_lib_pthread_var->anmial_id)[1].count = 15;
    (os_lib_pthread_var->anmial_id)[2].count = 27;

    OS_logInit(NULL, "log.txt", 0);   
  
    ret = OS_logModReg(0,"main");
    ret = OS_logSetMask(0,0x1f);

    ret = OS_cliInit(3938);
    ret = OS_regSym("print_var",0,0,cli_printf);
    
    return os_lib_pthread_var;
}

void* pthread_func(void * p_arg)
{
    int ret;
    
    while(1)
    {
        /*======= Test pthread_Create =======*/
        #if (TEST_SOURCE_NUM == 1) 
            int i;
            
            for (i = 0;i<50;i++)
            {
                printf("%d ",i);
                fflush(stdout);
            }
            printf("\n");
        #endif
        /*======= End Test pthread_Create =======*/

        /*======= Test Mutex =======*/
        #if (TEST_SOURCE_NUM == 3)
            ret = OS_mutexTake(((OS_LIB_PTHREAD_VAR *)p_arg)->mutex_id);
            //((OS_LIB_PTHREAD_VAR *)p_arg)->while_flag = 50;
            printf("while_flag mutex:%d\n",((OS_LIB_PTHREAD_VAR *)p_arg)->while_flag--);

            if(((OS_LIB_PTHREAD_VAR *)p_arg)->while_flag < -5)
            {
                ret = OS_mutexGive(((OS_LIB_PTHREAD_VAR *)p_arg)->mutex_id);
                break;
            }
            
            ret = OS_mutexGive(((OS_LIB_PTHREAD_VAR *)p_arg)->mutex_id);

            SLEEP(400);
        #endif 
        /*======= End Test Mutex =======*/

        /*======= Test Sem =======*/
        #if (TEST_SOURCE_NUM == 4) 
            ret = OS_semGive(((OS_LIB_PTHREAD_VAR *)p_arg)->sem_id);
            ret = OS_semTake(((OS_LIB_PTHREAD_VAR *)p_arg)->sem_id,1500);
            ret = OS_mutexTake(((OS_LIB_PTHREAD_VAR *)p_arg)->mutex_id);
 
            printf("while_flag sem:%d\n",((OS_LIB_PTHREAD_VAR *)p_arg)->while_flag--);

            if(((OS_LIB_PTHREAD_VAR *)p_arg)->while_flag < -5)
            {
                ret = OS_mutexGive(((OS_LIB_PTHREAD_VAR *)p_arg)->mutex_id);
                break;
            }

            SLEEP(400);
            ret = OS_mutexGive(((OS_LIB_PTHREAD_VAR *)p_arg)->mutex_id);
        #endif
        /*======= End Test Sem  =======*/

        /*======= Test msgq =======*/
        #if (TEST_SOURCE_NUM == 5) 
            int msg = 50;
            while(1)
            {
                SLEEP(1);
                //ret = OS_msgqShow(((OS_LIB_PTHREAD_VAR *)p_arg)->msgq_id);
                //printf("====%d====\n",OS_msgqGetMsgCnt(((OS_LIB_PTHREAD_VAR *)p_arg)->msgq_id));
                ret = OS_msgqSend(((OS_LIB_PTHREAD_VAR *)p_arg)->msgq_id,(void *)&msg);
                //OS_log(LVL_TRACE, 0,"hello"); 
                //printf("msg is %d\n",(int)msg);
            }
        #endif
        /*======= End Test msgq =======*/

        /*======= Test  =======*/
        #if (TEST_SOURCE_NUM == 6) 
            ret = 1;
        #endif
        /*======= End Test  =======*/

        /*======= Test  =======*/
        #if (TEST_SOURCE_NUM == 7) 
            int while_flag = ((OS_LIB_PTHREAD_VAR *)p_arg)->while_flag;

            while(1)
            {
                ret = OS_mutexTake(((OS_LIB_PTHREAD_VAR *)p_arg)->mutex_id);
                
                (((OS_LIB_PTHREAD_VAR *)p_arg)->anmial_id)[while_flag].count++;
                (((OS_LIB_PTHREAD_VAR *)p_arg)->while_flag)++;
                
                if(((OS_LIB_PTHREAD_VAR *)p_arg)->while_flag == 3)
                {
                    ((OS_LIB_PTHREAD_VAR *)p_arg)->while_flag = 0;
                }
                
                while_flag = ((OS_LIB_PTHREAD_VAR *)p_arg)->while_flag;
                ret = OS_mutexGive(((OS_LIB_PTHREAD_VAR *)p_arg)->mutex_id);
                SLEEP(400);
            }
        #endif
        /*======= End Test  =======*/
    }
    return NULL;
}

void cli_printf(int id)
{
    printf("%d\n",(os_lib_pthread_var->anmial_id)[id].count);
}

void deinitialization(OS_LIB_PTHREAD_VAR * os_lib_pthread_var)
{
    free(os_lib_pthread_var);
    OS_logDeInit();
}

