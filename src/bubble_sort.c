#include "bubble_sort.h"

void bubble_sort(double *nums, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 1; j < len - i; ++j) {
            if (nums[j] < nums[j - 1])
                swap(&nums[j], &nums[j - 1]);
        }
    }
}

void coctail_sort(double *nums, int len) {
    bool swapped = true;
    int dir[2] = {1, -1};
    int start[2] = {1, len - 1};
    bool back = false;

    for (int i = 0; i < len && swapped; ++i) {
        swapped = false;
        for (int j = start[back]; j < len && j > 0; j += dir[back]) {
            if (nums[j - 1] > nums[j]) {
                swap(&nums[j], &nums[j - 1]);
                swapped = true;
            }
        }
        back = !back;
    }
}
