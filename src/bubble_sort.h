#ifndef BUBBLE_SORT_INCLUDED
#define BUBBLE_SORT_INCLUDED

#include <stdbool.h>
#include "helper.h"

/// @brief Sorts double array using Bubble sort
/// @param nums double array
/// @param len length of the array
void bubble_sort(double *nums, int len);

/// @brief Sorts double array using improved Bubble sort
/// Added detection of last swap
/// @param nums double array
/// @param len length of the array
void bubble_sort_improved(double *nums, int len);

/// @brief Sorts double array using recursive Bubble sort
/// @param nums double array
/// @param len length of the array
void bubble_sort_recursive(double *nums, int len);

/// @brief Sorts double array using Coctail sort
/// Similiar to Bubble sort, looping array one way and then back
/// @param nums double array
/// @param len length of the array
void coctail_sort(double *nums, int len);


#endif // BUBBLE_SORT_INCLUDED
