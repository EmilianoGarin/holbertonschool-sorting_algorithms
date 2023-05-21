#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: array with ramdom numbers
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t j, i;
	int y, x;

	for (i = 0; i < (size - 1); i++)
	{
		x = array[i];
		for (j = (i + 1); j < size; j++)
			if (array[j] < x)
			{
				y = x;
				x = array[j];
				array[j] = y;
			}
		if (x != array[i])
			array[i] = x;
		print_array(array, size);
	}
}
