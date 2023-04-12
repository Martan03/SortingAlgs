# C Sorting Algorithms

## Bubble sort
Bubble sort like algorithms:
```C
void bubble_sort(double* nums, int len);
void bubble_sort_optimised(double* nums, int len);
void bubble_sort_improved(double* nums, int len);
void bubble_sort_recursive(double* nums, int len);
void coctail_sort(double* nums, int len);
```

## Selection sort
```C
void select_sort(double* nums, int len);
```

## Insertion sort
```C
void insert_sort(double* nums, int len);
```

## Quick sort
```C
void quick_sort(double* nums, int len);
```

## Merge sort
```C
void merge_sort(double* nums, int len);
```

# Testing
I wanted to find out, how much time it takes each algorithm to sort an array,
so I tested it. Each algorithm sorts ascending array, descending array and
array with random numbers.

Bubble sort algorithms take a while, so I tested them with only 100.000 numbers.
There are the results:  
![image](https://user-images.githubusercontent.com/46300167/229298216-5839b0bb-8d39-455c-a854-8597b94aa09d.png)


Then I tested all other algorithms, this time with 1.000.000 numbers:  
![image](https://user-images.githubusercontent.com/46300167/229298302-0e3cb04e-f37f-4c0e-9eb9-8ebdfdafd15e.png)

## Links

- **Author:** [Martan03](https://github.com/Martan03)
- **GitHub repository:** [SortingAlgs](https://github.com/Martan03/SortingAlgs)
- **Author website:** [martan03.github.io](https://martan03.github.io)
