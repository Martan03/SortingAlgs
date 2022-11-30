#include <stdio.h>

/// @brief Swaps two numbers
/// @param x first number
/// @param y second number
void Swap(double *x, double *y);

/// @brief Sorts double array using Bubble sort
/// @param nums double array
/// @param len length of the array
void BubbleSort(double *nums, int len);

/// @brief Sorts double array using Selection sort
/// @param nums double array
/// @param len length of the array
void SelectSort(double *nums, int len);

/// @brief Sorts double array using Insertion sort
/// @param nums double array
/// @param len length of the array
void InsertSort(double *nums, int len);

/// @brief Prints double array
/// @param nums double array
/// @param len length of the array
void PrintNums(double *nums, int len);

int main()
{
    double nums[] = { 10, 8, 2, 7, 4, 3, 6, 1, 9, 5 };
    int len = 10;
    //BubbleSort(nums, len);
    //SelectSort(nums, len);
    InsertSort(nums, len);
    PrintNums(nums, len);
}

void Swap(double *x, double *y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(double *nums, int len)
{
    for (int i = 0; i < len; ++i)
        for (int j = i + 1; j < len; ++j)
            if (nums[i] > nums[j])
                Swap(&nums[i], &nums[j]);
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
            Swap(&nums[i], &nums[min]);
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
            Swap(&nums[k + 1], &nums[k]);
    }
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
