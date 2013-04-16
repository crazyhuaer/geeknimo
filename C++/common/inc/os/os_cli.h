/****************************************************************
***
*** File name  : os_cli.h
***
*** Module     : common Cli
***
*** Version    : 1.0
***
*** Created On : 07/30/2008
***
*** Description:
 ***            This header file definitions for common cli used in win32 and linux
***
*** Modification histroy:
***
****************************************************************/
#ifndef _OS_CLI_H_
#define _OS_CLI_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WIN32
#define	TRUE			1
#define	FALSE			0
#endif

typedef enum sec_type
{
    OS_SYMB_TYP_FUNC,
    OS_SYMB_TYP_DATA
}sec_type_e;

int OS_cliInit(int svrport);
int OS_regSym(const char *name, int size, int type, void* addr);

#ifdef __cplusplus
}
#endif
#endif  /* _OS_CLI_H_ */

