#ifndef _UART_H_
#define _UART_H_

#include "etherdev.h"
#include <stdio.h>
#include "mytype.h"

//#define BPS	115200
#define BPS	19200


#define TBUF_SIZE   1024	     /*** Must be a power of 2 (2,4,8,16,32,64,128,256,512,...) ***/
#define RBUF_SIZE   1024      /*** Must be a power of 2 (2,4,8,16,32,64,128,256,512,...) ***/

struct buf_st {
  u16 in;                                // Next In Index
  u16 out;                               // Next Out Index
  u8 buf [RBUF_SIZE];                           // Buffer
};


extern xdata struct buf_st rbuf;
#define SIO_RBUFLEN ((u16)(rbuf.in - rbuf.out))

extern xdata struct buf_st tbuf;
#define SIO_TBUFLEN ((u16)(tbuf.in - tbuf.out))


void uart_init(void);
void buffer_Init (void);
int SendChar (u8 c);
int GetKey (void);
void xputs(u8 *dt);
void put2s(u8 *p);

#define xlog(x) xputs(x)
//#define xlog(x) put2s(x)
//#define xlog(x)




#endif