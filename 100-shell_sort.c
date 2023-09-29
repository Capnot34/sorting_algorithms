#include "sort.h"

/**
 * shell_sort - sorts an array of integers using shell sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (!array || size < 2)
        return;

    for (gap = size / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < size; i += 1)
        {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
        print_array(array, size);
    }
}
