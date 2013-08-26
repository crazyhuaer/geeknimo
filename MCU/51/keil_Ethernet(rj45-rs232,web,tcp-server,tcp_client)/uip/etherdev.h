#ifndef ETHERDEV_H
#define ETHERDEV_H
#include "STC12C5A60S2.H"
#include "uip.h"

// Change ETH_CPU_XTAL to match hardware

#define ETH_CPU_XTAL     11059200             // 8051 crystal freq in Hz
//#define ETH_CPU_XTAL       22118400


#define ETH_DATA_PORT P0     // Adjust this to suit hardware.
#define ETH_ADDR_PORT P2     // Adjust this to suit hardware.
#define ETH_CTRL_PORT P3     // Adjust this to suit hardware.
sbit ETH_RST_PIN = ETH_CTRL_PORT^5;	//rst pin 	
sbit IOW = ETH_CTRL_PORT^6;  // ISA slot pin B13, RTL8019AS pin 30, active low
sbit IOR = ETH_CTRL_PORT^7;  // ISA slot pin B14, RTL8019AS pin 29, active low


void etherdev_init(void);
void etherdev_send(void);
unsigned int etherdev_read(void);
void Delay_Ms(unsigned int t1);


#endif