#include <limits.h>
#include "unity.h"
#include "testable.h"

/**
 * @author Alex Tuddenham
 * @date 03-02-2020
 * @file test_addition.c
 * @brief Test cases for a Calculator.
 */

/**
 * @brief testing whole int added together via addition function
 * 
 */
TEST_CASE("testing basic addition","[addition]")
{
    const int a = 5;
    const int b = 5;
    TEST_ASSERT_EQUAL(10,testable_addition(a,b));
}

TEST_CASE("testing Addition of non-zero and zero values","[addition]")
{
    const int a = 5;
    const int b = 0;
    TEST_ASSERT_EQUAL(5,testable_addition(a,b));
}
