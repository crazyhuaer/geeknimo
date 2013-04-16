#ifndef _OS_SEM_H
#define _OS_SEM_H


#ifdef __cplusplus
extern "C" {
#endif

/*it mean the max sem id is 256, note: it just limit in WIN32 */
#define SEM_MAX_INIT_NUM	256

/*program can use this variable to check if a timeout happend when semaphore take*/
extern int g_os_sem_timeout_flag;

int OS_semTake(char * nSemId, int nTimeout);
int OS_semGive(char * nSemId);
int OS_semDelete(char * nSemId);
char * OS_semCreate(int lInitCount);

void OS_semDisableErrPrint();
void OS_semEnableErrPrint();

#ifdef __cplusplus
}
#endif

#endif/*_OS_SEM_H*/

