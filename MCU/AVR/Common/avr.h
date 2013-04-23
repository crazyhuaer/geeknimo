/************************************************************************ 
* 
*   文件名：avr.h
* 
*   文件描述：AVR开发自定义头文件
* 
*   创建人： Crazy_huaer(Neo), 2010年5月6日 
* 
*   版本号：1.0 
* 
*   修改记录： 无
* 
************************************************************************/ 
#include	<avr/io.h>
#include	<avr/interrupt.h>

//Define Register Operate
#define clearPA0()  (PORTA&=~(1<<PA0))
#define clearPA1()  (PORTA&=~(1<<PA1))
#define clearPA2()  (PORTA&=~(1<<PA2))
#define clearPA3()  (PORTA&=~(1<<PA3))
#define clearPA4()  (PORTA&=~(1<<PA4))
#define clearPA5()  (PORTA&=~(1<<PA5))
#define clearPA6()  (PORTA&=~(1<<PA6))
#define clearPA7()  (PORTA&=~(1<<PA7))

#define clearPB0()  (PORTB&=~(1<<PB0))
#define clearPB1()  (PORTB&=~(1<<PB1))
#define clearPB2()  (PORTB&=~(1<<PB2))
#define clearPB3()  (PORTB&=~(1<<PB3))
#define clearPB4()  (PORTB&=~(1<<PB4))
#define clearPB5()  (PORTB&=~(1<<PB5))
#define clearPB6()  (PORTB&=~(1<<PB6))
#define clearPB7()  (PORTB&=~(1<<PB7))

#define clearPC0()  (PORTC&=~(1<<PC0))
#define clearPC1()  (PORTC&=~(1<<PC1))
#define clearPC2()  (PORTC&=~(1<<PC2))
#define clearPC3()  (PORTC&=~(1<<PC3))
#define clearPC4()  (PORTC&=~(1<<PC4))
#define clearPC5()  (PORTC&=~(1<<PC5))
#define clearPC6()  (PORTC&=~(1<<PC6))
#define clearPC7()  (PORTC&=~(1<<PC7))

#define clearPD0()  (PORTD&=~(1<<PD0))
#define clearPD1()  (PORTD&=~(1<<PD1))
#define clearPD2()  (PORTD&=~(1<<PD2))
#define clearPD3()  (PORTD&=~(1<<PD3))
#define clearPD4()  (PORTD&=~(1<<PD4))
#define clearPD5()  (PORTD&=~(1<<PD5))
#define clearPD6()  (PORTD&=~(1<<PD6))
#define clearPD7()  (PORTD&=~(1<<PD7))

#define setPA0()  (PORTA|=(1<<PA0))
#define setPA1()  (PORTA|=(1<<PA1))
#define setPA2()  (PORTA|=(1<<PA2))
#define setPA3()  (PORTA|=(1<<PA3))
#define setPA4()  (PORTA|=(1<<PA4))
#define setPA5()  (PORTA|=(1<<PA5))
#define setPA6()  (PORTA|=(1<<PA6))
#define setPA7()  (PORTA|=(1<<PA7))

#define setPB0()  (PORTB|=(1<<PB0))
#define setPB1()  (PORTB|=(1<<PB1))
#define setPB2()  (PORTB|=(1<<PB2))
#define setPB3()  (PORTB|=(1<<PB3))
#define setPB4()  (PORTB|=(1<<PB4))
#define setPB5()  (PORTB|=(1<<PB5))
#define setPB6()  (PORTB|=(1<<PB6))
#define setPB7()  (PORTB|=(1<<PB7))

#define setPC0()  (PORTC|=(1<<PC0))
#define setPC1()  (PORTC|=(1<<PC1))
#define setPC2()  (PORTC|=(1<<PC2))
#define setPC3()  (PORTC|=(1<<PC3))
#define setPC4()  (PORTC|=(1<<PC4))
#define setPC5()  (PORTC|=(1<<PC5))
#define setPC6()  (PORTC|=(1<<PC6))
#define setPC7()  (PORTC|=(1<<PC7))

