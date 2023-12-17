#include "sort.h"

/**
 * swpnodes - swaps nodes
 * @head: pointer to head node
 * @l1: pointer to 1st node to swap
 * @l2: pointer to scnd node
 */

void swpnodes(listint_t **head, listint_t **l1, listint_t *l2)
{
	(*l1)->next = l2->next;
	if (l2->next != NULL)
		l2->next->prev = *l1;
	l2->prev = (*l1)->prev;
	l2->next = *l1;
	if ((*l1)->prev != NULL)
		(*l1)->prev->next = l2;
	else
		*head = l2;
	(*l1)->prev = l2;
	*l1 = l2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *		in ascending order using the Insertion sort algorithm
 * @list: double linked list
 * Return: print the list after each time you swap two elements
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tempo, *iteration, *insertion;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iteration = (*list)->next; iteration != NULL; iteration = tempo)
	{
		tempo = iteration->next;
		insertion = iteration->prev;
		while (insertion != NULL && iteration->n < insertion->n)
		{
			swpnodes(list, &insertion, iteration);
			print_list((const listint_t *)*list);
		}
	}
}
