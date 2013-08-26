#include "main.h"
#include "adc.h"

sbit LED1 = P1^7;
sbit LED2 = P1^6;

u8 client_connect_flag = 0;
u8 loop_cnt = 1;
u8 i, arptimer;

void main(void)
{ 
	uart_init();
	InitADC(); 
	buffer_Init();

	for(i=0; i<20; i++) xlog("\r\n");	//clear screen

    /* Initialise the uIP TCP/IP stack. */
    uip_init();

    /* Initialise the device driver. */ 
    etherdev_init();

    /* Initialise the ARP cache. */
    uip_arp_init();
	
	
	/*Initialise listen port */
	listen_init(); 

	EA=1;
	xlog("init ok\r\n");


    arptimer = 0;

    while(1)
    {
		if((client_connect_flag == 0) && (loop_cnt++%15 == 0))
		{
			u16_t ipaddr[2];
			struct uip_conn *pcon = NULL;	 

			uip_ipaddr(ipaddr,192,168,1,2);
			pcon = uip_connect(ipaddr,HTONS(8888));
			client_connect_flag = 1;

			xlog("sync ");
		}

        uip_len = etherdev_read();

        if(uip_len == 0)
        {
            for(i = 0; i < UIP_CONNS; i++)
            {
                uip_periodic(i);
                /* If the above function invocation resulted in data that
                   should be sent out on the network, the global variable
                   uip_len is set to a value > 0. */
                if(uip_len > 0)
                {
                    uip_arp_out();
                    etherdev_send();
                }
            }

            /* Call the ARP timer function every 10 seconds. */
            if(++arptimer == 20)
            {	
	            uip_arp_timer();
	            arptimer = 0;
            }
        }
        else /* (uip_len != 0) Process incoming */
        {
            if(BUF->type == htons(UIP_ETHTYPE_IP))
            {
	            uip_arp_ipin();
	            uip_input();
	            /* If the above function invocation resulted in data that
	               should be sent out on the network, the global variable
	               uip_len is set to a value > 0. */
	            if(uip_len > 0)
                {
	                uip_arp_out();
	                etherdev_send();
	            }
            }
            else if(BUF->type == htons(UIP_ETHTYPE_ARP))
            {
	            uip_arp_arpin();
	            /* If the above function invocation resulted in data that
	               should be sent out on the network, the global variable
	               uip_len is set to a value > 0. */	
	            if(uip_len > 0)
                {	
	                etherdev_send();
	            }
            }
        }	
    }//while(1)
    return;
}

