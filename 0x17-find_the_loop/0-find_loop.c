#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * find_listint_loop - find the loop in a linked list
 * @head: first element of the list
 * Return: the node where estarts the loop
 */
{
	listint_t *lento = head, *rap = head;

	if (head == NULL)
		return (0);
	while (lento && rap && rap->next)
	{
		lento = lento->next;
		rap = rap->next->next;

		if (lento == rap)
		{
			return (head);
		}
	}
	return (NULL);
}
