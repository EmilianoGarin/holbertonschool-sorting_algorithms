#include <stdio.h>
#include "sort.h"

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
	int x, i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			x = array[i];
			array[i] = array[j];
			array[j] = x;
		}
	}
	x = array[i + 1];
	array[i + 1] = array[high];
	array[high] = x;
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
	int stack[size];
	int top = -1;

	stack[++top] = 0;
	stack[++top] = size - 1;

	while (top >= 0)
	{
		int high = stack[top--];
		int low = stack[top--];
		int pivot_index = partition(array, low, high);

		if (pivot_index - 1 > low)
		{
			stack[++top] = low;
			stack[++top] = pivot_index - 1;
		}
		if (pivot_index + 1 < high)
		{
			stack[++top] = pivot_index + 1;
			stack[++top] = high;
		}
		print_array(array, size);
	}
}
