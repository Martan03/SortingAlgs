#ifndef SORTS_INCLUDED
#define SORTS_INCLUDED

#include <stdbool.h>
#include <stdio.h>

//====================<HELP FUNCTIONS>=====================

/// @brief Swaps two numbers
/// @param x first number
/// @param y second number
static inline void swap(double* x, double* y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

/// @brief Prints double array
/// @param nums double array
/// @param len length of the array
static inline void print_nums(double* nums, int len)
{
    for (int i = 0; i < len; ++i)
    {
        if (i)
            printf(", ");
        printf("%lf", nums[i]);
    }
    printf("\n");
}

//======================<BUBBLE SORT>======================

/// @brief Sorts double array using Bubble sort
/// @param nums double array
/// @param len length of the array
void bubble_sort(double* nums, int len);

/// @brief Sorts double array using optimised Bubble sort
/// Added detection if swap occured, if not, ends sorting
/// @param nums 
/// @param len 
void bubble_sort_optimised(double* nums, int len);

/// @brief Sorts double array using improved Bubble sort
/// Added detection of last swap
/// @param nums double array
/// @param len length of the array
void bubble_sort_improved(double* nums, int len);

/// @brief Sorts double array using recursive Bubble sort
/// @param nums double array
/// @param len length of the array
void bubble_sort_recursive(double* nums, int len);

/// @brief Sorts double array using Coctail sort
/// Similiar to Bubble sort, looping array one way and then back
/// @param nums double array
/// @param len length of the array
void coctail_sort(double* nums, int len);

//======================<SELECT SORT>======================

/// @brief Sorts double array using Selection sort
/// @param nums double array
/// @param len length of the array
void select_sort(double* nums, int len);

//======================<INSERT SORT>======================

/// @brief Sorts double array using Insertion sort
/// @param nums double array
/// @param len length of the array
void insert_sort(double* nums, int len);

//======================<MERGE SORT>=======================

/// @brief Sorts double array using Merge sort
/// @param nums double array
/// @param len length of the array
void merge_sort(double* nums, int len);

#endif // SORTS_INCLUDED
