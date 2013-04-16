#ifndef _OS_GLOBAL_H
#define _OS_GLOBAL_H

#ifdef WIN32
#pragma warning(disable : 4996)
#endif
	/*define wait forever constant for mutex/semaphore*/
#ifndef OS_WAIT_FOREVER
	#define OS_WAIT_FOREVER -1	/*mutex/semaphore will wait forever when use it to take*/
#endif

#define OS_OK           0      /* function return OK */
#define OS_ERROR        (-1)   /* function return ERROR */
#define OS_TIMEOUT		(-2)
#define OS_EXIT			(-3)

#ifdef __cplusplus
extern "C" {
#endif

void OS_verShow();

#ifdef __cplusplus
}
#endif

#endif/*_OS_GLOBAL_H*/

