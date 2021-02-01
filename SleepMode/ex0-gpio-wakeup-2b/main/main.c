/**
 * @brief GPIO wakeup example from deep sleep
 * @file main.c 
 * @author Alex Tuddenham
 * @date 01-02-2021
 * @example - 2.B
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "esp_system.h"
#include "esp_sleep.h"
#include "driver/gpio.h"
/**
 * Added freertos libraries.
 */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * Added Macro HIGH to assign 1
 */
#define HIGH 1

uint8_t wake_pin = GPIO_NUM_33;

/**
 * @brief Function configures wakeup conditions and sends to sleep
 * @param pvParameter passed parameters used to edit conditions from freeRTOS task
 */
void sleepingFunction(void * pvParameter)
{
	esp_sleep_enable_ext0_wakeup((gpio_num_t)wake_pin,HIGH);
	esp_deep_sleep_start();
}


/**
 * @brief Cleaner GPIO wake example, executing freeRTOS tasks.
 */
void app_main()
{
	/**
	 * @brief Creates freeRTOS task for calling sleeping function
	 * @param 1 - Reference to sleeping function.
	 * @param 2 - Task name.
	 * @param 3 - Stack allocation of memory.
	 * @param 4 - Parameters to pass onto the function, NULL as non required.
	 * @param 5 - Priority, Only relevant when running several tasks at once.
	 * @param 6 - Task Handler, Only relevant when running several tasks.
	 */
	xTaskCreate(&sleepingFunction,"sending to sleep", 2048,NULL,5,NULL);
}