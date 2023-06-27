#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* partition - finds the partition_for  quickSort
* using the_Hoare_scheme
* @array: array_to_sort
* @lo: lowest index_of_the partition_to_sort
* @hi: highest_index_of the partition_to_sort
* @size: size of_the array
* Return: index_of the_partition
*/
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int swap, pivot;

	pivot = array[hi];
	while (lo <= hi)
	{
		while (array[lo] < pivot)
			lo++;
		while (array[hi] > pivot)
			hi--;
		if (lo <= hi)
		{
			if (lo != hi)
			{
				swap = array[lo];
				array[lo] = array[hi];
				array[hi] = swap;
				print_array(array, size);
			}
			lo++;
			hi--;
		}
	}
	return (hi);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @lo: lowest_index of_the_partition to be sorted
 * @hi: highest_index of the partition to be sorted
 * @size: size_of the_array
 *
 * Return: return type void
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot, size);
		quicksort(array, pivot + 1, hi, size);

	}
}

/**
* quick_sort_hoare - sortArray of integer in_ascendingOrder using the
* Quick_sort Algorithm
* @array: The_array to_sort
* @size: The size of the_array
* Return:return type void
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
