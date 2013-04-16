#ifndef _OS_MSGQ_H
#define  _OS_MSGQ_H

#include "queue.h"
//#include <pthread.h>
#ifdef __cplusplus
extern "C" {
#endif

struct msgq_body;

TAILQ_HEAD(h_free_link, msgq_body);   //head of free link is out of the dev_data[MAX_DEV_DATA]
TAILQ_HEAD(h_used_link, msgq_body);

struct msgq_header
{
	unsigned int initFlag;	//初始化标记, 当delete msgq的时候设置为0
	int max_count;	//max number of block
//	int cur_count;	//current number of block
	int size;	//size of each block
	int free_count;
	char * mutexId;
	char * full_sem;
	char * empty_sem;
	struct h_free_link free_link_head;	//head of free link is out of the dev_data[20]
	struct h_used_link used_link_head;
	int send_block_count;
	int recv_block_count;
	struct msgq_body *p_msgq_body;
};

//struct msgq_header *msq_id;

struct msgq_body
{
	TAILQ_ENTRY(msgq_body) body_link;	//双向链表
	char *pbuf;
};

typedef struct msgq_body	MSGQ_BODY;
typedef struct msgq_header MSGQ_HEADER;

#define MSG_Q_INIT_FLAG 0x00A59375   /* "MQI" */
#define DEFAULT_ALIGN_MODEL 4

#define OS_msgqPush			OS_msgqSend_head_nonblock
#define OS_msgqPop			OS_msgqRecv_nonblock

char * OS_msgqCreate(int count,int size);
int OS_msgqDelete(char * msgq_id);

int OS_msgqSend(char * msgq_id,void *p_msg);
int OS_msgqSend_nonblock(char * msgq_id,void *p_msg);

int OS_msgqSend_head(char * msgq_id,void *p_msg);
int OS_msgqSend_head_nonblock(char * msgq_id,void *p_msg);

int OS_msgqRecv(char * msgq_id,void *p_msg);
int OS_msgqRecv_nonblock(char * msgq_id,void *p_msg);

int OS_msgqPeek(char * msgq_id,void *p_msg);
int OS_msgqShow(char * msgq_id);

int OS_msgqPush(char * msgq_id,void *p_msg);
int OS_msgqPop(char * msgq_id,void *p_msg);

int OS_msgqGetMsgCnt(char *msgq_id);

#ifdef __cplusplus
}
#endif

#endif //_OS_MSGQ_H

