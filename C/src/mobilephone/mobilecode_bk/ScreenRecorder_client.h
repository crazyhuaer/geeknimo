//ScreenRecorder_client.h
/*
 *	Code copyright by wangyunjin 
 *	Date@20120906
 *     The ScreenRecorder_client Interface for interaction
 *	 with ScreenRecorder_server process
 *
 *   整个应用分为三部分：1. 编码进程（系统进程）2. 应用层的httpserver 3. 应用层的UI
 *   应用层进程和编码进程的通信过程以及编码结果的获取都通过一个localsocket完成。
 *		1> localsocket在编码进程中创建，连接通讯接口与编码进程对接
 *		2> httpserver 目前作为一个线程存在于应用进程中，也就说编码过程当中应用必须一直运行。（未来要做一个后台服务用于httpserver）
 *		3> 编码进程的启动时机：init启动（系统启动）； 应用启动
*/

typedef enum {
    OUTPUT_FORMAT_DEFAULT = 0,
    OUTPUT_FORMAT_THREE_GPP = 1,
    OUTPUT_FORMAT_MPEG_4 = 2,
    /* H.264/AAC data encapsulated in MPEG2/TS */
    OUTPUT_FORMAT_MPEG2TS = 8,

    OUTPUT_FORMAT_LIST_END // must be last - used to validate format type

}output_format_e;

typedef   void (*LISTENFUNC)(void *);

/*连接编码进程的localsocket（EVENT_CONNECT），初始化变量*/
int screenrecorder_init(int *connSockFd,int *cmdSockFd);

/*设置编码帧率（通过向localsocket发送 EVENT_SET_RATE）*/
int screenrecorder_set_rate(int cmdSockFd, int fps);

/*设置编码帧率（通过向localsocket发送 EVENT_SET_OUTPUTFORMAT)*/
int screenrecorder_set_format(int cmdSockFd, output_format_e format);

/*设置编码帧率（通过向localsocket发送 EVENT_SET_OUTPUTSIZE)*/
int screenrecorder_set_size(int cmdSockFd, int width, int height);

/*开始录制屏幕视频，（EVENT_START）*/
int screenrecorder_start(int cmdSockFd, int connSockFd,  LISTENFUNC func, void *data);

/*结束录制屏幕视频，（EVENT_STOP）*/
int screenrecorder_stop(int cmdSockFd);

/*断开localsocket连接，去初始化*/
int screenrecorder_deinit(int connSockFd, int cmdSockFd);
