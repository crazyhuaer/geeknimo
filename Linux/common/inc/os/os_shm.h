#ifndef	OS_SHM_H
#define	OS_SHM_H

#ifdef WIN32
#include <windows.h>

#else
#include <sys/shm.h>
#define HANDLE	int
#endif

#ifdef __cplusplus
extern "C" {
#endif

HANDLE OS_shmget(int key,int size);
int OS_shmdt(const void *shmaddr);
void OS_shmclose(HANDLE shmid);
void* OS_shmat(HANDLE shmid);

#ifdef __cplusplus
}
#endif
#endif  /*OS_SHM_H*/


