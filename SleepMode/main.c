// #include <stdio.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "driver/gpio.h"
// #include "sdkconfig.h"
// #include "esp_system.h"
// #include <inttypes.h>

/* Alex Tuddenham 2020*/
/**
 * @brief File with various codes in
 * @file main.c
 * @author Alex Tuddenham
 * @date 28-01-2021
 * 
 */

// #define BLINK_GPIO 2

// ///////////////////////////////
// // /**
// //  * @brief hello world printing task
// //  * 
// //  * @param pvParameter smart pointer that does something
// //  */
// void hello_world(void * pvParameter )
// {
//     while (1)
//     { 
//         printf("Hello world!\n"); 
//         vTaskDelay(1000 / portTICK_PERIOD_MS);
//     }
// }

// void blinky(void *pvParameter)
// {
//     while(1)
//     {
//         /**
//          * @brief sets gpio level
//          * @param 0 assigns which pin is being controlled.
//          * @param 1 assigns state to LOW.  
//          */
//         gpio_set_level(BLINK_GPIO,0);
//         vTaskDelay(1000/portTICK_RATE_MS);
//         /**
//          * @brief sets gipo to high
//          * @param 0 assigns which pin is being controlled.
//          * @param 1 assigns state to HIGH.
//          */
//         gpio_set_level(BLINK_GPIO,1);
//         vTaskDelay(1000/portTICK_RATE_MS);

        
//     }

// }


// void app_main(void)
// {
//     gpio_reset_pin(BLINK_GPIO);
//     gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);


//     xTaskCreate(&hello_world,"hello_task",2048,NULL,5,NULL);
//     xTaskCreate(&blinky,"blinky",512,NULL,5,NULL);    
// }


// // ////////////////////////////////////////////////
// /**
//  * @def defines task name
//  */
// const char *pcTask1 = "thingy to do 1\n";
// /**
//  * @def defines task 2 name
// */
// const char *pcTask2 = "thingy to do 2\n";

// /**
//  * @brief prints task names
//  * 
//  * @param parameter given char for task
//  */
// void vPrintFunction(void * parameter);

// /**
//  * @brief creates two freeRTOS tasks
//  * 
//  */
// void app_main()
// {
//     xTaskCreate(vPrintFunction,"print whatever",2048,(void *) pcTask1,1,NULL);
//     xTaskCreate(vPrintFunction,"print something else",2048,(void *) pcTask2,1,NULL);
// }
// /**
//  * @brief prints the name of the task then waits 1 sec
//  * 
//  * @param parameter task name being passed to function
//  */
// void vPrintFunction(void *parameter)
// {
//     char *pcTaskName;
//     pcTaskName  = (char *) parameter;
//     while(1)
//     {
//         printf("Parameter: %s",pcTaskName);
//         vTaskDelay(1000/portTICK_PERIOD_MS);
//     }

// }

// //////////////////////////////

// /**
//  * @brief stucture of data
//  * @return no return
//  * @arg GenericData_t is object/declaration of structure
//  *  
//  */
// typedef struct Data_t
// {
//     uint32_t ucData;
//     char id;
// } GenericData_t;

// /**
//  * @brief Reads structure and prints fields from structure
//  * 
//  * @param xStruct of data with fields id and ucData
//  */
// void genericStructPrint(void *xStruct)
// {
//     /**
//      * @brief saves structure passed in as new pointer data
//      */
//     GenericData_t * data = (GenericData_t *) xStruct;
//     /**
//      * @brief prints ucData via data pointer  
//      * 
//      */
//     printf("ucData:%"PRIu32 "\n",data->ucData);
//     printf("id: %c\n",data->id);
// }
// void app_main()
// {
//     /**
//      * @brief saving into structure with fields 100 and 'a'
//      */
//     GenericData_t data1 = {100,'a'};
//     GenericData_t data2 = {200,'z'};

//     /**
//      * @brief Calls function to print and passes structure with fields filled. 
//      */
//     genericStructPrint((void *) &data1);
//     genericStructPrint((void *) &data2);
// }

// /////////////////////////////////////

// /**
//  * @brief converts milliseconds to OSTicks
//  * 
//  * @param millis time millisecs 
//  * @return TickType_t datatype of ticks
//  */
// TickType_t pdMS_TO_TICKS(uint32_t millis);

// /**
//  * @brief converts 500ms to a delay of ticks 
//  */
// TickType_t xDelay500ms = pdMS_TO_TICKS(500);

// void vTaskDelay(TickType_t xTicksToDelay);

