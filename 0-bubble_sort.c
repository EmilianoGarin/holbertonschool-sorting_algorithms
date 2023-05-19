#include <stdio.h>

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

	for (x = 0; x < size; x++)
		for (j = 0; j < (size - x); j++)
			if (array[j] > array[j + 1])
			{
				i = array[j];
				array[j] = array[j + 1];
				array[j + 1] = i;
			}
}
