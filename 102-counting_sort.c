#include "sort.h"

/**
 * counting_sort - sorts an arrays of integers in ascending
 *			order using the Counting sort algorithm
 * @array: array of integers
 * @size: number of integers
 * Return: print your counting array once it is set up
 */
void counting_sort(int *array, size_t size)
{
	int maximum, number, i, l, *count, *out;
	size_t index, k, m, n;

	if (size < 2)
		return;
	maximum = array[0];
	for (index = 1; index < size; index++)
		if (array[index] > maximum)
			maximum = array[index];
	count = malloc(sizeof(size_t) * (maximum + 1));
	out = malloc(sizeof(int) * size);
	for (i = 0; i <= maximum; i++)
		count[i] = 0;
	for (k = 0; k < size; k++)
	{
		number = array[k];
		count[number] += 1;
	}
	for (l = 1; l <= maximum; l++)
		count[l] += count[l - 1];
	print_array(count, maximum + 1);
	for (m = 0; m < size; m++)
	{
		out[count[array[m]] - 1] = array[m];
		count[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = out[n];

	free(count);
	free(out);
}
