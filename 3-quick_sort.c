#include "sort.h"

/**
 * swp - swap 2 integer values
 * @arr: array of integers
 * @s: number of integers
 * @first: first integer
 * @second: second integer
 * Return: void
 */

void swp(int *arr, size_t s, int *first, int *second)
{
	if (*first != *second)
	{
		*first = *first + *second;
		*second = *first - *second;
		*first = *first - *second;
		print_array((const int *)arr, s);
	}
}

/**
 * lomutoparts - parting array
 * @arr: array of integers
 * @s: size of array
 * @l: low index of sorted range
 * @h: high index of sorted range
 * Return: index
 */

size_t lomutoparts(int *arr, size_t s, ssize_t l, ssize_t h)
{
	int index, i, pivot = arr[h];

	for (index = i = l; i < h; i++)
		if (arr[i] < pivot)
			swp(arr, s, &arr[i], &arr[index++]);
	swp(arr, s, &arr[index], &arr[h]);

	return (index);
}

/**
 * quicksort - quicksorts via Lomuto partitioning scheme
 * @arr: array of integers
 * @s: number of integers
 * @l: low i of sorted range
 * @h: high i of sorted range
 */

void quicksort(int *arr, size_t s, ssize_t l, ssize_t h)
{
	if (l < h)
	{
		size_t p = lomutoparts(arr, s, l, h);

		quicksort(arr, s, l, p - 1);
		quicksort(arr, s, p + 1, h);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *			using the Quick sort algorithm
 * @array: array of integers
 * @size: number of integers
 * Return: print the array after each time you swap two elements
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
