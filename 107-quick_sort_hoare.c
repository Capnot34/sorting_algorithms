#include "sort.h"

void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    q_sort_hoare(array, 0, size - 1, size);
}

void q_sort_hoare(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);

        q_sort_hoare(array, low, pivot, size);
        q_sort_hoare(array, pivot + 1, high, size);
    }
}

int hoare_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[low];
    ssize_t i = low - 1;
    ssize_t j = high + 1;

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

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
