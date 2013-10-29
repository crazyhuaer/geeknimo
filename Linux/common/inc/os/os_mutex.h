#ifndef _OS_MUTEX_H
#define _OS_MUTEX_H


#ifdef __cplusplus
extern "C" {
#endif

char * OS_mutexCreate();
int OS_mutexDelete(char * nMutexId);
int OS_mutexTake( char * nMutexId );
int OS_mutexGive(char * nMutexId);

void OS_mutexEnableErrPrint();
void OS_mutexDisableErrPrint();


#ifdef __cplusplus
}
#endif

#endif/*_OS_MUTX_H*/

