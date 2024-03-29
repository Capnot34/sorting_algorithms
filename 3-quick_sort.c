#include "sort.h"

void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size);
ssize_t partition(int *array, ssize_t lo, ssize_t hi, size_t size);
int is_sorted(int *array, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: pointer to the first element of the array
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2 || is_sorted(array, size))
		return;

	quicksort(array, 0, size - 1, size);
}
/**
 * is_sorted - Checks if the given array is sorted in ascending order
 * @array: Pointer to the first element of the array to check
 * @size: The number of elements in the array
 *
 * Return: 1 if the array is sorted, 0 otherwise
 */
int is_sorted(int *array, size_t size)
{
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i - 1] > array[i])
			return (0);
	}
	return (1);
}

/**
 * quicksort - implements the quicksort algorithm
 * @array: pointer to the first element of the array
 * @lo: starting index
 * @hi: ending index
 * @size: size of the array
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	if (lo < hi)
	{
		ssize_t p = partition(array, lo, hi, size);

		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}
}

/**
 * partition - partitions the array
 * @array: pointer to the first element of the array
 * @lo: starting index
 * @hi: ending index
 * @size: size of the array
 * Return: the pivot position
 */
ssize_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int pivot = array[hi];
	ssize_t i = lo, j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			 i++;
		}
	}

	if (i != hi)
	{
		int temp = array[i];

		array[i] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}

	return (i);
}
