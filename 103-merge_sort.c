#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* TDMerge - sort&Also Merges the_sub arrays_in_source
* @start: starting_index inclusiveFor the left_sub_array
* @middle: end_index exclusiveFor the left sub array_and
* starting index inclusiveFor the right sub_array
* @end: end_index exclusiveFor_right sub_array
* @dest: destination_for data
* @source: source of_data
* Return: return type void
*/
void TDMerge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	i = start;
	j = middle;
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
* TDSplitMerge - splitings the_array and_merges the sort_arrays
* @start: starting_index inclusive
* @end: end_index exclusive
* @array: array to_sort
* @copy: a duplicate_of the-array
* Return: retunr type void
*/
void TDSplitMerge(size_t start, size_t end, int *array, int *copy)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	TDSplitMerge(start, middle, array, copy);
	TDSplitMerge(middle, end, array, copy);
	TDMerge(start, middle, end, array, copy);
	for (middle = start; middle < end; middle++)
		copy[middle] = array[middle];
}

/**
* merge_sort - sorts_an_array of_integers ascending_order
* using a Merge_sort_algorithm
* @array: array to sort
* @size: the size_of_array
* Return: Retunr type void
*/
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	TDSplitMerge(0, size, array, copy);
	free(copy);
}