#define setPD0()  (PORTD|=(1<<PD0))
#define setPD1()  (PORTD|=(1<<PD1))
#define setPD2()  (PORTD|=(1<<PD2))
#define setPD3()  (PORTD|=(1<<PD3))
#define setPD4()  (PORTD|=(1<<PD4))
#define setPD5()  (PORTD|=(1<<PD5))
#define setPD6()  (PORTD|=(1<<PD6))
#define setPD7()  (PORTD|=(1<<PD7))

#define opposePA0()  (PORTA^=(1<<PA0))
#define opposePA1()  (PORTA^=(1<<PA1))
#define opposePA2()  (PORTA^=(1<<PA2))
#define opposePA3()  (PORTA^=(1<<PA3))
#define opposePA4()  (PORTA^=(1<<PA4))
#define opposePA5()  (PORTA^=(1<<PA5))
#define opposePA6()  (PORTA^=(1<<PA6))
#define opposePA7()  (PORTA^=(1<<PA7))

#define opposePB0()  (PORTB^=(1<<PB0))
#define opposePB1()  (PORTB^=(1<<PB1))
#define opposePB2()  (PORTB^=(1<<PB2))
#define opposePB3()  (PORTB^=(1<<PB3))
#define opposePB4()  (PORTB^=(1<<PB4))
#define opposePB5()  (PORTB^=(1<<PB5))
#define opposePB6()  (PORTB^=(1<<PB6))
#define opposePB7()  (PORTB^=(1<<PB7))

#define opposePC0()  (PORTC^=(1<<PC0))
#define opposePC1()  (PORTC^=(1<<PC1))
#define opposePC2()  (PORTC^=(1<<PC2))
#define opposePC3()  (PORTC^=(1<<PC3))
#define opposePC4()  (PORTC^=(1<<PC4))
#define opposePC5()  (PORTC^=(1<<PC5))
#define opposePC6()  (PORTC^=(1<<PC6))
#define opposePC7()  (PORTC^=(1<<PC7))

#define opposePD0()  (PORTD^=(1<<PD0))
#define opposePD1()  (PORTD^=(1<<PD1))
#define opposePD2()  (PORTD^=(1<<PD2))
#define opposePD3()  (PORTD^=(1<<PD3))
#define opposePD4()  (PORTD^=(1<<PD4))
#define opposePD5()  (PORTD^=(1<<PD5))
#define opposePD6()  (PORTD^=(1<<PD6))
#define opposePD7()  (PORTD^=(1<<PD7))

#define clearDA0()  (DDRA&=~(1<<PA0))
#define clearDA1()  (DDRA&=~(1<<PA1))
#define clearDA2()  (DDRA&=~(1<<PA2))
#define clearDA3()  (DDRA&=~(1<<PA3))
#define clearDA4()  (DDRA&=~(1<<PA4))
#define clearDA5()  (DDRA&=~(1<<PA5))
#define clearDA6()  (DDRA&=~(1<<PA6))
#define clearDA7()  (DDRA&=~(1<<PA7))

#define clearDB0()  (DDRB&=~(1<<PB0))
#define clearDB1()  (DDRB&=~(1<<PB1))
#define clearDB2()  (DDRB&=~(1<<PB2))
#define clearDB3()  (DDRB&=~(1<<PB3))
#define clearDB4()  (DDRB&=~(1<<PB4))
#define clearDB5()  (DDRB&=~(1<<PB5))
#define clearDB6()  (DDRB&=~(1<<PB6))
#define clearDB7()  (DDRB&=~(1<<PB7))

#define clearDC0()  (DDRC&=~(1<<PC0))
#define clearDC1()  (DDRC&=~(1<<PC1))
#define clearDC2()  (DDRC&=~(1<<PC2))
#define clearDC3()  (DDRC&=~(1<<PC3))
#define clearDC4()  (DDRC&=~(1<<PC4))
#define clearDC5()  (DDRC&=~(1<<PC5))
#define clearDC6()  (DDRC&=~(1<<PC6))
#define clearDC7()  (DDRC&=~(1<<PC7))

