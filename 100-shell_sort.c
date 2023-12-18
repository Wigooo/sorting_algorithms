#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending
 *			order using the Shell sort algorithm
 * @array: array of integers
 * @size: number of integers
 * Return: print the array each time you decrease the interval
 */

void shell_sort(int *array, size_t size)
{
	size_t g = 0, index, i;
	int tempo;

	if (size < 2)
		return;
	while ((g = g * 3 + 1) < size)
		;
	g = (g - 1) / 3;
	for (; g > 0; g = (g - 1) / 3)
	{
		for (index = g; index < size; index++)
		{
			tempo = array[index];
			for (i = index; i >= g && tempo <= array[i - g]; i -= g)
				array[i] = array[i - g];
			array[i] = tempo;
		}
		print_array(array, size);
	}
}
