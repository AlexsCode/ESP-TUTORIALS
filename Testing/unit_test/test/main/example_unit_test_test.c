/**
 * @file example_unit_test_test.c
 * @author Alex Tuddenham   
 * @brief Unit Test Runner with Unity.
 * @version 0.1
 * @date 2021-02-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <string.h>
#include "unity.h"

static void print_banner(const char* text);

void app_main(void)
{

    print_banner("Running tests with [addition] tag");
    UNITY_BEGIN();
    unity_run_tests_by_tag("[addition]", false);
    UNITY_END();

    print_banner("Running all the registered tests");
    UNITY_BEGIN();
    unity_run_all_tests();
    UNITY_END();

    print_banner("Starting interactive test menu");
    /* This function will not return, and will be busy waiting for UART input
     */
    unity_run_menu();
}

static void print_banner(const char* text)
{
    printf("\n#### %s #####\n\n", text);
}

