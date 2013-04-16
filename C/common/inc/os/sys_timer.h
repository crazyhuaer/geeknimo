#ifndef  _SYS_TIMER_H_
#define  _SYS_TIMER_H_

#include "sys_queue.h"
#include "sys_cdefs.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef  TIMER_IN_SERVER
#define	TIMER_WHEEL_SIZE		8192
#else
#define TIMER_WHEEL_SIZE		32
#endif

struct os_sys_timer;
struct sys_timerpool;

typedef struct os_sys_timer		sys_timer_t;
typedef struct sys_timerpool	sys_timerpool_t;


typedef void (*sys_timerproc_t)(unsigned int arg1, unsigned int arg2) ;



#define	TIMER_F_FREE			0x01
#define	TIMER_F_IDLE			0x02
#define	TIMER_F_ACTIVE			0x03

#define	TIMER_FREE_MAGIC		0xF2EE
#define	TIMER_ACTIVE_MAGIC	0xAC75
#define	TIMER_IDLE_MAGIC		0x1DEE

#define	TIMER_IS_FREE(tmr)		(NULL != (tmr) && (tmr)->tmr_magic == TIMER_FREE_MAGIC)
#define	TIMER_IS_ACTIVE(tmr)	(NULL != (tmr) && (tmr)->tmr_magic == TIMER_ACTIVE_MAGIC)
#define	TIMER_IS_IDLE(tmr)		(NULL != (tmr) && (tmr)->tmr_magic == TIMER_IDLE_MAGIC)
struct os_sys_timer
{
	TAILQ_ENTRY(os_sys_timer)	tmr_listq;
	unsigned short			tmr_magic;

	sys_timerpool_t			*tmr_owner;

	unsigned short			tmr_flag;
	unsigned int				tmr_period;		/* unit is tick */

	unsigned int				tmr_timeout;

	sys_timerproc_t			tmr_proc;
	unsigned int				tmr_arg1;
	unsigned int				tmr_arg2;
};

typedef TAILQ_HEAD(sys_timerlist, os_sys_timer)	sys_timerlist_t;


/*
 * Timer pool definition
 */
struct sys_timerpool
{
	sys_timer_t			*tp_memptr;
	sys_timer_t			*tp_current;

	unsigned int			tp_maxtimer;

	sys_timerlist_t		tp_freelist;

	unsigned int			tp_mytick;
	
	unsigned int			tp_ms_1_tick;

	sys_timerlist_t		tp_wheel[TIMER_WHEEL_SIZE];
};






/*
 * The following are public intefaces
 */

/*
 * Use the two macro to judge if the timer is active(idle)
 */
#define SYS_TIMER_IS_ACTIVE(timer)	(NULL != (timer) && (timer)->tmr_flag == TIMER_F_ACTIVE)
#define SYS_TIMER_IS_IDLE(timer)		(NULL != (timer) && (timer)->tmr_flag == TIMER_F_IDLE)


/*
 * Allocate a timer from the timer pool. 'interval': unit is microsecond. 
 */
#define	SYS_TIMER_ALLOC(pool, timer, interval)		do{						\
	SYS_ASSERT((interval) > 0);												\
	if (NULL != ((timer) = TAILQ_FIRST(&(pool)->tp_freelist))){					\
		SYS_ASSERT(TIMER_IS_FREE((timer)));								\
		TAILQ_REMOVE(&(pool)->tp_freelist, (timer), tmr_listq);					\
		(timer)->tmr_magic = TIMER_IDLE_MAGIC;								\
		(timer)->tmr_flag = TIMER_F_IDLE;										\
		(timer)->tmr_owner = (pool);											\
		(timer)->tmr_period = ((interval)/pool->tp_ms_1_tick);					\
	}																		\
}while(0)


/*
 * Start a timer with callback-func with two paramters;
 * The timer will timeout(callback-func will be called) after 'period' microsends;
 * 'period' is the timer period that you must provide when you allocate a timer; 
 */
