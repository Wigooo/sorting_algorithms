#include "sort.h"
/**
 * swp_integers - swap 2 integers
 * @first: first integer
 * @second: second integer
 */
void swp_integers(int *first, int *second)
{
	int tempo;

	tempo = *first;
	*first = *second;
	*second = tempo;
}

/**
 * hoare_scheme - order subarray of integers
 * @array: array of integers
 * @size: number of integers
 * @lindex: left subarray index
 * @rindex: right subarray index
 * Return: final partition index
 */
int hoare_scheme(int *array, size_t size, size_t lindex, size_t rindex)
{
	int pivot, up, down;

	pivot = array[rindex];
	for (up = lindex - 1, down = rindex + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			down--;
		} while (array[down] > pivot);
		if (up < down)
		{
			swp_integers(array + up, array + down);
			print_array(array, size);
		}
	}
	return (up);
}

/**
 * hoare_recursion - quicksort algorithm recursion
 * @array: array of integers
 * @size: number of integers
 * @lindex: left subarray start index
 * @rindex: right end index
 */
void hoare_recursion(int *array, size_t size, size_t lindex, size_t rindex)
{
	int sub;

	if (rindex - lindex > 0)
	{
		sub = hoare_scheme(array, size, lindex, rindex);
		hoare_recursion(array, size, lindex, sub - 1);
		hoare_recursion(array, size, sub, rindex);
	}
}

/**
 * quick_sort_hoare -  sorts an array of integers in ascending order
 *				using the Quick sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: print the array after each time you swap two elements
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_recursion(array, size, 0, size - 1);
}
