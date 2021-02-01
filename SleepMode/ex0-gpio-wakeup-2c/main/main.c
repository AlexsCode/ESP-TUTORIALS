/**
 * @brief GPIO wakeup example from deep sleep
 * @file main.c 
 * @author Alex Tuddenham
 * @date 01-02-2021
 * @example - 2.C
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "esp_system.h"
#include "esp_sleep.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define HIGH 1
uint8_t wake_pin = GPIO_NUM_33;

/**
 * @brief RTC memory location for counting times awoken from sleep
 */
RTC_DATA_ATTR int woken_up_number=0;

/**
 * @brief Function configures wakeup conditions and sends to sleep
 * @param pvParameter passed parameters used to edit conditions from freeRTOS task
 */
void sleepingFunction(void * pvParameter)
{
	esp_sleep_enable_ext0_wakeup((gpio_num_t)wake_pin,HIGH);
	/**
	 * @brief Adds a delay of a 1000 system ticks
	 */
	vTaskDelay(1000/portTICK_PERIOD_MS);
	esp_deep_sleep_start();
}


/**
 * @brief GPIO wake example using RTC memory between sleeps.
 */
void app_main()
{
	printf("System has awoken %d times",woken_up_number);
	woken_up_number++;
	// vTaskDelay(5000/portTICK_PERIOD_MS);
	/**
	 * @brief Creates freeRTOS task for calling sleeping function
	 * @param 1 - Reference to sleeping function.
	 * @param 2 - Task name.
	 * @param 3 - Stack allocation of memory.
	 * @param 4 - Parameters to pass onto the function, NULL as non required.
	 * @param 5 - Priority, Only relevant when running several tasks at once.
	 * @param 6 - Task Handler, Only relevant when running several tasks.
	 */
	if (woken_up_number==0){xTaskCreate(&sleepingFunction,"sending to sleep", 2048,NULL,5,NULL);}
	else{printf("System has awoken %d times",woken_up_number);
	woken_up_number++; }
}