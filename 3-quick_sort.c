#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the Lomuto partition scheme (last element as pivot).
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot = array + right;
    int above = left, below;
    
    for (below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above < below)
            {
                swap_ints(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        swap_ints(array + above, pivot);
        print_array(array, size);
    }

    return above;
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    if (right - left > 0)
    {
        int part = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, part - 1);
        lomuto_sort(array, size, part + 1, right);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order using the quicksort algorithm.
 *              Uses the Lomuto partition scheme.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}
