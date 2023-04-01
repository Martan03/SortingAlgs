#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

/// @brief Generates array with random numbers
/// @param len length of array to be generated
/// @param t time to make randomization based on
/// @return generated array
double* random_nums(int len, time_t t);

/// @brief Tests sort algorithm
/// @param sort sort function
/// @param t time to base randomization on
/// @param len length of the array to be generated
void test_sort(void (*sort)(double* nums, int len), time_t t, int len);

/// @brief Tests C qsort algorithm
/// @param t time to base randomization on
/// @param len length of the array to be generated
void test_qsort(time_t t, int len);

/// @brief Compares two numbers
/// @param a number
/// @param b number
/// @return 1 if a is greater, 0 if numbers are equal, -1 if a is less
int compare(const void* a, const void* b);

int main() {
    time_t t;
    time(&t);

    int len = 100000;

    printf("%30s", "Bubble sort: ");
    test_sort(&bubble_sort, t, len);
    printf("%30s", "Bubble Sort optimised: ");
    test_sort(&bubble_sort_optimised, t, len);
    printf("%30s", "Bubble Sort improved: ");
    test_sort(&bubble_sort_improved, t, len);
    printf("%30s", "Bubble Sort recursive: ");
    test_sort(&bubble_sort_recursive, t, len);
    printf("%30s", "Coctail Sort: ");
    test_sort(&coctail_sort, t, len);

    printf("%30s", "Select sort: ");
    test_sort(&select_sort, t, len);

    printf("%30s", "Insert sort: ");
    test_sort(&insert_sort, t, len);

    printf("%30s", "Merge sort: ");
    test_sort(&merge_sort, t, len);

    printf("%30s", "C qsort: ");
    test_qsort(t, len);

    return 0;
}

double* random_nums(int len, time_t t) {
    double* nums = malloc(sizeof(double) * len);
    if (!nums)
        return NULL;
    
    for (int i = 0; i < len; ++i)
        nums[i] = rand();
    
    return nums;
}

void test_sort(void (*sort)(double* nums, int len), time_t t, int len) {
    srand(t);

    double* nums = random_nums(len, t);
    if (!nums)
        return;

    clock_t start = clock();
    (*sort)(nums, len);
    printf("time=%.3g\n", (double)(clock() - start) / CLOCKS_PER_SEC);

    free(nums);
}

void test_qsort(time_t t, int len) {
    srand(t);

    double* nums = random_nums(len, t);
    if (!nums)
        return;

    clock_t start = clock();
    qsort(nums, len, sizeof(double), compare);
    printf("time=%.3g\n", (double)(clock() - start) / CLOCKS_PER_SEC);

    free(nums);
}

int compare(const void* a, const void* b) {
    double da = *((double*) a);
    double db = *((double*) b);

    return (da > db) - (db > da);
}
