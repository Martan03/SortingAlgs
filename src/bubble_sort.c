#include "sorts.h"

/// @brief Helper function for recursive Bubble sort
/// @param nums double array
/// @param len length of the array
void _bubble_sort_recursive(double *nums, int len);

void bubble_sort(double *nums, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 1; j < len - i; ++j) {
            if (nums[j] < nums[j - 1])
                swap(&nums[j], &nums[j - 1]);
        }
    }
}

void bubble_sort_improved(double *nums, int len) {
    for (int i = len, last = 1; i > 1; i = last, last = 1) {
        for (int j = 1; j < i; ++j) {
            if (nums[j] < nums[j - 1]) {
                swap(&nums[j], &nums[j - 1]);
                last = j;
            }
        }
    }
}

void bubble_sort_recursive(double *nums, int len) {
    if (len <= 1)
        return;

    _bubble_sort_recursive(nums, len);
    bubble_sort_recursive(nums, --len);
}

void _bubble_sort_recursive(double *nums, int len) {
    if (len <= 1)
        return;

    if (*nums > nums[1])
        swap(nums, &nums[1]);
    
    _bubble_sort_recursive(++nums, --len);
}

void coctail_sort(double *nums, int len) {
    int dir[2] = {1, -1};
    int start[2] = {1, len - 1};
    bool back = false;

    for (int i = 0; i < len; ++i) {
        for (int j = start[back]; j < len && j > 0; j += dir[back]) {
            if (nums[j - 1] > nums[j])
                swap(&nums[j], &nums[j - 1]);
        }
        back = !back;
    }
}
