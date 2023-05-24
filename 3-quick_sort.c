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

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, i = low - 1;

	for (j = low; j <= high - 1; j++)
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
			break;
		}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

void quick(int *array, size_t size, size_t t_size)
{
	if (size <= 1)
        return;

    int pivot_index = partition(array, 0, size - 1, t_size);
    
    quick_sort(array, pivot_index);
    quick_sort(array + pivot_index + 1, size - pivot_index - 1);
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
	quick(array, size, size);
}
