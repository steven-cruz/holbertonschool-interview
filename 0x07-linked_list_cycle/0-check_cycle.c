#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - function that checks if a singly linked list has a cycle in it.
 *
 * @list: pointer. 
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *slow = list;
	listint_t *fast = list->next;

	if (list == NULL || !(list->next))
		return (0);
	while ((fast->next) != NULL)
	{
		fast = fast->next;
		if (fast->next)
			fast = fast->next;
		else
			return (0);
		slow = slow->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