#define clearDD0()  (DDRD&=~(1<<PD0))
#define clearDD1()  (DDRD&=~(1<<PD1))
#define clearDD2()  (DDRD&=~(1<<PD2))
#define clearDD3()  (DDRD&=~(1<<PD3))
#define clearDD4()  (DDRD&=~(1<<PD4))
#define clearDD5()  (DDRD&=~(1<<PD5))
#define clearDD6()  (DDRD&=~(1<<PD6))
#define clearDD7()  (DDRD&=~(1<<PD7))

#define setDA0()  (DDRA|=(1<<PA0))
#define setDA1()  (DDRA|=(1<<PA1))
#define setDA2()  (DDRA|=(1<<PA2))
#define setDA3()  (DDRA|=(1<<PA3))
#define setDA4()  (DDRA|=(1<<PA4))
#define setDA5()  (DDRA|=(1<<PA5))
#define setDA6()  (DDRA|=(1<<PA6))
#define setDA7()  (DDRA|=(1<<PA7))

#define setDB0()  (DDRB|=(1<<PB0))
#define setDB1()  (DDRB|=(1<<PB1))
#define setDB2()  (DDRB|=(1<<PB2))
#define setDB3()  (DDRB|=(1<<PB3))
#define setDB4()  (DDRB|=(1<<PB4))
#define setDB5()  (DDRB|=(1<<PB5))
#define setDB6()  (DDRB|=(1<<PB6))
#define setDB7()  (DDRB|=(1<<PB7))

#define setDC0()  (DDRC|=(1<<PC0))
#define setDC1()  (DDRC|=(1<<PC1))
#define setDC2()  (DDRC|=(1<<PC2))
#define setDC3()  (DDRC|=(1<<PC3))
#define setDC4()  (DDRC|=(1<<PC4))
#define setDC5()  (DDRC|=(1<<PC5))
#define setDC6()  (DDRC|=(1<<PC6))
#define setDC7()  (DDRC|=(1<<PC7))

#define setDD0()  (DDRD|=(1<<PD0))
#define setDD1()  (DDRD|=(1<<PD1))
#define setDD2()  (DDRD|=(1<<PD2))
#define setDD3()  (DDRD|=(1<<PD3))
#define setDD4()  (DDRD|=(1<<PD4))
#define setDD5()  (DDRD|=(1<<PD5))
#define setDD6()  (DDRD|=(1<<PD6))
#define setDD7()  (DDRD|=(1<<PD7))

#define getPA0() (PINA&(1<<PA0))
#define getPA1() (PINA&(1<<PA1))
#define getPA2() (PINA&(1<<PA2))
#define getPA3() (PINA&(1<<PA3))
#define getPA4() (PINA&(1<<PA4))
#define getPA5() (PINA&(1<<PA5))
#define getPA6() (PINA&(1<<PA6))
#define getPA7() (PINA&(1<<PA7))

#define getPB0() (PINB&(1<<PB0))
#define getPB1() (PINB&(1<<PB1))
#define getPB2() (PINB&(1<<PB2))
#define getPB3() (PINB&(1<<PB3))
#define getPB4() (PINB&(1<<PB4))
#define getPB5() (PINB&(1<<PB5))
#define getPB6() (PINB&(1<<PB6))
#define getPB7() (PINB&(1<<PB7))

#define getPC0() (PINC&(1<<PC0))
#define getPC1() (PINC&(1<<PC1))
#define getPC2() (PINC&(1<<PC2))
#define getPC3() (PINC&(1<<PC3))
#define getPC4() (PINC&(1<<PC4))
#define getPC5() (PINC&(1<<PC5))
#define getPC6() (PINC&(1<<PC6))
#define getPC7() (PINC&(1<<PC7))

