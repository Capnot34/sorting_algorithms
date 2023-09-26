#include "sort.h"

void swap(int *a, int *b);
void heapify(int *array, size_t size, int i, size_t print_size);
void heap_sort(int *array, size_t size);

/**
 * swap - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * heapify - Turns the array into a max heap.
 * @array: The array.
 * @size: The size of the array.
 * @i: The current index.
 * @print_size: Size of the array to print.
 */
void heapify(int *array, size_t size, int i, size_t print_size)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < (int)size && array[left] > array[largest])
        largest = left;
    if (right < (int)size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        print_array(array, print_size);
        heapify(array, size, largest, print_size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (!array || size < 2)
        return;

    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, size);
    for (i = size - 1; i >= 0; i--)
    {
        swap(&array[0], &array[i]);
        if (i != 0)
            print_array(array, size);
        heapify(array, i, 0, size);
    }
}
