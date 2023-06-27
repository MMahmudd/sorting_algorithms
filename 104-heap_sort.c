#include "sort.h"

/**
* sift_down - amendHeap
* @array: the heap_to_fix
* @root: the root_of the_heap
* @end: the_last index_of the_heap
* @size: size_of_the array
* Return: return type void
*/

void sift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t left_child, right_child, swap;
	int temp;

	while ((left_child = (2 * root) + 1) <= end)
	{
		swap = root;
		right_child = left_child + 1;
		if (array[swap] < array[left_child])
			swap = left_child;
		if (right_child <= end && array[swap] < array[right_child])
			swap = right_child;
		if (swap == root)
			return;
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}

/**
* make_heap - makes a heap_from_unsorted _array
* @array: array to turn_into a _heap
* @size: size_of the_array
* Return: return type_void
*/
void make_heap(int *array, size_t size)
{
	size_t parent;

	for (parent = ((size - 1) - 1) / 2; 1; parent--)
	{
		sift_down(array, parent, size - 1, size);
		if (parent == 0)
			break;
	}
}

/**
* heap_sort - sorting an_array of ints in ascending_order w/
* the Heap_sort algo
* @array: array_to_sort
* @size:the  size_of the_array
* Return: return type void
*/
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;
	make_heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
