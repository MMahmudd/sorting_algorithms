#include "sort.h"
#include <stdio.h>

/**
* bitonic_compare - sort_the_values in subArray with
* respectation to the Bitonic sort_algorithm
* @up:the  direction_of_sorting
* @array: subArray to_sort
* @size: size_of the subArray
* Return: return type void
*/
void bitonic_compare(char up, int *array, size_t size)
{
	size_t i, dist;
	int swap;

	dist = size / 2;
	for (i = 0; i < dist; i++)
	{
		if ((array[i] > array[i + dist]) == up)
		{
			swap = array[i];
			array[i] = array[i + dist];
			array[i + dist] = swap;
		}
	}
}

/**
* bitonic_merge - recursive_function that_merges two subAarrays
* @up: direction of_sorting
* @array: subArray to_sort
* @size: size of the subAarray
* Return: return type void
*/
void bitonic_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_compare(up, array, size);
	bitonic_merge(up, array, size / 2);
	bitonic_merge(up, array + (size / 2), size / 2);
}

/**
* bit_sort - recursive_function using the_Bitonic sort_lgorithm
* @up: direction of_sorting
* @array: subArray to_sort
* @size: size_of the subArray
* @t: total_set of the orginal_array
* Return:retun type void
*/
void bit_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);
	bitonic_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
* bitonic_sort - sorts_an array_of integers in_ascending_order
* using the Bitonic_sort algorithm
* @array: array_to_sort
* @size: size of_the_array
* Return: return type void
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}
