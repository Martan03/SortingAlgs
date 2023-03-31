#include <stdio.h>
#include "bubble_sort.h"
#include "helper.h"

/// @brief Sorts double array using Selection sort
/// @param nums double array
/// @param len length of the array
void SelectSort(double *nums, int len);

/// @brief Sorts double array using Insertion sort
/// @param nums double array
/// @param len length of the array
void InsertSort(double *nums, int len);

/// @brief Sorts double array using Merge sort
/// @param nums double array
/// @param len length of the array
void MergeSort(double *nums, int len);

// Merge sort help function (this sorts :) )
void _MergeSort(double *nums, int left, int right);

/// @brief Prints double array
/// @param nums double array
/// @param len length of the array
void PrintNums(double *nums, int len);

int main()
{
    double nums[] = { 10, 8, 2, 7, 4, 3, 6, 1, 9, 5 };
    int len = 10;
    bubble_sort_recursive(nums, len);
    //SelectSort(nums, len);
    //InsertSort(nums, len);
    //MergeSort(nums, len);
    PrintNums(nums, len);
}

void SelectSort(double *nums, int len)
{
    for (int min, i = 0; i < len; ++i)
    {
        min = i;
        for (int j = i + 1; j < len; ++j)
            if (nums[min] > nums[j])
                min = j;

        if (min != i)
            swap(&nums[i], &nums[min]);
    }
}

void InsertSort(double *nums, int len)
{
    for (int j, k, i = 0; i < len; ++i)
    {
        for (j = i + 1; j < len && nums[j - 1] < nums[j]; ++j);
        if (j == len)
            break;
        for (k = j - 1; k >= 0 && nums[k + 1] < nums[k]; --k)
            swap(&nums[k + 1], &nums[k]);
    }
}

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

void PrintNums(double *nums, int len)
{
    for (int i = 0; i < len; ++i)
    {
        if (i)
            printf(", ");
        printf("%lf", nums[i]);
    }
    printf("\n");
}
