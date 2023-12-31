#ifndef __SORT_H__
#define __SORT_H__

#include <stddef.h>
#include <stdio.h>
/**
* struct listint_s - Doubly_000linked list_node
* @n: Integers storage in_nodes
* @prev: Pointer_to_ previous component_of_the list
* @next: Pointer_to the next_components of_list
*/
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
#endif
