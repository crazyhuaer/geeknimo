
#include <jiekou.h>

int init(int video_size,int video_rate,int video_format)
{   
    //设置大小、格式、帧率三个参数
    if(!write(localsocket,EVENT_SET_OUTPUTSIZE,video_size))return -1;
    if(!write(localsocket,EVENT_SET_RATE,video_rate))return -1;
    if(!write(localsocket,EVENT_SET_OUTPUTFORMAT,video_format))return -1;
    
    return 0;
}

int start_record(int mode)
{
    //连接localsocket
    if(!write(localsocket,EVENT_CONNECT))return -1;

    read_localsocket(char * buff, int len);
    
    if(mode == 1)
    {   
        localwrite(char * pathname,buff,len);
    }
    if(mode == 2)
    {
        httpserver(struct sockaddr_in * p_struct,buff,len);
    }
    return 0;
}

int stop_record()
{
    if(!write(localsocket,EVENT_STOP))return -1;  
    return 0;
}

int localwrite(char * pathname,char * buff,int len)
{
    FILE *stream;
    
    if((stream = fopen(pathname,"r+")) == (FILE *)0)
    {
        PERROR("[FATAL]..fopen");
        return  -1;
    }
    
    int number = fwrite(buff,len,number_of_record,stream);

    if((fclose(strem)) == EOF)
    {
        PERROR("[FATAL..fclose]");
        return -1;
    }

    return 0;
}

int httpserver(struct sockaddr_in * p_struct,char * buff,int len)
{

}

int read_localsocket(char * buff,int len)
{
    if(!read(localsocket,buff,len))return -1; 
    return 0;
}