#define getPD0() (PIND&(1<<PD0))
#define getPD1() (PIND&(1<<PD1))
#define getPD2() (PIND&(1<<PD2))
#define getPD3() (PIND&(1<<PD3))
#define getPD4() (PIND&(1<<PD4))
#define getPD5() (PIND&(1<<PD5))
#define getPD6() (PIND&(1<<PD6))
#define getPD7() (PIND&(1<<PD7))

#define setInterrupt()      (SREG|=0x80)
#define clearInterrupt()      (SREG&=~0x80)

//Define Type
#define	uint	unsigned	int
#define	uchar	unsigned	char
#define	ufloat	unsigned	float
#define	udouble	unsigned	double

/************************************************************************ 
* 
*   文件名：	delay.h
* 
*   文件描述：	延时函数
* 
*   创建人： Crazy_huaer(Neo), 2010年5月9日 
* 
*   版本号：1.0 
* 
*   修改记录： 无
* 
************************************************************************/ 
/*******************************************
函数名称: delayus
功    能: 延时指定微秒（8M晶振）
参    数: US--延时的微秒数(大约，不是很精确，MS越大越准确)
返回值  : 无
/********************************************/
void delayus( uint us )		  
{
	 uint i;
	 us	= us * 5 / 4;		  	 //5/4是在8MHz晶振下，通过软件仿真反复实验得到的数值
	 for( i=0;i<us;i++); 
}
/*******************************************
函数名称: delayms
功    能: 延时指定毫秒（8M晶振）
参    数: MS--延时的毫秒数
返回值  : 无
/********************************************/
void delayms( uint MS )
{
	 uint i,j;
	 for( i=0;i<MS;i++)
	 for( j=0;j<1141;j++);	//1141是在8MHz晶振下，通过软件仿真反复实验得到的数值
}






/************************************************************************ 
* 
*   文件名：	key.h
* 
*   文件描述：	延时函数
* 
*   创建人： Crazy_huaer(Neo), 2010年5月9日 
* 
*   版本号：1.0 
* 
*   修改记录： 无
* 
************************************************************************/ 
/*******************************************
函数名称: scan_key
功    能: 键盘扫描
参    数: 无
返回值  : 无
/********************************************/
//键盘扫描信号
uchar	scan_signal[4] = {	0xfe , 0xfd , 0xfb , 0xf7 };
uchar	scan_key(void)
{
	uchar	col_value,row_value,find = 0;
	uchar	i,j,in;

	for( i = 0 ; i < 4 ; i++)
	{
		PORTB = scan_signal[i];
		delayms(6);
		delayus(500);
		in = PINB;
		in = (in >> 4) | 0xf0;
		
		for( j = 0; j < 4 ;j++ )
		{
			if(	scan_signal[j] == in)
			{
				find = 1;
				col_value = i;
				row_value = j;
			}
			
		}	
	}
	return ( find == 1 ) ? ( 4 * col_value + row_value ) : 16;
}





/************************************************************************ 
* 
*   文件名：	beep.h
* 
*   文件描述：	蜂鸣器宏定义
* 
*   创建人： Crazy_huaer(Neo), 2010年5月9日 
* 
*   版本号：1.0 
* 
*   修改记录： 无
* 
************************************************************************/ 
/******************蜂鸣器音乐常量******************/
#define BEEP     PA6
//      计时值=65536-8000000/8/2/频率  
//      音名     计时值       频率Hz
#define DO_L     63627       //262
#define DOA_L    63731       //277
#define RE_L     63835       //294
#define REA_L    63928       //311
#define MI_L     64021       //330 
#define FA_L     64103       //349 
#define FAA_L    64185       //370
#define SO_L     64270       //392
#define SOA_L    64331       //415 
#define LA_L     64400       //440
#define LAA_L    64463       //466
#define TI_L     64524       //494 
#define DO       64580       //523
#define DOA      64633       //554
#define RE       64684       //587 
#define REA      64732       //622
#define MI       64777       //659 
#define FA       64820       //698 
#define FAA      64860       //740
#define SO       64898       //784 
#define SOA      64934       //831
#define LA       64968       //880  
#define LAA      65000       //932
#define TI       65030       //988                                               
#define DO_H     65058       //1046
#define DOA_H    65085       //1109
#define RE_H     65110       //1175
#define REA_H    65134       //1245 
#define MI_H     65157       //1318 
#define FA_H     65178       //1397
#define FAA_H    65198       //1480
#define SO_H     65217       //1568 
#define SOA_H    65235       //1661
#define LA_H     65252       //1760 
#define LAA_H    65268       //1865
#define TI_H     65283       //1976 
#define ZERO     0           //休止符
//十进制:     0
//休止符:     0
 
