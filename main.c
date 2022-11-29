#include <stdio.h>

/// @brief Swaps two numbers
/// @param x first number
/// @param y second number
void Swap(double *x, double *y);

/// @brief Sorts double array using Bubble sort
/// @param nums double array
/// @param len length of the array
void BubbleSort(double **nums, int len);

/// @brief Sorts double array using Selection sort
/// @param nums double array
/// @param len length of the array
void SelectSort(double **nums, int len);

/// @brief Prints double array
/// @param nums double array
/// @param len length of the array
void PrintNums(double *nums, int len);

int main()
{
    double n[] = { 10, 8, 2, 7, 4, 3, 6, 1, 9, 5 };
    double *nums = n;
    int len = 10;
    //BubbleSort(&nums, len);
    SelectSort(&nums, len);
    PrintNums(nums, len);
}

void Swap(double *x, double *y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(double **nums, int len)
{
    double *n = *nums;
    for (int i = 0; i < len; ++i)
        for (int j = i + 1; j < len; ++j)
            if (n[i] > n[j])
                Swap(&n[i], &n[j]);
}

void SelectSort(double **nums, int len)
{
    double *n = *nums;
    for (int min, i = 0; i < len; ++i)
    {
        min = i;
        for (int j = i + 1; j < len; ++j)
            if (n[min] > n[j])
                min = j;

        if (min != i)
            Swap(&n[i], &n[min]);
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
