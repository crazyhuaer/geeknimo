/*************************************************************************
***
*** File name  : os_thread.h
***
*** Module     : common thread create
***
*** Version    : 1.0
***
*** Created On :  6/9/2011
***
*** Description:
 ***            This header file definitions for common thread functions used in win32 and linux
***
*** Modification histroy:
***
**************************************************************************/



#ifndef __OS_THREAD_H_
#define __OS_THREAD_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void * (*OS_THREAD_FUNC)(void *);

int OS_thread_create(OS_THREAD_FUNC p_func, void *arg);


#ifdef __cplusplus
}
#endif

#endif /* __OS_THREAD_H_ */

