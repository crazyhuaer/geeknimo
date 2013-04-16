
#include "selectmode.h"

void *listenThreadFunc(void *para)
{
	PTHREAD_PARA_S *data = (PTHREAD_PARA_S *)para;
	//LOGWYJ("listenThreadFunc: confd=%d,cmdfd=%d ", data->connFd, data->cmdFd);

	screenrecorder_deinit(data->connFd, data->cmdFd);
	
	free(para);
	return NULL;
}

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
