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
        _quick_sort(nums, low, p - 1);
        _quick_sort(nums, p + 1, high);
    }
}

int partition(double* nums, int low, int high) {
    int pivot = nums[high];
    int i = low;

    for (int j = low; j < high; ++j) {
        if (nums[j] < pivot)
            swap(&nums[i++], &nums[j]);
    }

    swap(&nums[i], &nums[high]);
    return i;
}
