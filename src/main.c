#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

double* random_nums(int len, time_t t);

void test_sort(void (*sort)(double* nums, int len), time_t t, int len);

int main() {
    time_t t;
    time(&t);

    int len = 50000;

    printf("%30s", "Bubble sort: ");
    test_sort(&bubble_sort, t, len);

    printf("%30s", "Bubble Sort improved: ");
    test_sort(&bubble_sort_improved, t, len);

    printf("%30s", "Bubble Sort recursive: ");
    test_sort(&bubble_sort_recursive, t, len);

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
