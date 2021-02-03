/**
 * @file addition.c
 * @author Alex Tuddenham
 * @brief Component test for Addition, including full method definitions
 * @version 0.1
 * @date 2021-02-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "testable.h"

int testable_addition(const int a, const int b)
{
   return (a + b);
}


int testable_further_addition(const int a,float b)
{
   //conversion float to int.
   b = (int)b; 
   return (a + b);
}