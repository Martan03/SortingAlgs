#include "sorts.h"

void select_sort(double* nums, int len) {
    for (int min = 0, i = 0; i < len; ++i, min = i)
    {
        for (int j = i + 1; j < len; ++j)
            if (nums[min] > nums[j])
                min = j;

        if (min != i)
            swap(&nums[i], &nums[min]);
    }
}
