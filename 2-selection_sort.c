#include <stdio.h>
#include "sort.h"

/**
 * swap - swap the values ​​of a and b
 * @b: int b
 * @a: int a
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: array with ramdom numbers
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t x, i, j;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		x = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[x])
				x = j;
		if (x != i)
		{
			swap(&array[i], &array[x]);
			print_array(array, size);
		}
	}
}
