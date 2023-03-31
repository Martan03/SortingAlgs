#include "sorts.h"

// Merge sort help function (this sorts :) )
void _MergeSort(double *nums, int left, int right);

void MergeSort(double *nums, int len)
{
    if (len <= 0)
        return;
    _MergeSort(nums, 0, len - 1);
}

void _MergeSort(double *nums, int left, int right)
{
    if (left >= right)
        return;
    
    int middle = (left + right) / 2;
    _MergeSort(nums, left, middle);
    _MergeSort(nums, middle + 1, right);

    int tempLen = right - left + 1;
    double temp[tempLen];
    int l, r, k;
    for (l = left, r = middle + 1, k = 0; k < tempLen && l <= middle && r <= right; ++k)
    {
        if (nums[l] < nums[r])
            temp[k] = nums[l++];
        else
            temp[k] = nums[r++];
    }

    for (; l <= middle; ++l)
        temp[k++] = nums[l];

    for (; r <= right; ++r)
        temp[k++] = nums[r];

    for (int i = 0; i < tempLen; ++i)
        nums[left + i] = temp[i];
    
    return;
}
