#include "sort.h"

/**
 * heaping - turns array in heaps
 * @array: array of integers
 * @hsize: number of integers in subtrees
 * @itree: index of subtree in heap
 * @size: number of integers in array
 */
void heaping(int *array, size_t hsize, size_t itree, size_t size)
{
	size_t maximum, before, after;
	int tempo;

	maximum = itree;
	before = (itree * 2) + 1;
	after = (itree * 2) + 2;
	if (before < hsize && array[before] > array[maximum])
		maximum = before;
	if (after < hsize && array[after] > array[maximum])
		maximum = after;
	if (maximum != itree)
	{
		tempo = array[itree];
		array[itree] = array[maximum];
		array[maximum] = tempo;
		print_array(array, size);
		heaping(array, hsize, maximum, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 *			using the Heap sort algorithm
 * @array: array of integers
 * @size: number of integers
 * Return: print the array after each time you swap two elements
 */
void heap_sort(int *array, size_t size)
{
	int index;
	int tempo;

	if (size < 2)
		return;

	for (index = size / 2 - 1; index >= 0; index--)
		heaping(array, size, (size_t)index, size);

	for (index = size - 1; index >= 0; index--)
	{
		tempo = array[index];
		array[index] = array[0];
		array[0] = tempo;
		if (index != 0)
			print_array(array, size);
		heaping(array, (size_t)index, 0, size);
	}
}
