//ScreenRecorderInterface.h


/*
 *	Code copyright by wangyunjin 
 *	Date@20120906
 *    The ScreenRecorderInterface is for the interaction 
 *      between ScreenRecorder_client with ScreenRecorder_server process 
 *
 */

#define LOCAL_SOCKET_CONNECT_NAME "screen_enc_connect_sock"
#define LOCAL_SOCKET_COMMAND_NAME "screen_enc_command_sock"

#define CONNECTION_MSG_STRING  "screenrecorder_connection"
#define DISCONNECTION_MSG_STRING  "screenrecorder_disconnection"

enum event
{
	EVENT_CONNECT,
	EVENT_SET_RATE,
	EVENT_SET_OUTPUTFORMAT,
	EVENT_SET_OUTPUTSIZE,
	EVENT_START,
	EVENT_STOP,
	EVENT_DISCONNECT,
	
	EVENT_NB,
};

typedef struct
{
	enum event evt;
	int ext1;
	int ext2;
	uint8_t ext3[32];
}SR_EVENT_S;

