#include "sort.h"
/**
* swap - For swapping_nodesin list
* @list: list of_integers
* @node: A node_to_swap
*/
void swap(listint_t **list, listint_t *node)
{
node->next->prev = node->prev;
if (node->prev)
node->prev->next = node->next;
else
*list = node->next;
node->prev = node->next;
node->next = node->next->next;
node->prev->next = node;
if (node->next)
node->next->prev = node;
}
/**
* cocktail_sort_list - sort_doubly linked_list of an integer
* in ascending order, use the Cocktail_shaker sor_algorithm
* @list: list_of_integer
*/
void cocktail_sort_list(listint_t **list)
{
int swapped = 1;
listint_t *tmp;
if (list == NULL || *list == NULL)
return;
tmp = *list;
while (swapped)
{
swapped = 0;
while (tmp->next)
{
if (tmp->next->n < tmp->n)
{
swap(list, tmp);
swapped = 1;
print_list(*list);
}
else
tmp = tmp->next;
}
if (swapped == 0)
break;
swapped = 0;
while (tmp->prev)
{
if (tmp->prev->n > tmp->n)
{
swap(list, tmp->prev);
swapped = 1;
print_list(*list);
}
else
tmp = tmp->prev;
}
}
}
