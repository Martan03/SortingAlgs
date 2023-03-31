#ifndef HELPER_INCLUDED
#define HELPER_INCLUDED

/// @brief Swaps two numbers
/// @param x first number
/// @param y second number
static inline void swap(double *x, double *y);

static inline void swap(double *x, double *y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

#endif // HELPER_INCLUDED
