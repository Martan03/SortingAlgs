#include "sorts.h"

void insert_sort(double* nums, int len) {
    for (int j = 0, i = 1, k = nums[i]; i < len; ++i) {
        k = nums[i];
        for (j = i - 1; j >= 0 && nums[j] > k; --j)
            nums[j + 1] = nums[j];
        nums[j + 1] = k;
    }
}
