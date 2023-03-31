#include "sorts.h"

void insert_sort(double *nums, int len)
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
