#include "sorts.h"

/// @brief Helper function for quick_sort
/// @param nums double array
/// @param low lower limit
/// @param high upper limit
void _quick_sort(double* nums, int low, int high);

/// @brief Partitions the array using middle element as pivot
/// @param nums double array
/// @param low lower limit
/// @param high upper limit
/// @return partition
int partition(double* nums, int low, int high);

void quick_sort(double* nums, int len) {
    _quick_sort(nums, 0, len - 1);
}

void _quick_sort(double* nums, int low, int high) {
    if (low < high) {
        int p = partition(nums, low, high);
        _quick_sort(nums, low, p);
        _quick_sort(nums, p + 1, high);
    }
}

int partition(double* nums, int low, int high) {
    int pivot = nums[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    for (;;) {
        for (; nums[++i] < pivot;);
        for (; nums[--j] > pivot;);

        if (i >= j)
            return j;
        
        swap(&nums[i], &nums[j]);
    }
}
