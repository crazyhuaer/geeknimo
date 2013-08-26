#include "STC12C5A60S2.H"
#include "uart.h"
#include "intrins.h"

typedef unsigned char BYTE;
typedef unsigned int WORD;

BYTE ch = 3; //ADC channel NO.


void Delay_x(WORD n);


/*Define ADC operation const for ADC_CONTR*/
#define ADC_POWER 0x80 //ADC power control bit
#define ADC_FLAG 0x10 //ADC complete flag
#define ADC_START 0x08 //ADC start control bit
#define ADC_SPEEDLL 0x00 //540 clocks
#define ADC_SPEEDL 0x20 //360 clocks
#define ADC_SPEEDH 0x40 //180 clocks
#define ADC_SPEEDHH 0x60 //90 clocks

/*----------------------------
ADC interrupt service routine
----------------------------*/
//void adc_isr() interrupt 5 using 1
//{
//	ADC_CONTR &= !ADC_FLAG; //Clear ADC interrupt flag
////	SendData(ch); //Show Channel NO.
////	SendData(ADC_RES); //Get ADC high 8-bit result and Send to UART
//	//if you want show 10-bit result, uncomment next line
//	// SendData(ADC_LOW2); //Show ADC low 2-bit result
////	if (++ch > 7) ch = 0; //switch to next channel
//	adc_val = (WORD)ADC_RES<<2 + (ADC_RESL)>>6;
//	ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ADC_START | ch;
//
//	xlog("isr");
//}

/*----------------------------
Initial ADC sfr
----------------------------*/
void InitADC( )
{
	P1ASF = (1<<ch); //P13×÷ÎªADCÊäÈë
	ADC_RES = 0; //Clear previous result
	ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ADC_START | ch;
//	EADC = 1;
	Delay_x(2); //ADC power-on delay and Start A/D conversion
	while(ADC_CONTR & ADC_FLAG == 0);
	ADC_CONTR &= ~ADC_FLAG;
}

unsigned short get_adc_val(void)
{
	unsigned short ret = 0;

	ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ADC_START | ch;
	_nop_(); _nop_();_nop_();_nop_();_nop_();_nop_();
	while(ADC_CONTR & ADC_FLAG == 0);
	ret = (WORD)ADC_RES<<2 | ADC_RESL&0x03;
	ADC_CONTR &= ~ADC_FLAG;
	return ret;
}

/*----------------------------
Software delay function
----------------------------*/
void Delay_x(WORD n)
{
	WORD x;
	while (n--)
	{
		x = 5000;
		while (x--);
	}
}