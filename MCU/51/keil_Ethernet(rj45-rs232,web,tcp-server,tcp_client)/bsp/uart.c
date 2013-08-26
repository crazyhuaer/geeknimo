#define UART_GLOBALS

#include "uart.h"

#define S2RI 1
#define S2TI 2


/*----------------------------------------------------------------------------
  Notes:
  The length of the receive and transmit buffers must be a power of 2.
  Each buffer has a next_in and a next_out index.
  If next_in = next_out, the buffer is empty.
  (next_in - next_out) % buffer_size = the number of characters in the buffer.
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
#if TBUF_SIZE < 2
#error TBUF_SIZE is too small.  It must be larger than 1.
#elif ((TBUF_SIZE & (TBUF_SIZE-1)) != 0)
#error TBUF_SIZE must be a power of 2.
#endif

#if RBUF_SIZE < 2
#error RBUF_SIZE is too small.  It must be larger than 1.
#elif ((RBUF_SIZE & (RBUF_SIZE-1)) != 0)
#error RBUF_SIZE must be a power of 2.
#endif

xdata struct buf_st rbuf = { 0, 0, };

xdata struct buf_st tbuf = { 0, 0, };

u8 tx_restart = 1;               // NZ if TX restart is required

/*------------------------------------------------------------------------------
  buffer_Init
  initialize the buffers
 *------------------------------------------------------------------------------*/
void buffer_Init (void) {

  tbuf.in = 0;                                    // Clear com buffer indexes
  tbuf.out = 0;
  tx_restart = 1;

  rbuf.in = 0;
  rbuf.out = 0;
}

/*------------------------------------------------------------------------------
  SenChar
  transmit a character
 *------------------------------------------------------------------------------*/
int SendChar (u8 c) {
  struct buf_st *p = &tbuf;
                                                  // If the buffer is full, return an error value
  if (SIO_TBUFLEN >= TBUF_SIZE)
    return (-1);
  ES = 0;                                                  
  p->buf [p->in & (TBUF_SIZE - 1)] = c;           // Add data to the transmit buffer.
  p->in++;
  ES = 1;
  if (tx_restart) {                               // If transmit interrupt is disabled, enable it
    tx_restart = 0;
	TI = 1;
  }

  return (0);
}

void xputs(u8 *dt)
{
	while(*dt)
		SendChar(*dt++);

	SendChar('\r');
	SendChar('\n');
}

/*------------------------------------------------------------------------------
  GetKey
  receive a character
 *------------------------------------------------------------------------------*/
int GetKey (void) {
  struct buf_st *p = &rbuf;
  u16 ret;

  if (SIO_RBUFLEN == 0)
    return (-1);
  ES = 0;
  ret = p->buf [(p->out++) & (RBUF_SIZE - 1)];
  ES = 1;
  return (ret);
}


//uart2 variables
bit busy = 0; //=0 可以发送  =1表示不可以发送


/**********************************************************************
**函数原型：    void Uart_Init(void)
**参数说明：	无
**返 回 值：	无      
**说    明：	串口初始化，采用T2，时钟和波特率在net_cfg.h中定义
************************************************************************/
void uart_init(void)
{
//uart1
	TMOD = (TMOD & 0x0F) | 0x20;
	TH1=256-ETH_CPU_XTAL/32/BPS;
	AUXR |= 0x40;	 //T1 1t mode  
	TL1=TH1;
	SCON=0x50;
	TR1=1;
	ES = 1;
	TI = 1;
//// 	RCAP2H=(65536-FOSC/16/BPS)/256;		  //6-clock mode
////	RCAP2L=(65536-FOSC/16/BPS)%256;
//	RCAP2H=(65536-ETH_CPU_XTAL/32/BPS)/256;		 //12-clock mode 
//	RCAP2L=(65536-ETH_CPU_XTAL/32/BPS)%256;
//	SCON = 0x50;	                      //串口工作方式1
//	T2CON = 0x34;	                   
////	TI=1;
//	PS=1;	//高中断优先级
//	ES=1;

//注意 串口2采用查询方式时，有问题，字节间需要很长的延时  否则字节无法同步 股这里采用中断收发
//uart2
	S2CON = 0x50;	
//	BRT = -(ETH_CPU_XTAL/12/32/BPS);
//	AUXR |= 0x10;
	BRT = -(ETH_CPU_XTAL/32/115200);
	AUXR |= 0x14;  //BRTR = 1, BRTx12 = 1
	IE2 = 0x01;
//	EA = 1;


}


//void put2(u8 dt)
//{
//	if(busy==1) while(busy==1);
//	S2BUF = dt;
//	busy = 1;
//}
//
////串口2输出字符串  用于输出调试日志
//void put2s(u8 *p)
//{
//	while(*p)
//	{
//		put2(*p++);
//	}
//}
//
//void put2hex(u8 *p, len)
//{
//	u8 i;
//	code u8 tab[] = "0123456789ABCDEF";
//	for(i=0; i<len; i++)
//	{
//		put2(tab[p[i]>>4]);
//		put2(tab[p[i]&0x0f]);
//		put2(' ');
//	}
//}
//

/**********************************************************************
**函数原型：    void  	Printf_Char(uchar ascii)
**参数说明：	ascii：	发送到串口的ASCII
**返 回 值：	无      
**说    明：	往串口发送一个字符
************************************************************************/
//void put(unsigned char ascii)
//{	ES=0;
//	SBUF=ascii;
//	while(!TI);
//	TI=0;
//	ES=1;
//}


/*******************************************************************
串口ISR，执行一些命令
********************************************************************/
void serial(void) interrupt 4
{
	struct buf_st *p;
	
	if(TI) 
	{	
		TI=0;
		p = &tbuf;
		
		if (p->in != p->out) {
			SBUF = (p->buf [p->out & (TBUF_SIZE-1)] & 0x1FF);
			p->out++;
			tx_restart = 0;
		}
		else {
			tx_restart = 1;
		}
	} 

	if (RI)
	{	RI=0;
		p = &rbuf;
		
		if (((p->in - p->out) & ~(RBUF_SIZE-1)) == 0) {
			p->buf [p->in & (RBUF_SIZE-1)] = SBUF;
			p->in++;
		}
	}	 
}

void uart2_isr(void) interrupt 8 using 2
{

	if(S2CON & S2RI)
	{
		S2CON &= ~S2RI;
		S2BUF = S2BUF;
	}
	
	if(S2CON & S2TI)
	{
		S2CON &= ~S2TI;	
		busy = 0;
	}
}

