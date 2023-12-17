#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *			using the Selection sort algorithm
 * @array: array of integers
 * @size: number of integers
 * Return: print the array after each time you swap two elements
 */

void selection_sort(int *array, size_t size)
{
	size_t index, i, x;
	int tempo;

	if (!array || !size)
		return;

	for (index = 0; index < size - 1; index++)
	{
		for (i = size - 1, x = index + 1; i > index; i--)
		{
			if (array[i] < array[x])
				x = i;
		}
		if (array[index] > array[x])
		{
			tempo = array[index];
			array[index] = array[x];
			array[x] = tempo;
			print_array(array, size);
		}
	}
}
