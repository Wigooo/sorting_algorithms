#include "deck.h"

/**
 * string_cmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int string_cmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * cvalue - card value
 * @node: card in a deck
 * Return: value between 1 and 52
 */
int cvalue(deck_node_t *node)
{
	char *valuee[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *printing[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int index, printingvalue = 0;

	for (index = 1; index <= 13; index++)
	{
		if (!string_cmp(node->card->value, valuee[index - 1]))
			printingvalue = index;
	}
	for (index = 1; index <= 4; index++)
	{
		if (!string_cmp(printing[node->card->kind], printing[index - 1]))
			printingvalue = printingvalue + (13 * index);
	}

	return (printingvalue);
}

/**
 * decklist_length - function returns length of list
 * @list: head of list
 *
 * Return: length
 */
size_t decklist_length(deck_node_t *list)
{
	size_t length = 0;

	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: pointer to head of double linked list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	size_t length;
	deck_node_t *one, *two, *three, *four;

	length = decklist_length(*deck);

	if (!deck || !*deck || length < 2)
		return;

	current = *deck;
	while (current)
	{
		if (current->prev && cvalue(current) < cvalue(current->prev))
		{
			one = current->prev->prev;
			two = current->prev;
			three = current;
			four = current->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*deck = three;
			two->prev = three;
			current = *deck;
			continue;
		}
		else
			current = current->next;
	}
}
