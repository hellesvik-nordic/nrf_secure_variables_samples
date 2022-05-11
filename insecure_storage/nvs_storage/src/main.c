/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>
#include <device.h>
#include <fs/nvs.h>
#include <storage/flash_map.h>
#include <string.h>

//Label of which DeviceTree storage to use. 
#define DEVICE_LABEL storage
#define KEY_ID 1
#define KEY_SIZE 12

static struct nvs_fs nvs = {
    .sector_size = DT_PROP(DT_CHOSEN(zephyr_flash), erase_block_size), //Got this from samples/nfc/writable_ndef_msg
    .sector_count = 2, //Decided based on how much the application needs
    .offset = FLASH_AREA_OFFSET(DEVICE_LABEL),
};

void main(void)
{
    ssize_t ret = 0;
    const struct device *nvs_dev;
    uint8_t key[KEY_SIZE];

    printk("Start of NVS simple sample\n");


    nvs_dev = FLASH_AREA_DEVICE(DEVICE_LABEL);
    if(!device_is_ready(nvs_dev)){
        printk("Error: Device not ready\n");
        return; 
    }

    nvs_init(&nvs, nvs_dev->name);


    ret = nvs_read(&nvs, KEY_ID, key, sizeof(key));
    if(ret > 0){ // Key already in NVS
        printk("Key read from NVS: %s\n", key);
    }
    else{ // Key not in NVS
        strcpy(key,"password123");
        printk("Write key to NVS complete\n");
        nvs_write(&nvs, KEY_ID, key, sizeof(key));
    }
    printk("End of NVS simple sample\n");
}
