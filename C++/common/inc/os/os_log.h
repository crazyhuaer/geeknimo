/*************************************************************************
***
*** File name  : os_log.h
***
*** Module     : common Log
***
*** Version    : 1.0
***
*** Created On : 07/12/2008
***
*** Description:
 ***            This header file definitions for common log used in win32 and linux
***
*** Modification histroy:
***
**************************************************************************/



#ifndef __OS_LOG_H_
#define __OS_LOG_H_



#ifdef WIN32


/*
 *below is copy from syslog
 */

/* syslog priorities */

#define LOG_EMERG   0   /* system is unusable */
#define LOG_ALERT   1   /* action must be taken immediately */
#define LOG_CRIT    2   /* critical conditions */
#define LOG_ERR     3   /* error conditions */
#define LOG_WARNING 4   /* warning conditions */
#define LOG_NOTICE  5   /* normal but significant condition */
#define LOG_INFO    6   /* informational */
#define LOG_DEBUG   7   /* debug-level messages */



/* syslog facilities */

#define LOG_KERN     (0<<3)     /* kernel messages */
#define LOG_USER     (1<<3)     /* random user-level messages */
#define LOG_MAIL     (2<<3)     /* mail system */
#define LOG_DAEMON   (3<<3)     /* system daemons */
#define LOG_AUTH     (4<<3)     /* security/authorization messages */
#define LOG_SYSLOG   (5<<3)     /* messages generated internally by syslogd */
#define LOG_LPR      (6<<3)     /* line printer subsystem */
#define LOG_NEWS     (7<<3)     /* network news subsystem */
#define LOG_UUCP     (8<<3)     /* UUCP subsystem */
#define LOG_CRON     (9<<3)     /* clock daemon */
#define LOG_AUTHPRIV (10<<3)    /* security/authorization messages (private) */
#define LOG_FTP      (11<<3)    /* ftp daemon */

    /* other codes through 15 reserved for system use */

#define LOG_LOCAL0   (16<<3)    /* reserved for local use */
#define LOG_LOCAL1   (17<<3)    /* reserved for local use */
#define LOG_LOCAL2   (18<<3)    /* reserved for local use */
#define LOG_LOCAL3   (19<<3)    /* reserved for local use */
#define LOG_LOCAL4   (20<<3)    /* reserved for local use */
#define LOG_LOCAL5   (21<<3)    /* reserved for local use */
#define LOG_LOCAL6   (22<<3)    /* reserved for local use */
#define LOG_LOCAL7   (23<<3)    /* reserved for local use */

/*
 * above is copy from linux syslog.h
 */



#define vsnprintf _vsnprintf
#define snprintf  _snprintf

#define OS_DIR_SEPARAT  '\\'

#else  /*ifdef LINUX*/

#define OS_DIR_SEPARAT  '/'

#endif /* #ifdef LINUX */


#ifdef __cplusplus
extern "C" {
#endif

/* log levels */

#define LVL_FATAL     16  /* 1<<4 */
#define LVL_ERR		  8   /* 1<<3 */
#define LVL_WRN		  4   /* 1<<2 */
#define LVL_INFO      2   /* 1<<1 */
#define LVL_TRACE     1

#define OS_LOG_NUM_OF_LEVELS      5
#define OS_LOG_FULL_LEVEL_MASK    0x1F  /* in binary: 11111 */
#define OS_LOG_DEFAULT_LEVEL_MASK 0x1C  /* in binary: 11110 */


/* special return value for slogInit() */
#define OS_LOG_ALREADY_INITED     -2

/* special return value for slogGetMask() */
#define OS_LOG_GET_MASK_ERR       0xF0000000

/* input vaules for printSwitch parameter of slogInit() */
#define OS_LOG_PRINT_ON           1
#define OS_LOG_PRINT_OFF          0

/* special input value for mod parameter of slogSetMask() */
#define OS_LOG_MOD_ALL            0xFFFFFFFF


#define OS_LOG_MAX_LOG_STR_LEN          1000

#define OS_LOG_MAX_REMOTE_ENTRY_LEN     OS_LOG_MAX_LOG_STR_LEN + OS_LOG_MAX_APP_NAME_LEN + 32

#define OS_LOG_EVENT_LOG_ENTRY          WS_EVENT_USER_BASE
#define OS_LOG_MIN_FILE_SIZE            8192
#define OS_LOG_DEFAULT_MAX_FILE_SIZE    512*1024
#define OS_LOG_MAX_FILE_SIZE			   512*1024*1024   /*the max file size is 512M*/
#define OS_LOG_DEFAULT_MAX_BACKUPS      4      /* must > 0 */
#define OS_LOG_MAX_BACKUPS				  10000   /*the max backup file numbers*/
#define OS_LOG_SKT_SND_BUF_SIZE         65536  /* 64 KB, max: 252 KB */
#define OS_LOG_FLUSH_GRANULARITY        5      /* log file flush granularity (in seconds) */

#define OS_LOG_MOD_MAX					32   /*the max module number is 32*/

/* facilities/priorities -- defines which fac/pri pair is used */

#define OS_LOG_PRI  (LOG_LOCAL0 | LOG_DEBUG)

#ifndef MAX_PATH
#define MAX_PATH 256
#endif

#define OS_LOG_MAX_APP_NAME_LEN         32
#define OS_LOG_MAX_MODNAME_LEN          32
#define OS_LOG_MAX_LOCAL_ENTRY_HEAD_LEN 64


int OS_logModReg(unsigned int mod,const char *modname);
int OS_logInit(const char *remoteIp,const char *localFile,int   printSwitch);
int OS_logSetGrade(unsigned int  mod,unsigned int  grade);
void OS_log(unsigned int  level,unsigned int  mod,const char   *para, ...);


int OS_logSetParam(unsigned int maxFileSize,unsigned int maxBackup);
int OS_logSetPrint(int printSwitch);
int OS_logSetMask(unsigned int  mod,unsigned int  levelMask);
unsigned int OS_logGetMask(unsigned int mod);
int OS_logSetSysPri(unsigned int facility,unsigned int level);
void OS_logSetAppName(const char *appName);
void OS_logFlush();

void OS_logStatus();
void OS_logHelp();

int OS_logSetRemote(const char *remoteIp);

//de-init oslog
void OS_logDeInit();

#ifdef __cplusplus
}
#endif

#endif /* __OS_LOG_H_ */