//十进制:     1     2     3     4     5     6     7     8     9     10    11     12
//低音  :     1     #1    2     #2    3     4     #4    5     #5    6     #6     7
 
//十进制:     13    14    15    16    17    18    19    20    21    22    23     24
// 中音 :     1     #1    2     #2    3     4     #4    5     #5    6     #6     7

//十进制:     25    26    27    28    29    30    31    32    33    34    35     36
// 高音 :     1     #1    2     #2    3     4     #4    5     #5    6     #6     7







/************************************************************************ 
* 
*   文件名：	int.h
* 
*   文件描述：中断处理
* 
*   创建人： Crazy_huaer(Neo), 2010年5月9日 
* 
*   版本号：1.0 
* 
*   修改记录： 无
* 
************************************************************************/ 
/*============================================================ 
* 
* 函 数 名： INTERRUPT_init
* 
* 参  数： 
* 
*     		int	flag;用于标识开启的中断量
					int	clock;用于标识中断是上升沿还是下降沿
* 
* 功能描述: 
* 
*						中断初始化
* 
* 返 回 值：空 
* 
* 抛出异常： 
* 
* 作  者：Crazyhuaer(Neo) 2010/5/9 
* 
============================================================*/
#define	UP	0
#define	DOWN	1
void	INTERRUPT_init(int	flag,int	clock)
{
	switch(flag)
	{
		case	0:	//开启中断0	
							if(clock == UP)
							{
								MCUCR |= (1 << ISC00) | (1 << ISC01);
								GICR  |= (1 << INT0);
							}
							else
							{
								MCUCR |= (1 << ISC01);
								GICR  |= (1 << INT0);	
							}
							setPD2();
							break;
		case	1:	//开启中断1	
							if(clock == UP)
							{
								MCUCR |= (1 << ISC11) | (1 << ISC10);
								GICR  |= (1 << INT1);
							}
							else
							{
								MCUCR |= (1 << ISC11);
								GICR  |= (1 << INT1);	
							}
							setPD3();
							break;
		case	2:	//开启中断2
							GICR |= (1 << INT2);
							if(clock == UP)
							{
								MCUCSR |= (1 << ISC2);
							} 
							setPB2();
							break;
		default:
							MCUCR |= (1 << ISC11) | (1 << ISC10) 
												| (1 << ISC01) | (1 << ISC00);
							GICR  |= (1 << INT2) | (1 << INT1) | (1 << INT0);
							setPD2();
							setPD3();
							setPB2();
							break;
	}
}







/************************************************************************ 
* 
*   文件名：	ioinit.h
* 
*   文件描述：串口的使用
* 
*   创建人： Crazy_huaer(Neo), 2010年5月9日 
* 
*   版本号：1.0 
* 
*   修改记录： 无
* 
************************************************************************/ 
void	ioinit()
{
		DDRA = 0xff;
		DDRB = 0xff;
		DDRC = 0xff;
		
		PORTA = 0x00;
		PORTB = 0xff;
		PORTC = 0xff;
}