// /**
//  * @brief places task into blocked state for time period
//  * 
//  * @param pxPreviousWakeTime  standard wake time
//  * @param xTimeIncrement time added
//  */
// void vTaskDelayUntil(TickType_t *pxPreviousWakeTime, TickType_t xTimeIncrement);
// //


// //definitions
// #define BLINK_GPIO 2

// //constants used
// const char *pcTextForTask1 = "Task 1\n";
// const char *pcTextForTask2 = "Task 2\n";
// const TickType_t xDelay250ms = pdMS_TO_TICKS(250);

// //functions used
// void blink_task(void *pvParameters);
// void print_task(void *pvParameters);

// //DONE, Change the Project Name in Makefile
// //DONE, Test this with ESP32
// void app_main()
// {
//     xTaskCreate(&blink_task, "blink_task", configMINIMAL_STACK_SIZE, NULL, 5, NULL);

//     //Adding the Parameter here
//     xTaskCreate(&print_task, "print_task 1", 2048, (void *)pcTextForTask1, 5, NULL);
//     xTaskCreate(&print_task, "print_task 2", 2048, (void *)pcTextForTask2, 5, NULL);
// }

// void blink_task(void *pvParameters)
// {
//     /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
//        muxed to GPIO on reset already, but some default to other
//        functions and need to be switched to GPIO. Consult the
//        Technical Reference for a list of pads and their default
//        functions.)
//     */

// 	gpio_pad_select_gpio(BLINK_GPIO);
//     /* Set the GPIO as a push/pull output */
//     gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

//     while(1)
//     {
//         /* Blink off (output low) */
//         gpio_set_level(BLINK_GPIO, 0);
//         vTaskDelay(xDelay500ms);

//         /* Blink on (output high) */
//         gpio_set_level(BLINK_GPIO, 1);
//         vTaskDelay(xDelay500ms);
//     }

//     vTaskDelete(NULL);
// }

// void print_task(void *pvParameters)
// {
// 	char *pcTaskName;
// 	pcTaskName = (char *)pvParameters;

// 	while(1)
// 	{
// 		printf("Parameter: %s", pcTaskName);
// 		vTaskDelay(xDelay250ms);
// 	}

// 	vTaskDelete(NULL);
// }


// #include <stdio.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "driver/gpio.h"
// #include "sdkconfig.h"

// //definitions used
// #define BLINK_GPIO 2

// //constants used
// const char *pcTextForTask1 = "Task 1\n";
// const char *pcTextForTask2 = "Task 2\n";
// const TickType_t xDelay250ms = pdMS_TO_TICKS(250);

// //functions used
// void blink_task(void *pvParameters);
// void print_task(void *pvParameters);

// //DONE, Change the Project Name in Makefile
// //DONE, Test this with ESP32
// void app_main()
// {
//     xTaskCreate(&blink_task, "blink_task", 1024, NULL, 5, NULL);

//     //Adding the Parameter here
//     xTaskCreate(&print_task, "print_task 1", 2048, (void *)pcTextForTask1, 5, NULL);
//     xTaskCreate(&print_task, "print_task 2", 2048, (void *)pcTextForTask2, 5, NULL);
// }

// void blink_task(void *pvParameters)
// {
//     /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
//        muxed to GPIO on reset already, but some default to other
//        functions and need to be switched to GPIO. Consult the
//        Technical Reference for a list of pads and their default
//        functions.)
//     */
//     gpio_pad_select_gpio(BLINK_GPIO);
//     /* Set the GPIO as a push/pull output */
//     gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

//     while(1)
//     {
//         /* Blink off (output low) */
//         gpio_set_level(BLINK_GPIO, 0);
//         vTaskDelay(xDelay250ms);
//         /* Blink on (output high) */
//         gpio_set_level(BLINK_GPIO, 1);
//         vTaskDelay(xDelay250ms);
//     }

//     vTaskDelete(NULL);
// }

// void print_task(void *pvParameters)
// {
// 	char *pcTaskName;
// 	TickType_t xLastWakeUpTime;
// 	pcTaskName = (char *)pvParameters;

// 	while(1)
// 	{
// 		printf("Parameter: %s", pcTaskName);
// 		//vTaskDelay(1000 / portTICK_PERIOD_MS);
// 		vTaskDelayUntil(&xLastWakeUpTime, (5*xDelay250ms));
// 	}

// // 	vTaskDelete(NULL);
// // }

// #include <stdio.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "driver/gpio.h"
// #include "sdkconfig.h"

// //definitions
// #define BLINK_GPIO 2

