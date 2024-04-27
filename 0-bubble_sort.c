#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - function that sorts an array of inte
 * gers
 * @array: The array of integers
 * @size: The size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int temp;

	if (!array || size < 2)
		return;

	while (i < size)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] >  array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		i++;
	}
}