/************************************************************************ 
* 
*   文件名：usart.h
* 
*   文件描述：串口的使用
* 
*   创建人： Crazy_huaer(Neo), 2010年5月9日 
* 
*   版本号：1.0 
* 
*   修改记录： 无
* 
************************************************************************/ 

/***********************************************/
// UART 
// CPU Frequence and Baud  单片机频率和波特率
#define	FRE_CPU	8000000
#define	BAUD	9600  
//数据接收变量
volatile	char	recieve_data=0;

/*============================================================ 
* 
* 函 数 名：usart_init
* 
* 参  数： 
* 
*     		void
* 
* 功能描述: 
* 
*						USART初始化
* 
* 返 回 值：空 
* 
* 抛出异常： 
* 
* 作  者：Crazyhuaer(Neo) 2010/5/9 
* 
============================================================*/
void	usart_init(void)
{
	// Data write register and Date read register----UBRRH  and UBRRL
	UCSRA = 0x00;
	UCSRC |= (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); //8位数据位+1位停止位
	UBRRH = (FRE_CPU/BAUD/16-1)/256;
	UBRRL = (FRE_CPU/BAUD/16-1)%256;
	UCSRB |= (1 << RXCIE) | (1 << RXEN) | ( 1 << TXEN); //允许发送和接收,接收中断使能
}
/*============================================================ 
* 
* 函 数 名：	uart_charsend
* 
* 参  数： 
* 
*     		char	data	：发送的字符
* 
* 功能描述: 
* 
*						USART字符发送函数
* 
* 返 回 值：	空 
* 
* 抛出异常： 
* 
* 作  者：Crazyhuaer(Neo) 2010/5/9 
* 
============================================================*/
void uart_charsend( char data )
{
	/* Is not completly? */
	// Use Query approach send and Interrupt approach recieve
	// UCSRA ...UDRE(BIT)
	while ( !( UCSRA &( 1<<UDRE)) );
	/* send data */
	UDR = data;
}
/*============================================================ 
* 
* 函 数 名：	uart_charsend_str
* 
* 参  数： 
* 
*     		char	*str	：发送的字符串
* 
* 功能描述: 
* 
*						USART字符发送串函数
* 
* 返 回 值：	空 
* 
* 抛出异常： 
* 
* 作  者：Crazyhuaer(Neo) 2010/5/9 
* 
============================================================*/
void	uart_charsend_str(char	*str)
{	
		while(*str != '\0')
		{
				uart_charsend(*str);
				str++;
		}
		uart_charsend(0x0a);	//结尾时回车
		uart_charsend(0x0d);
}

/******************************************************************/









/************************************************************************ 
* 
*   文件名：	board.h
* 
*   文件描述：	开发板初始化
* 
*   创建人： Crazy_huaer(Neo), 2010年5月9日 
* 
*   版本号：1.0 
* 
*   修改记录： 无
* 
************************************************************************/ 
/*******************************************
函数名称: Board_init
功    能: 初始化实验板，关闭全部功能
参    数: 无
返回值  : 无
/********************************************/
void Board_init(void)
{
	DDRA=0xFF;	//将四个IO口全部配置为输出
	DDRB=0xFF;
	DDRC=0xFF;
	DDRD=0xFF;

	SPCR=0x00;	//还原SPI口，使其为正常端口	

	setPA6();//(BEEP)关闭蜂鸣器
	clearPC6();	  //(RELAY)初始化继电器为常闭连接状态	
	clearPA1();	//关闭SPI总线DA
	PORTB=0xFF;	//关闭LED
	setPA2();	//锁存数据，使LED熄灭
 	delayus(5);		
 	clearPA2();
	
	PORTB=0x00;	   //输出段选
 	setPA3();		  
 	delayus(50);			  
 	clearPA3();	    
 	
 	PORTB=0xFF;	   //输出位选
 	setPA4();		   
 	delayus(50);				   
 	clearPA4();	   
	
	PORTD=0xFF;
	setPA7();
	delayus(50);
	clearPA7();	
}
