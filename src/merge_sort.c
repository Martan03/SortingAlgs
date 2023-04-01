#include "sorts.h"

// Merge sort help function (this sorts :) )
void _merge_sort(double* nums, int left, int right);

void merge_sort(double* nums, int len) {
    if (len <= 0)
        return;
    _merge_sort(nums, 0, len - 1);
}

void _merge_sort(double* nums, int left, int right) {
    if (left >= right)
        return;
    
    int mid = (left + right) / 2;
    _merge_sort(nums, left, mid);
    _merge_sort(nums, mid + 1, right);

    int len = right - left + 1;
    double temp[len];
    int l, r, k;
    for (l = left, r = mid + 1, k = 0; k < len && l <= mid && r <= right; ++k)
    {
        if (nums[l] < nums[r])
            temp[k] = nums[l++];
        else
            temp[k] = nums[r++];
    }

    for (; l <= mid; ++l)
        temp[k++] = nums[l];

    for (; r <= right; ++r)
        temp[k++] = nums[r];

    for (int i = 0; i < len; ++i)
        nums[left + i] = temp[i];
    
    return;
}
