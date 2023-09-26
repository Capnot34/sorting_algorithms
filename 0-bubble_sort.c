#include "sort.h"

/**
 * bubble_sort - sorts an array using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swapped;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{

			if (array[j] > array[j + 1])
			{
				/* Swap arr[j] and arr[j+1] */
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;

				/* Print the array after each swap */
				print_array(array, size)
			}
		}
		/* If no two elements were swapped, the array is sorted */
		if (swapped == 0)
			break;
	}
}
