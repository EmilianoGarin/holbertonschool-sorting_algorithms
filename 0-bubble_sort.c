#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array with ramdom numbers
 * @size: size of array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, j, i;

	if (!array || size < 1)
		return;
	for (x = 0; x < size - 1; x++)
	{
		for (j = 0; j < (size - x - 1); j++)
			if (array[j] > array[j + 1])
			{
				i = array[j];
				array[j] = array[j + 1];
				array[j + 1] = i;
				print_array(array, size);
			}
	}
}
