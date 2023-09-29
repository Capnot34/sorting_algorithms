#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Order a subset of an array of integers according to
 *                   the hoare partition scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 * @low: The index to start at.
 * @high: The index to end at.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot, i, j;

    pivot = array[high];
    i = low - 1;
    j = high + 1;
    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);
        do {
            j--;
        } while (array[j] > pivot);

        if (i < j)
        {
            swap_ints(&array[i], &array[j]);
            print_array(array, size);
        }
        else
            return (j);
    }
}

/**
 * quicksort_h - Sorts an array of integers in ascending order using
 *               the quicksort algorithm with the hoare partition scheme.
 * @array: An array of integers.
 * @size: Size of the array.
 * @low: The index to start sorting from.
 * @high: The index to stop sorting to.
 */
void quicksort_h(int *array, size_t size, int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = hoare_partition(array, size, low, high);
        quicksort_h(array, size, low, pivot);
        quicksort_h(array, size, pivot + 1, high);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the quicksort algorithm with the hoare partition scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quicksort_h(array, size, 0, size - 1);
}
