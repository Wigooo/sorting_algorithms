#include "sort.h"

/**
 * bimerging - merges a seq in asscending or descending order
 * @array: array of integers
 * @size: size of array
 * @lindex: left element index
 * @rindex: right element index
 * @seq: ascending or descending
 */
void bimerging(int *array, size_t size, size_t lindex, size_t rindex,
		int seq)
{
	size_t tempo, index, heap = (lindex + rindex) / 2,
	    middle = (rindex - lindex + 1) / 2;

	if (rindex - lindex > 1)
	{
		for (index = lindex; index < lindex + middle; index++)
		{
			if (seq == (array[index] > array[index + middle]))
			{
				tempo = array[index + middle];
				array[index + middle] = array[index];
				array[index] = tempo;
			}
		}
		bimerging(array, size, lindex, heap, seq);
		bimerging(array, size, heap + lindex, rindex, seq);
	}
}

/**
 * birecursion - recursive for bitonic_sort
 * @array: array of integers
 * @lindex: left  element index
 * @rindex: right element index
 * @seq: asscending or descending
 * @size: size of array
 */
void birecursion(int *array, int lindex, int rindex, int seq, size_t size)
{
	int heap;

	if (rindex - lindex >= 1)
	{
		heap = (rindex + lindex) / 2;
		printf("Merging [%d/%lu] ", rindex - lindex + 1, size);
		if (seq)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + lindex, rindex - lindex + 1);
		birecursion(array, lindex, heap, 1, size);
		birecursion(array, heap + 1, rindex, 0, size);
		bimerging(array, size, lindex, rindex, seq);
		printf("Result [%d/%lu] ", rindex - lindex + 1, size);
		if (seq)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + lindex, rindex - lindex + 1);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 *			using the Bitonic sort algorithm
 * @array: array of integers
 * @size: number of integers
 * Return: print the array each time you swap two elements
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	birecursion(array, 0, size - 1, 1, size);
}
