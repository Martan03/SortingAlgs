#ifndef HELPER_INCLUDED
#define HELPER_INCLUDED

#include <stdio.h>

/// @brief Swaps two numbers
/// @param x first number
/// @param y second number
static inline void swap(double *x, double *y);

/// @brief Prints double array
/// @param nums double array
/// @param len length of the array
static inline void print_nums(double *nums, int len);

static inline void swap(double *x, double *y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

static inline void print_nums(double *nums, int len)
{
    for (int i = 0; i < len; ++i)
    {
        if (i)
            printf(", ");
        printf("%lf", nums[i]);
    }
    printf("\n");
}

#endif // HELPER_INCLUDED
