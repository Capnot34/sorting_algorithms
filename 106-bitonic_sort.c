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
	size_t i, j, k = count / 2;

	for (i = low; i < low + k; i++)
	{
		j = i + k;
		if (dir == (array[i] > array[j]))
		{
			swap(array, i, j);
			print_array(array, count);
		}
	}
}

/**
 * bitonic_merge - Recursively sorts a bitonic sequence.
 * @array: Array.
 * @low: Starting index.
 * @count: Number of elements to be considered.
 * @dir: Direction (1 for increasing, 0 for decreasing).
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count <= 1)
		return;

	bitonic_compare(array, low, count, dir);
	bitonic_merge(array, low, count / 2, dir);
	bitonic_merge(array, low + count / 2, count / 2, dir);
}

/**
 * bitonic_sort_recursive - Main recursive function for bitonic sort.
 * @array: Array.
 * @low: Starting index.
 * @count: Number of elements to be considered.
 * @dir: Direction (1 for increasing, 0 for decreasing).
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	if (count <= 1)
		return;

	size_t k = count / 2;

	bitonic_sort_recursive(array, low, k, 1);
	bitonic_sort_recursive(array, low + k, k, 0);
	bitonic_merge(array, low, count, dir);
}

/**
 * bitonic_sort - Sorts an array of integers using bitonic sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}
