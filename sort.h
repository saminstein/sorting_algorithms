#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t *a, listint_t *b);


/* Prototype for Selection sort */
void selection_sort(int *array, size_t size);
void swap_linked_list(listint_t **head, listint_t **first, listint_t *second);

/* Prototypes for Quick sort */
void quick_sort(int *array, size_t size);
void lomuto_sort(int *array, size_t size, int left, int right);

#endif
