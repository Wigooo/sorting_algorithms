#include "sort.h"

/**
 * swapnodeforward - swap a node with a node a head of it
 * @head: pointer to head of double linked list
 * @last: pointer to tail of double linked list
 * @current: pointer to current swapping node
 */
void swapnodeforward(listint_t **head, listint_t **last, listint_t **current)
{
	listint_t *tempo = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = tempo;
	else
		*head = tempo;
	tempo->prev = (*current)->prev;
	(*current)->next = tempo->next;
	if (tempo->next != NULL)
		tempo->next->prev = *current;
	else
		*last = *current;
	(*current)->prev = tempo;
	tempo->next = *current;
	*current = tempo;
}

/**
 * swapnodeback - swap a node with a node back to it
 * @head: pointer to head of double linked list
 * @last: pointer to tail of double linked list
 * @current: pointer to current swapping node
 */
void swapnodeback(listint_t **head, listint_t **last, listint_t **current)
{
	listint_t *tempo = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = tempo;
	else
		*last = tempo;
	tempo->next = (*current)->next;
	(*current)->prev = tempo->prev;
	if (tempo->prev != NULL)
		tempo->prev->next = *current;
	else
		*head = *current;
	(*current)->next = tempo;
	tempo->prev = *current;
	*current = tempo;
}

/**
 * cocktail_sort_list -  sorts a doubly linked list of integers in
 *	ascending order using the Cocktail shaker sort algorithm
 * @list: double linked list
 * Return: print the list after each time you swap two elements
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *last, *current;
	bool current_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (last = *list; last->next != NULL;)
		last = last->next;
	while (current_not_stirred == false)
	{
		current_not_stirred = true;
		for (current = *list; current != last; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swapnodeforward(list, &last, &current);
				print_list((const listint_t *)*list);
				current_not_stirred = false;
			}
		}
		for (current = current->prev; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swapnodeback(list, &last, &current);
				print_list((const listint_t *)*list);
				current_not_stirred = false;
			}
		}
	}
}