// //constants used
// const char *pcTextForTask1 = "Task 1\n";
// const char *pcTextForTask2 = "Task 2\n";
// const TickType_t xDelay250ms = pdMS_TO_TICKS(250);

// //variables that are used
// static uint32_t ulIdleCycleCount = 0UL;

// //functions used
// void blink_task(void *pvParameters);
// void print_task(void *pvParameters);
// void print_idle(void *pvParameters);

// //DONE, Change the Project Name in Makefile
// //DONE, Test this with ESP32
// void app_main()
// {
//     xTaskCreate(&blink_task, "blink_task", configMINIMAL_STACK_SIZE, NULL, 5, NULL);

//     //Adding the Parameter here
//     xTaskCreate(&print_task, "print_task 1", 2048, (void *)pcTextForTask1, 5, NULL);
//     //xTaskCreate(&print_idle, "print_task 2", 2048, (void *)pcTextForTask2, 5, NULL);
//     xTaskCreate(&print_idle, "idle_task 1", 2048, NULL, 5, NULL);
// }

// void blink_task(void *pvParameters)
// {
//     /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
//        muxed to GPIO on reset already, but some default to other
//        functions and need to be switched to GPIO. Consult the
//        Technical Reference for a list of pads and their default
//        functions.)
//     */
//     gpio_pad_select_gpio(BLINK_GPIO);
//     /* Set the GPIO as a push/pull output */
//     gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

//     while(1)
//     {
//         /* Blink off (output low) */
//         gpio_set_level(BLINK_GPIO, 0);
//         vTaskDelay(xDelay250ms);
//         /* Blink on (output high) */
//         gpio_set_level(BLINK_GPIO, 1);
//         vTaskDelay(xDelay250ms);
//     }

//     vTaskDelete(NULL);
// }

// void print_task(void *pvParameters)
// {
// 	char *pcTaskName;
// 	pcTaskName = (char *)pvParameters;

// 	while(1)
// 	{
// 		printf("Parameter: %s", pcTaskName);
// 		vTaskDelay(xDelay250ms);
// 	}

// 	vTaskDelete(NULL);
// }

// void print_idle(void *pvParameters)
// {
// 	while(1)
// 	{
// 		printf("IdleCount: %u\n", ulIdleCycleCount);

// 		vTaskDelay(xDelay250ms);
// 	}
// }

// void vApplicationIdleHook(void)
// {
// 	ulIdleCycleCount++;
// }

////////////////////////
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

//Definitions
#define BLINK_GPIO 2
#define INTR_GPIO 4
#define ESP_INTR_FLAG_DEFAULT 0

//Constants used
const TickType_t xDelay250ms = pdMS_TO_TICKS(250);
static int i=0;

//Functions Created
void gpio_output(void *pvParameters);
static void IRAM_ATTR interrupt_task(void *arg);

//DONE, Change the Project Name in Makefile
//DONE, Test this with ESP32
void app_main()
{
	gpio_config_t intrconfig;
	intrconfig.pin_bit_mask = (1 << INTR_GPIO);
	intrconfig.mode = GPIO_MODE_INPUT;
	intrconfig.pull_up_en = GPIO_PULLUP_ENABLE;
	intrconfig.pull_down_en = GPIO_PULLDOWN_DISABLE;
	intrconfig.intr_type = GPIO_PIN_INTR_POSEDGE;
	gpio_config(&intrconfig);

	gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
	gpio_isr_handler_add(INTR_GPIO, interrupt_task, NULL);

	xTaskCreate(&gpio_output, "blink_task", 2048, NULL, 5, NULL);
	while(1)
	{
		printf("What is it: %d\n", i);
		vTaskDelay(xDelay250ms);
	}

}

void gpio_output(void *pvParameters)
{
	gpio_config_t blinkconfig;
	blinkconfig.pin_bit_mask = (1 << BLINK_GPIO);
	blinkconfig.mode = GPIO_MODE_OUTPUT;
	blinkconfig.pull_up_en = GPIO_PULLUP_DISABLE;
	blinkconfig.pull_up_en = GPIO_PULLDOWN_DISABLE;
	blinkconfig.intr_type = GPIO_INTR_DISABLE;

	//Set the pin configs here
	gpio_config(&blinkconfig);


    while(1)
    {
        /* Blink off (output low) */
    	printf("Off\n");
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(xDelay250ms);

        /* Blink on (output high) */
        printf("On\n");
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(xDelay250ms);
    }

    vTaskDelete(NULL);
}

static void IRAM_ATTR interrupt_task(void * arg)
{
	i++;
}