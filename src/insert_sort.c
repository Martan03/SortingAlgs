#include "sorts.h"

void insert_sort(double* nums, int len) {
    double k;
    for (int j, i = 1; i < len; ++i) {
        k = nums[i];
        for (j = i - 1; j >= 0 && nums[j] > k; --j)
            nums[j + 1] = nums[j];
        nums[j + 1] = k;
    }
}
