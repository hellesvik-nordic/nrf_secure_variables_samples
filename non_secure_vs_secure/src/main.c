/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>
#include <device.h>
#include <drivers/pwm.h>

void set_pwm_pin_dim(const struct device *pwm, uint8_t pin_num){
	uint32_t max_period = 10000;
	uint32_t period = 500;
	const uint8_t flags = 0;

	pwm_pin_set_usec(pwm, pin_num, max_period, period,flags);
}



void main(void)
{
	printk("Start of Non-secure vs Secure example\n");
	printk("Hello World! %s\n", CONFIG_BOARD);
	
	const struct device *pwm0;
    pwm0 = device_get_binding(DT_LABEL(DT_NODELABEL(pwm0)));
	set_pwm_pin_dim(pwm0,2);	

	const struct device *pwm1;
    pwm1 = device_get_binding(DT_LABEL(DT_NODELABEL(pwm1)));
	set_pwm_pin_dim(pwm1,3);	

	printk("End of Non-secure vs Secure example\n");
}
