#include "sort.h"

/**
 * hoare_partition - Partition the array using Hoare partition scheme.
 * @array: The array to be sorted.
 * @low: The starting index.
 * @high: The ending index.
 * @size: Size of the array.
 * Return: The correct position of the pivot.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;
    int temp;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
        else
            return (j);
    }
}

/**
 * quicksort_hoare - Implement the quicksort algorithm using Hoare partition.
 * @array: The array to be sorted.
 * @low: The starting index.
 * @high: The ending index.
 * @size: Size of the array.
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);
        quicksort_hoare(array, low, pivot, size);
        quicksort_hoare(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Call the quicksort function to sort the entire array.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1, size);
}
