#ifndef _OS_RBUF_H
#define _OS_RBUF_H

#include "queue.h"

struct rbuf_body;

CIRCLEQ_HEAD(h_use_link, rbuf_body);

struct rbuf_header
{
	unsigned int initFlag; //mark a valid rbuf_ID
	int total_size;	//rbuf's total size
	int align_size; //rbuf's align size

	int malloc_block_size;
	
	int after_end_size;
	int before_first_size;
	
	char * mutexId;
	char * sem;
	
	struct h_use_link use_link_head;

	char *last_malloc_start;
	char *last_malloc_data;
	char *last_malloc_end; //the last malloc's end pointer
	char *rf_real; //pointed to the address of the real malloc
	char *rf_align; //pointer of after align rf 
	char *rf_last;	//pointer of end of rf
};

struct rbuf_body
{
	unsigned int body_initFlag;
	CIRCLEQ_ENTRY(rbuf_body) body_link;

	int data_size;
};

typedef struct rbuf_body	RBUF_BODY;
typedef struct rbuf_header RBUF_HEADER;

#define RBUFF_INIT_FLAG 0x00A59375   /* "MQI" */
#define RBUFF_MIN_SIZE (64 * 1024)
#define RBUFF_MAX_ALIGNSIZE (4 * 1024)
#define RBUFF_ALIGN_SIZE 16

#ifdef __cplusplus
extern "C" {
#endif

char * OS_rbuf_create(int size,int align_size);

int OS_calculate_free_size(char * rbuf_id, int *size_after_end, int *size_before_first);

char * OS_rbuf_alloc(char * rbuf_id, int size);
char * OS_rbuf_pend_alloc(char * rbuf_id,int size);

int OS_rbuf_last_resize(char * rbuf_id, char *p,int new_size);

int OS_rbuf_free(char * rbuf_id,char *p);
int OS_rbuf_free_head(char * rbuf_id);
int OS_rbuf_free_last(char * rbuf_id);

char * OS_rbuf_get_head(char * rbuf_id, int *allocate_size);
char * OS_rbuf_get_last(char * rbuf_id, int *allocate_size);

int OS_rbuf_show(char * rbuf_id);

int OS_rbuf_delete(char * rbuf_id);

#ifdef __cplusplus
}
#endif

#endif //_OS_RBUF_H

