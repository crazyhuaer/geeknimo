    
#include "getopt_test.h"


int main(int argc,char * argv[])
{
    //Define the variables
    GLOBAL_VAR * global_var;
    int next_option;
    
    //Initialize variables
    global_var = initialization();
    next_option = 0;

    //Do job!
    ////////////////////////////////////////////////
    do
    {
        next_option = getopt_long(argc,argv,global_var->short_option,global_var->long_options,NULL);
        //printf("next_option:%d\n",next_option);
        switch(next_option)
        {
            case 'h':
                printf("h\n");
                break;
            case 'o':
                printf("o\n");
                break;    
            case 'v':
                printf("v\n");
                break;    
            case '?':
                printf("?\n");
                break;
            case -1:
                //printf("-1\n");
                break;    
            default:
                printf("default\n");
        }

	
    }while(next_option != -1);
        

    ////////////////////////////////////////////////

    //Deinitialize the variables
    deinitialization(global_var);
    pthread_exit(NULL);
    return 0;
}

GLOBAL_VAR * initialization()
{
    
    GLOBAL_VAR * global_var = malloc(sizeof(GLOBAL_VAR));
    struct option long_options[]=\
    {
        {"help",0,NULL,'h'},
        {"output",1,NULL,'o'},
        {"verbose",0,NULL,'v'},
        {NULL,0,NULL,0}
    };

    
    memset(global_var,0,sizeof(GLOBAL_VAR));

    global_var->mutex_id = OS_mutexCreate();
    global_var->sem_id = OS_semCreate(1);
    global_var->msgq_id = OS_msgqCreate(10,4);

    //////////////////////////////
    global_var->short_option = "ho:v";
    global_var->long_options = long_options;
    //////////////////////////////

        
    return global_var;
}

void* pthread_func(void * p_arg)
{

    return NULL;
}


void deinitialization(GLOBAL_VAR * global_var)
{
    free(global_var);
}




