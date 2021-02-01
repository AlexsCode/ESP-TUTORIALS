/**
 * @brief GPIO wakeup example from deep sleep
 * @file main.c
 * @author Alex Tuddenham
 * @date 01-02-2021
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "esp_system.h"
#include "esp_sleep.h"
/**
 * Added header for gpio control.
 */
#include "driver/gpio.h"

/**
 * @brief simplest external interupt example
 * 
 */
void app_main()
{
	esp_sleep_enable_ext0_wakeup((gpio_num_t)GPIO_NUM_33,1);
	esp_deep_sleep_start();
}