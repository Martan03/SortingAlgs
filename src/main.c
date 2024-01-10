#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

#define DG "\x1b[92m"
#define DW "\x1b[97m"
#define DBB "\x1b[38;2;70;70;70m"
#define DRS "\x1b[0m"

/// @brief Generates array with ascending numbers
/// @param len length of desired array
/// @return generated array
double* asc_nums(int len);

/// @brief Generates array with descending numbers
/// @param len length of desired array
/// @return generated array
double* desc_nums(int len);

/// @brief Generates array with random numbers
/// @param len length of desired array
/// @param t time to make randomization based on
/// @return generated array
double* random_nums(int len);

/// @brief Tests sort algorithm
/// @param sort sort function
/// @param t time to base randomization on
/// @param len length of the array to be generated
void test_sort(void (*sort)(double* nums, int len), time_t t, int len);

/// @brief Helper function for test_sort
/// @param sort sort function
/// @param nums array to be sorted
/// @param len length of the array
void _test_sort(void (*sort)(double* nums, int len), double* nums, int len);

/// @brief Tests C qsort algorithm
/// @param t time to base randomization on
/// @param len length of the array to be generated
void test_qsort(time_t t, int len);

/// @brief Helper function for test_qsort
/// @param nums array to be sorted
/// @param len length of the array
void _test_qsort(double* nums, int len);

/// @brief Compares two numbers
/// @param a number
/// @param b number
/// @return 1 if a is greater, 0 if numbers are equal, -1 if a is less
int compare(const void* a, const void* b);

int main() {
    time_t t;
    time(&t);

    int len = 100000;

    printf(DG "Bubble sort:\n" DRS);
    test_sort(&bubble_sort, t, len);
    printf(DG "Bubble Sort optimised:\n" DRS);
    test_sort(&bubble_sort_optimised, t, len);
    printf(DG "Bubble Sort improved:\n" DRS);
    test_sort(&bubble_sort_improved, t, len);
    printf(DG "Bubble Sort recursive:\n" DRS);
    test_sort(&bubble_sort_recursive, t, len);
    printf(DG "Coctail Sort:\n" DRS);
    test_sort(&coctail_sort, t, len);

    len = 1000000;

    printf(DG "Select sort:\n" DRS);
    test_sort(&select_sort, t, len);

    printf(DG "Insert sort:\n" DRS);
    test_sort(&insert_sort, t, len);

    printf(DG "Quick sort:\n" DRS);
    test_sort(&quick_sort, t, len);

    printf(DG "Merge sort:\n" DRS);
    test_sort(&merge_sort, t, len);

    printf(DG "C qsort:\n" DRS);
    test_qsort(t, len);

    return 0;
}

//======================<Sort testing>=====================

void test_sort(void (*sort)(double* nums, int len), time_t t, int len) {
    srand(t);

    printf(DW "  %-18s" DRS, "Ascending array: ");
    _test_sort(sort, asc_nums(len), len);
    printf(DW "  %-18s" DRS, "Descending array: ");
    _test_sort(sort, desc_nums(len), len);
    printf(DW "  %-18s" DRS, "Random array: ");
    _test_sort(sort, random_nums(len), len);
}

void _test_sort(void (*sort)(double* nums, int len), double* nums, int len) {
    if (!nums)
        return;

    clock_t start = clock();
    (*sort)(nums, len);
    printf(
        DBB "time = " DRS "%.5f\n", (double)(clock() - start) / CLOCKS_PER_SEC
    );

    for (int i = 1; i < len; ++i) {
        if (nums[i - 1] > nums[i]) {
            printf("Not sorted\n");
            break;
        }
    }

    free(nums);
}

void test_qsort(time_t t, int len) {
    srand(t);

    printf(DW "  %-18s" DRS, "Ascending array: ");
    _test_qsort(asc_nums(len), len);
    printf(DW "  %-18s" DRS, "Descending array: ");
    _test_qsort(desc_nums(len), len);
    printf(DW "  %-18s" DRS, "Random array: ");
    _test_qsort(random_nums(len), len);
}

void _test_qsort(double* nums, int len) {
    if (!nums)
        return;

    clock_t start = clock();
    qsort(nums, len, sizeof(double), compare);
    printf(
        DBB "time = " DRS "%.5f\n", (double)(clock() - start) / CLOCKS_PER_SEC
    );

    free(nums);
}

//====================<Array generating>===================

double* asc_nums(int len) {
    double* nums = malloc(sizeof(double) * len);
    if (!nums)
        return NULL;

    for (int i = 0; i < len; ++i)
        nums[i] = i + 1;

    return nums;
}

double* desc_nums(int len) {
    double* nums = malloc(sizeof(double) * len);
    if (!nums)
        return NULL;

    for (int i = 0; i < len; ++i)
        nums[i] = len - i;

    return nums;
}

double* random_nums(int len) {
    double* nums = malloc(sizeof(double) * len);
    if (!nums)
        return NULL;

    for (int i = 0; i < len; ++i)
        nums[i] = rand();

    return nums;
}

//================<Help function for qsort>================

int compare(const void* a, const void* b) {
    double da = *((double*) a);
    double db = *((double*) b);

    return (da > db) - (db > da);
}
