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
 * Return: partition
 */

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int j, i = low - 1;

	for (j = low; j <= high - 1; j++)
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			break;
		}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
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
	int low = 0, high = size - 1, pivot_index;

	while (low < high)
	{
		pivot_index = partition(array, low, high);

		print_array(array, size);

		if (pivot_index - low < high - pivot_index)
			if (low < pivot_index - 1)
				high = pivot_index - 1;
			else
				low = pivot_index + 1;
		else
			if (pivot_index + 1 < high)
				low = pivot_index + 1;
			else
				high = pivot_index - 1;
	}
}
