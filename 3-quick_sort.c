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
 * partition - split an sort one element
 * @array: array with ramdom numbers
 * @low: strart partition
 * @high: finish partition
 * @size: size of array
 * Return: partition
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, i = low - 1;

	for (j = low; j <= high - 1; j++)
		if (array[j] < pivot)
		{
			i++;
			if (i != j && i >= 0)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick - orts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array with ramdom numbers
 * @low: low value of array
 * @high: high value of array
 * @size: size of array
 * Return: void
 */

void quick(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (high > low)
	{
	pivot_index = partition(array, low, high, size);
	quick(array, low, pivot_index - 1, size);
	quick(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - orts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array with ramdom numbers
 * @size: size of array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	quick(array, low, high, size);
}
