/*
* libusb example program to list devices on the bus
* Copyright (C) 2007 Daniel Drake <dsd@gentoo.org>
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/
/*

#include "StdAfx.h"
#include <sys/types.h>

#include "libusb.h"

static void print_devs(libusb_device **devs)
{
	libusb_device *dev;
	int i = 0;
	
	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor");
			return;
		}
		
		printf("%04x:%04x (bus %d, device %d)\n",
			desc.idVendor, desc.idProduct,
			libusb_get_bus_number(dev), libusb_get_device_address(dev));
	}
}

int main(void)
{
	libusb_device **devs;
	int r;
	ssize_t cnt;
	
	r = libusb_init(NULL);
	if (r < 0)
		return r;
	
	cnt = libusb_get_device_list(NULL, &devs);
	if (cnt < 0)
		return (int) cnt;
	
	print_devs(devs);
	libusb_free_device_list(devs, 1);
	
	libusb_exit(NULL);
	return 0;
}

*/


#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libusb.h"

#define VERSION "0.1.0"
#define VENDOR_ID 0x0925
#define PRODUCT_ID 0x7001

// HID Class-Specific Requests values. See section 7.2 of the HID specifications
#define HID_GET_REPORT                0x01
#define HID_GET_IDLE                  0x02
#define HID_GET_PROTOCOL              0x03
#define HID_SET_REPORT                0x09
#define HID_SET_IDLE                  0x0A
#define HID_SET_PROTOCOL              0x0B
#define HID_REPORT_TYPE_INPUT         0x01
#define HID_REPORT_TYPE_OUTPUT        0x02
#define HID_REPORT_TYPE_FEATURE       0x03

#define CTRL_IN		LIBUSB_ENDPOINT_IN|LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE
#define CTRL_OUT	LIBUSB_ENDPOINT_OUT|LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE


const static int PACKET_CTRL_LEN=2; 
const static int PACKET_INT_LEN=2;
const static int INTERFACE=0;
const static int ENDPOINT_INT_IN=0x81; /* endpoint 0x81 address for IN */
const static int ENDPOINT_INT_OUT=0x01; /* endpoint 1 address for OUT */
const static int TIMEOUT=5000; /* timeout in ms */

void bad(const char *why) {
	fprintf(stderr,"Fatal error> %s\n",why);
	exit(17);
}

static struct libusb_device_handle *devh = NULL;

static int find_lvr_hidusb(void)
{
	devh = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, PRODUCT_ID);
	return devh ? 0 : -EIO;
}


static int test_control_transfer(void)
{
   	int r,i;
   	char answer[PACKET_CTRL_LEN-1];
   	char question[PACKET_CTRL_LEN-1];
   	for (i=0;i<PACKET_CTRL_LEN; i++) question[i]=0x20+i;

	r = libusb_control_transfer(devh,CTRL_OUT,HID_SET_REPORT,(HID_REPORT_TYPE_FEATURE<<8)|0x00, 0,question, PACKET_CTRL_LEN,TIMEOUT);
	if (r < 0) {
		fprintf(stderr, "Control Out error %d\n", r);
		return r;
	}
	r = libusb_control_transfer(devh,CTRL_IN,HID_GET_REPORT,(HID_REPORT_TYPE_FEATURE<<8)|0x00,0, answer,PACKET_CTRL_LEN, TIMEOUT);
	if (r < 0) {
		fprintf(stderr, "Control IN error %d\n", r);
		return r;
	}
	for(i = 0;i < PACKET_CTRL_LEN; i++) {
		if(i%8 == 0)
			printf("\n");
		printf("%02x, %02x; ",question[i],answer[i]);
	}
	printf("\n");

	return 0;
}

static int test_control_transfer_in_out(void)
{
   	int r,i;
   	char answer[PACKET_INT_LEN-1];
   	char question[PACKET_INT_LEN-1];
   	for (i=0;i<PACKET_INT_LEN; i++) question[i]=0x30+i;
   	for (i=1;i<PACKET_INT_LEN; i++) answer[i]=0;

	r = libusb_control_transfer(devh,CTRL_OUT,HID_SET_REPORT,(HID_REPORT_TYPE_OUTPUT<<8)|0x00, 0,question, PACKET_INT_LEN,TIMEOUT);
	if (r < 0) {
		fprintf(stderr, "Control Out error %d\n", r);
		return r;
	}
	r = libusb_control_transfer(devh,CTRL_IN,HID_GET_REPORT,(HID_REPORT_TYPE_INPUT<<8)|0x00, 0, answer,PACKET_INT_LEN, TIMEOUT);
	if (r < 0) {
		fprintf(stderr, "Control IN error %d\n", r);
		return r;
	}
	for(i = 0;i < PACKET_INT_LEN; i++) {
		if(i%8 == 0)
			printf("\n");
		printf("%02x, %02x; ",question[i],answer[i]);
	}
	printf("\n");

	return 0;
}


static int test_interrupt_transfer(void)
{
   	int r,i;
	int transferred;
   	char answer[PACKET_INT_LEN-1];
   	char question[PACKET_INT_LEN-1];
   	for (i=0;i<PACKET_INT_LEN; i++) question[i]=0x40+i;

	r = libusb_interrupt_transfer(devh, ENDPOINT_INT_OUT, question, PACKET_INT_LEN,
		&transferred,TIMEOUT);
	if (r < 0) {
		fprintf(stderr, "Interrupt write error %d\n", r);
		return r;
	}
	r = libusb_interrupt_transfer(devh, ENDPOINT_INT_IN, answer,PACKET_INT_LEN,
		&transferred, TIMEOUT);
	if (r < 0) {
		fprintf(stderr, "Interrupt read error %d\n", r);
		return r;
	}
	if (transferred < PACKET_INT_LEN) {
		fprintf(stderr, "Interrupt transfer short read (%d)\n", r);
		return -1;
	}

	for(i = 0;i < PACKET_INT_LEN; i++) {
		if(i%8 == 0)
			printf("\n");
		printf("%02x, %02x; ",question[i],answer[i]);
	}
	printf("\n");

	return 0;
}

int main(void)
{
	int r = 1;

	r = libusb_init(NULL);
	if (r < 0) {
		fprintf(stderr, "Failed to initialise libusb\n");
		exit(1);
	}

	r = find_lvr_hidusb();
	if (r < 0) {
		fprintf(stderr, "Could not find/open LVR Generic HID device\n");
		goto out;
	}
	printf("Successfully find the LVR Generic HID device\n");

#ifdef LINUX
 	libusb_detach_kernel_driver(devh, 0); 	
#endif

	r = libusb_set_configuration(devh, 1);
	if (r < 0) {
		fprintf(stderr, "libusb_set_configuration error %d\n", r);
		goto out;
	}
	printf("Successfully set usb configuration 1\n");
	r = libusb_claim_interface(devh, 0);
	if (r < 0) {
		fprintf(stderr, "libusb_claim_interface error %d\n", r);
		goto out;
	}
	printf("Successfully claimed interface\n");

	printf("Testing control transfer using loop back test of feature report");
	test_control_transfer();

	printf("Testing control transfer using loop back test of input/output report");
	test_control_transfer_in_out();
	
	printf("Testing interrupt transfer using loop back test of input/output report");
	test_interrupt_transfer();

	printf("\n");

	libusb_release_interface(devh, 0);
out:
//	libusb_reset_device(devh);
	libusb_close(devh);
	libusb_exit(NULL);
	return r >= 0 ? r : -r;
}


