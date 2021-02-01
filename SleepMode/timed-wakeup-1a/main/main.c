/**
 * @brief timed wakeup example from deep sleep
 * @file main.c
 * @author Alex Tuddenham
 * @date 01-02-2021
 * @example 1.A
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "esp_system.h"
#include "esp_sleep.h"

/**
 * @brief simplest timer wakeup
 * 
 */
void app_main()
{
	/**
	 * @brief wakeup condition
	 * @param 1 time in microseconds
	 */
	esp_sleep_enable_timer_wakeup(2000000);
	esp_deep_sleep_start();

}