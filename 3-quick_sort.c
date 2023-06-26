#include "sort.h"
#include <stdio.h>

/**
* partition - locating the party for the quick_sort
* use Lomuto_scheme
* @array: the_array_to_sort
* @lo: lowest_index of partition_to_sort
* @hi: highest_index of partition_to_sort
* @size: size_of_the arr
* Return: index_of_partition
*/
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quicksort - sorting_partition of_array of_integers
* @array: arr to_sort
* @lo: The lowest_index of_the_partition to be sorted
* @hi: highest_index of_partition to be sorted
* @size: size_of_the array
* Return: return type void
*/
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pi;

	if (lo < hi)
	{
		pi = partition(array, lo, hi, size);
		quicksort(array, lo, pi - 1, size);
		quicksort(array, pi + 1, hi, size);

	}
}

/**
* quick_sort - sorting an_array of_integers_in an_ascending_order
*  using the QuickSort_algorithm
* @array:  array_to_sort
* @size:  size_of the_array
* Return: retunr type void
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
