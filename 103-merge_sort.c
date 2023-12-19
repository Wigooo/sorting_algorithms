#include "sort.h"

/**
 * merging_babyarrays - merge subarray
 * @baby: subarray of main array
 * @buffer: buffer to store in sorted baby array
 * @first: front index of array
 * @middle: middle index of array
 * @last: back index of array
 */
void merging_babyarray(int *baby, int *buffer, size_t first,
		size_t middle, size_t last)
{
	size_t x, y, i = 0;

	printf("Merging...\n[left]: ");
	print_array(baby + first, middle - first);

	printf("[right]: ");
	print_array(baby + middle, last - middle);

	for (x = first, y = middle; x < middle && y < last; i++)
		buffer[i] = (baby[x] < baby[y]) ? baby[x++] : baby[y++];
	for (; x < middle; x++)
		buffer[i++] = baby[x];
	for (; y < last; y++)
		buffer[i++] = baby[y];
	for (x = first, i = 0; x < last; x++)
		baby[x] = buffer[i++];

	printf("[Done]: ");
	print_array(baby + first, last - first);
}

/**
 * merge_recursion - Implement the merge sort algorithm through recursion.
 * @baby: A subarray of an array
 * @buffer: A buffer to store the sorted result.
 * @first: The front index of the subarray.
 * @last: The back index of the subarray.
 */
void merge_recursion(int *baby, int *buffer, size_t first, size_t last)
{
	size_t middle;

	if (last - first > 1)
	{
		middle = first + (last - first) / 2;
		merge_recursion(baby, buffer, first, middle);
		merge_recursion(baby, buffer, middle, last);
		merging_babyarray(baby, buffer, first, middle, last);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 *			using the Merge sort algorithm
 * @array: array of integers
 * @size: number of integers
 * Return: merged sorted output
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;
	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_recursion(array, buffer, 0, size);
	free(buffer);
}
