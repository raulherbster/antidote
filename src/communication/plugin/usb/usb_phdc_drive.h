/**
 * \file usb_phdc_drive.h
 * \brief Functions to read/write data to USB PHDC compatible devices
 *
 * Copyright (C) 2011 Signove Tecnologia Corporation.
 * All rights reserved.
 * Contact: Signove Tecnologia Corporation (contact@signove.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation and appearing
 * in the file LICENSE included in the packaging of this file; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * \date Aug 31, 2011
 * \author Jose Luis do Nascimento
 */

#ifndef USB_PHDC_DRIVE_
#define USB_PHDC_DRIVE_

#include <libusb-1.0/libusb.h>
#include <poll.h>

typedef struct usb_phdc_device {

	libusb_device *usb_device;
	libusb_device_handle *usb_device_handle;
	libusb_context *usb_device_context;
	struct libusb_transfer *read_transfer;
	struct libusb_transfer *write_transfer;

	unsigned char *buffer_in;
	unsigned char *buffer_out;

	uint8_t ep_bulk_in;
	uint8_t ep_bulk_out;
	uint8_t ep_interrupt_in;
	int health_interface;

	uint16_t vendor_id;
	uint16_t product_id;

	struct pollfd *file_descriptors;
	nfds_t file_descriptors_count;

	char *manufacturer;
	char *name;
	char *serial_number;

	int *specializations;
	int number_of_specializations;

	void (*data_read_cb)(unsigned char* buffer, int size);
	void (*device_removed_cb)(int fd, void *user_data);

} usb_phdc_device;

typedef struct usb_phdc_context {
	libusb_context *usb_context;
	usb_phdc_device *device_list;
	int number_of_devices;
} usb_phdc_context;

int init_phdc_usb_plugin(usb_phdc_context *phdc_context);

void search_phdc_devices(usb_phdc_context *phdc_context);

void listen_for_incoming_data(usb_phdc_device *phdc_device);

void read_incoming_data(usb_phdc_device *phdc_device);

int send_apdu_stream(usb_phdc_device *phdc_device, unsigned char *data, int len);

int open_phdc_handle(usb_phdc_device *phdc_device);

void release_phdc_resources(usb_phdc_context *phdc_context);

void print_phdc_info(usb_phdc_device *phdc_device);

int poll_phdc_device(usb_phdc_device *phdc_device);

#endif /*USB_PHDC_DRIVE_*/