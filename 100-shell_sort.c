#include "sort.h"

void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    for (gap = 1; gap < size; gap = gap * 3 + 1)
        ; // Calculate gap

    for (gap /= 3; gap > 0; gap /= 3)
    {
        for (i = gap; i < size; i++)
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
