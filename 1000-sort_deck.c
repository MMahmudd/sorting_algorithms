#include "deck.h"

/**
* sort_deck - Sorting a_deck of_card
* @deck: doubly_linked_list to_sort
*/
void sort_deck(deck_node_t **deck)
{
deck_node_t *curr;
size_t len;
deck_node_t *one, *two, *three, *four;
len = list_len_deck(*deck);
if (!deck || !*deck || len < 2)
return;
curr = *deck;
while (curr)
{
if (curr->prev && card_value(curr) < card_value(curr->prev))
{
one = curr->prev->prev;
two = curr->prev;
three = curr;
four = curr->next;
two->next = four;
if (four)
four->prev = two;
three->next = two;
three->prev = one;
if (one)
one->next = three;
else
*deck = three;
two->prev = three;
curr = *deck;
continue;
}
else
curr = curr->next;
}
}

/**
* card_value - return_of the_value of a_card
* @node: card_in a_deck
* Return: value_between 1 & 52
*/
int card_value(deck_node_t *node)
{
char *val[13] = {"Ace", "2", "3", "4", "5", "6",
"7", "8", "9", "10", "Jack", "Queen", "King"};
char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
int i, kind_val = 0;
for (i = 1; i <= 13; i++)
{
if (!_strcmp(node->card->value, val[i - 1]))
kind_val = i;
}
for (i = 1; i <= 4; i++)
{
if (!_strcmp(kinds[node->card->kind], kinds[i - 1]))
kind_val = kind_val + (13 * i);
}
return (kind_val);
}

/**
* _strcmp - comparing two_strings
* @s1:the  first_string to_compare
* @s2:the  second_string to_compare
* Return: less_than 0 if_s1 is_less than_s2,
* 0 if_they're_equal,
* more_than 0 if_s1 is greater_than s2
*/
int _strcmp(const char *s1, const char *s2)
{
while (*s1 == *s2)
{
if (*s1 == '\0')
{
return (0);
}
s1++;
s2++;
}
return (*s1 - *s2);
}

/**
* list_len_deck - function_returns the_length of_list
* @list: lists'_head
* Return:return type length
*/
size_t list_len_deck(deck_node_t *list)
{
size_t len = 0;
while (list)
{
len++;
list = list->next;
}
return (len);
}
