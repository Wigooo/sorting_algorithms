#include "sort.h"

/**
 * bubble_sort - sort an array of integers in ascending
 *			order using the Bubble sort algorithm.
 * @array: array of integers
 * @size: number of integers
 * Return: array after each time you swap two elements
 */

void bubble_sort(int *array, size_t size)
{
	size_t index, i;
	int tempo;

	if (!array || !size)
		return;

	index = 0;
	while (index < size)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tempo = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tempo;
				print_array(array, size);
			}
		}
		index++;
	}
}