#define	SYS_TIMER_START(timer, proc_p, arg1, arg2)	do{						\
	unsigned int	_Xwheelpos;													\
	sys_timerpool_t	*_Xpool;													\
	if (SYS_TIMER_IS_ACTIVE(timer)) {										\
		SYS_TIMER_STOP(timer);												\
	}																		\
	if (SYS_TIMER_IS_IDLE(timer)){											\
		_Xpool = (timer)->tmr_owner;											\
		(timer)->tmr_magic = TIMER_ACTIVE_MAGIC;								\
		(timer)->tmr_flag = TIMER_F_ACTIVE;									\
		(timer)->tmr_timeout = _Xpool->tp_mytick + (timer)->tmr_period;			\
		(timer)->tmr_proc = (sys_timerproc_t)(proc_p);							\
		(timer)->tmr_arg1 = (unsigned int)(arg1);								\
		(timer)->tmr_arg2 = (unsigned int)(arg2);								\
		_Xwheelpos = (timer)->tmr_timeout%TIMER_WHEEL_SIZE;					\
		TAILQ_INSERT_TAIL(&_Xpool->tp_wheel[_Xwheelpos], (timer), tmr_listq);	\
	}																		\
}while(0)


/*
 * Start a timer with callback-func with two paramters;
 * The timer will timeout(callback-func will be called) after 'timeout' microsends;
 */
#define	SYS_TIMER_START2(timer, timeout, proc_p, arg1, arg2)	do{				\
	unsigned int	_Xwheelpos;													\
	sys_timerpool_t	*_Xpool;													\
	SYS_ASSERT((timeout) > 0);												\
	if (SYS_TIMER_IS_ACTIVE(timer)) {										\
		SYS_TIMER_STOP(timer);												\
	}																		\
	if (SYS_TIMER_IS_IDLE(timer)){											\
		_Xpool = (timer)->tmr_owner;											\
		(timer)->tmr_magic = TIMER_ACTIVE_MAGIC;								\
		(timer)->tmr_flag = TIMER_F_ACTIVE;									\
		(timer)->tmr_timeout = _Xpool->tp_mytick + ((timeout)/_Xpool->tp_ms_1_tick);\
		(timer)->tmr_proc = (sys_timerproc_t)(proc_p);							\
		(timer)->tmr_arg1 = (unsigned int)(arg1);								\
		(timer)->tmr_arg2 = (unsigned int)(arg2);								\
		_Xwheelpos = (timer)->tmr_timeout%TIMER_WHEEL_SIZE;					\
		TAILQ_INSERT_TAIL(&_Xpool->tp_wheel[_Xwheelpos], (timer), tmr_listq);	\
	}																		\
}while(0)

/*
 * Stop the timer
 */
#define	SYS_TIMER_STOP(timer)	do{											\
	unsigned int	_Xwheelpos;													\
	sys_timerpool_t	*_Xpool;													\
	SYS_ASSERT(TIMER_IS_ACTIVE((timer)));									\
	if (SYS_TIMER_IS_ACTIVE(timer)){											\
		_Xpool = (timer)->tmr_owner;											\
		if (_Xpool->tp_current == (timer)) {										\
			_Xpool->tp_current = TAILQ_NEXT(timer, tmr_listq);					\
		}																	\
		(timer)->tmr_magic = TIMER_IDLE_MAGIC;								\
		(timer)->tmr_flag = TIMER_F_IDLE;										\
		_Xwheelpos = (timer)->tmr_timeout%TIMER_WHEEL_SIZE;					\
		TAILQ_REMOVE(&_Xpool->tp_wheel[_Xwheelpos], (timer), tmr_listq);		\
	}																		\
}while(0)


/*
 * Release timer to timer pool
 */
#define	SYS_TIMER_FREE(timer)	do{											\
	sys_timerpool_t	*_Xpool;													\
	if (NULL != (timer)) {														\
		_Xpool = (timer)->tmr_owner;											\
		SYS_ASSERT(TIMER_IS_ACTIVE((timer)) ||								\
			TIMER_IS_IDLE((timer)));											\
		if (SYS_TIMER_IS_ACTIVE((timer))){									\
			SYS_TIMER_STOP((timer));										\
		}																	\
		(timer)->tmr_magic = TIMER_FREE_MAGIC;								\
		(timer)->tmr_flag = TIMER_F_FREE;										\
		TAILQ_INSERT_HEAD(&_Xpool->tp_freelist, (timer), tmr_listq);				\
		(timer) = NULL;														\
	}																		\
}while(0)

/*
 * Create a timer pool
 */
sys_timerpool_t*		sys_timerpool_create(unsigned int max_timer, unsigned int tick_interval);	/* tick_interval unit is microsecond*/

/*
 * User's APP must call this func once every tick to drive your timer pool in your task enviroment.
 * It is to say the func 'sys_timerpool_ticking' must be called in the main loop of your task(thread).
 */
void					sys_timerpool_ticking(sys_timerpool_t *tp);


#ifdef __cplusplus
}
#endif

#endif
