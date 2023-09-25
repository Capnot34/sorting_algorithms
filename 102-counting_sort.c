// 102-counting_sort.c
#include "sort.h"

void counting_sort(int *array, size_t size)
{
    int k = 0, *count, *output, i;

    if (!array || size < 2)
        return;

    for (i = 0; i < (int)size; i++)
        if (array[i] > k)
            k = array[i];

    count = malloc(sizeof(int) * (k + 1));
    output = malloc(sizeof(int) * size);
    if (!count || !output)
    {
        free(count);
        free(output);
        return;
    }

    for (i = 0; i <= k; i++)
        count[i] = 0;

    for (i = 0; i < (int)size; i++)
        count[array[i]] += 1;

    for (i = 1; i <= k; i++)
        count[i] += count[i - 1];

    print_array(count, k + 1);

    for (i = 0; i < (int)size; i++)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]] -= 1;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}
