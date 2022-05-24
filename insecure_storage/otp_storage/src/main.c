/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>
#include <nrfx_nvmc.h>

#define OTP_STEP 4

#if CONFIG_SOC_NRF9160
// OTP registers from https://infocenter.nordicsemi.com/topic/ps_nrf9160/uicr.html
#define OTP_START 0x00FF8108
#define OTP_SIZE  0x2F4

#elif CONFIG_SOC_NRF5340_CPUAPP
// OTP registers from https://infocenter.nordicsemi.com/topic/ps_nrf5340/chapters/uicr/doc/uicr.html
#define OTP_START 0x00FF8100
#define OTP_SIZE  0x2FC

#else
#error("OTP not available on this MCU\N")
#endif

void main(void)
{

    uint16_t data;
    uint32_t address;
    uint8_t counter = 0;

    printk("OTP Simple sample\n");

    printk("Writing to halfword. Try to change data next time to see that you can not change which value is already written\n");
    data = 0x1234;
    address = OTP_START+OTP_STEP*7;
    nrfx_nvmc_halfword_write(address,data);

    printk("Read all OTP:\n");
    address = OTP_START;
    while(address <= OTP_START+OTP_SIZE){
        data = nrfx_nvmc_otp_halfword_read(address);
        printk("%x, ",data);
        address += OTP_STEP;
        if(!(++counter%8)){
            printk("\n");
        }
    }
    printk("\n");
}
