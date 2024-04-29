#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @a: pointer of the first node
 * @b: pointer of the second node
 * Return: void
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	if (a->prev)
	{
		a->prev->next = b;
	}
	if (b->next)
	{
		b->next->prev = a;
	}
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: linked list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;
	listint_t *next_node = NULL;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;
		temp = current;
		while (temp != NULL && temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swap_nodes(temp->prev, temp);
				if (temp->prev == NULL)
				{
					*list = temp;
				}
				print_list(*list);
			}
			else
			{
				temp = temp->prev;
			}
		}
		current = next_node;
	}
}
