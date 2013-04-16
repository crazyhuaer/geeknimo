    
#include "acmcode.h"

#define CODE_NUM_OF_ACM 1001

int main(int argc,char * argv[])
{
    //Define the variables
    GLOBAL_VAR * global_var;
  
    //Initialize variables
    global_var = initialization();

    //Do job!
    ////////////////////////////////////////////////
    #if (CODE_NUM_OF_ACM==1001)
    {
        int a,b;  
        while(scanf("%d %d",&a,&b)!=EOF)
            printf("%d\n",a+b);
    }

    #endif
    ////////////////////////////////////////////////

    //Deinitialize the variables
    deinitialization(global_var);
    pthread_exit(NULL);
    return 0;
}

GLOBAL_VAR * initialization()
{
    
    GLOBAL_VAR * global_var = malloc(sizeof(GLOBAL_VAR));
  
    memset(global_var,0,sizeof(GLOBAL_VAR));

    //////////////////////////////

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




