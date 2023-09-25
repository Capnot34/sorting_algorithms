// 103-merge_sort.c
#include "sort.h"

void merge(int *array, int *temp, int left, int mid, int right)
{
    int i, j, k;

    for (i = left; i <= right; i++)
        temp[i] = array[i];

    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right)
    {
        if (temp[i] <= temp[j])
            array[k++] = temp[i++];
        else
            array[k++] = temp[j++];
    }

    while (i <= mid)
        array[k++] = temp[i++];
}

void split_merge(int *array, int *temp, int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        split_merge(array, temp, left, mid);
        split_merge(array, temp, mid + 1, right);
        printf("Merging...\n");
        printf("[left]: ");
        print_array(array + left, mid - left + 1);
        printf("[right]: ");
        print_array(array + mid + 1, right - mid);
        merge(array, temp, left, mid, right);
        printf("[Done]: ");
        print_array(array + left, right - left + 1);
    }
}

void merge_sort(int *array, size_t size)
{
    int *temp;

    if (!array || size < 2)
        return;

    temp = malloc(sizeof(int) * size);
    if (!temp)
        return;

    split_merge(array, temp, 0, size - 1);
    free(temp);
}
