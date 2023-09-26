#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @array: Array of integers.
 * @i: First index.
 * @j: Second index.
 */
void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}

/**
 * bitonic_compare - Compares and sorts a bitonic sequence.
 * @array: Array.
 * @low: Starting index.
 * @count: Number of elements to be considered.
 * @dir: Direction (1 means increasing, 0 means decreasing).
 */
void bitonic_compare(int *array, size_t low, size_t count, int dir)
{
	size_t i, j, k;

	for (k = count / 2; k > 0; k /= 2)
	{
		for (i = low; i < low + count - k; i++)
		{
			j = i + k;
			if ((array[i] > array[j]) == dir)
			{
				swap(array, i, j);
			}
		}
	}
}

/**
 * bitonic_merge - Recursively sorts a bitonic sequence.
 * @array: Array.
 * @low: Starting index.
 * @count: Number of elements to be considered.
 * @dir: Direction (1 for increasing, 0 for decreasing).
 * @size: The total number of elements in the original array.
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir, size_t size)
{
	size_t k;

	printf("Merging [%lu/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
	print_array(array + low, count);

	if (count > 1)
	{
		k = count / 2;
		bitonic_compare(array, low, count, dir);
		printf("Result [%lu/%lu] (%s):\n", k, size, dir ? "UP" : "DOWN");
		print_array(array + low, k);
		printf("Result [%lu/%lu] (%s):\n", k, size, dir ? "DOWN" : "UP");
		print_array(array + low + k, k);
		bitonic_merge(array, low, k, dir, size);
		bitonic_merge(array, low + k, k, !dir, size);
	}
}

/**
 * bitonic_sort_recursive - Main recursive function for bitonic sort.
 * @array: Array.
 * @low: Starting index.
 * @count: Number of elements to be considered.
 * @dir: Direction (1 for increasing, 0 for decreasing).
 */
void bitonic_sort_recursive(int *array, size_t low,
		size_t count, int dir, size_t size)
{
	size_t k;

	if (count <= 1)
		return;

	k = count / 2;

	bitonic_sort_recursive(array, low, k, 1, size);
	bitonic_sort_recursive(array, low + k, k, 0, size);
	bitonic_merge(array, low, count, dir, size);
}
/**
 * bitonic_sort - Sorts an array of integers
 * using bitonic sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;

	printf("%lu", (unsigned long)array[0]);
	for (i = 1; i < size; i++)
	{
		printf(", %d", array[i]);
	}
	printf("\n\n");

	bitonic_sort_recursive(array, 0, size, 1, size);

	printf("\n");
	print_array(array, size);
}
