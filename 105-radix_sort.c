#include "sort.h"

/**
 * countsort_LSD - count sort with LSD
 * @array: array of integers
 * @size: number of integers
 * @lsd: least significant digit
 */
void countsort_LSD(int *array, size_t size, size_t lsd)
{
	int count[10] = {0}, *out, l, m;
	size_t k, n;

	out = malloc(sizeof(int) * size);

	for (k = 0; k < size; k++)
		count[(array[k] / lsd) % 10]++;
	for (l = 1; l < 10; l++)
		count[l] += count[l - 1];

	for (m = size - 1; m >= 0; m--)
	{
		out[count[(array[m] / lsd) % 10] - 1] = array[m];
		count[(array[m] / lsd) % 10]--;
	}

	for (n = 0; n < size; n++)
		array[n] = out[n];

	free(out);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 *			using the Radix sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: print the array each time you increase your significant digit
 */
void radix_sort(int *array, size_t size)
{
	int maximum;
	size_t index, lsd;

	if (!array || size < 2)
		return;

	maximum = 0;
	for (index = 0; index < size; index++)
		if (array[index] > maximum)
			maximum = array[index];

	for (lsd = 1; maximum / lsd > 0; lsd *= 10)
	{
		countsort_LSD(array, size, lsd);
		print_array(array, size);
	}
}
