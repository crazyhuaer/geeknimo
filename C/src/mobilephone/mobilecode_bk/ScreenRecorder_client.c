
#include "ScreenRecorder_client.h"

/*连接编码进程的localsocket（EVENT_CONNECT），初始化变量*/
int screenrecorder_init(int *connSockFd,int *cmdSockFd)
{

	return 0;
}

/*设置编码帧率（通过向localsocket发送 EVENT_SET_RATE）*/
int screenrecorder_set_rate(int cmdSockFd, int fps)
{

	return 0;
}

/*设置编码帧率（通过向localsocket发送 EVENT_SET_OUTPUTFORMAT)*/
int screenrecorder_set_format(int cmdSockFd, output_format_e format)
{

	return 0;
}

/*设置编码帧率（通过向localsocket发送 EVENT_SET_OUTPUTSIZE)*/
int screenrecorder_set_size(int cmdSockFd, int width, int height)
{

	return 0;
}

/*开始录制屏幕视频，（EVENT_START）*/
int screenrecorder_start(int cmdSockFd, int connSockFd,  LISTENFUNC func, void *data)
{

	return 0;
}

/*结束录制屏幕视频，（EVENT_STOP）*/
int screenrecorder_stop(int cmdSockFd)
{

	return 0;
}

/*断开localsocket连接，去初始化*/
int screenrecorder_deinit(int connSockFd, int cmdSockFd)
{

	return 0;
}