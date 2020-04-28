#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly-linked list.
 * @head: A pointer the head of the linked list.
 * @number: The number to insert
 * Return: If fails - NULL Otherwise - a pointer to the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{

	listint_t *new;
	listint_t *prev;

	prev = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}

	while (prev)
	{
		if (prev->n > new->n)
		{
			new->next = prev;
			*head = new;
			return (new);
		}
		if (prev->n < new->n && prev->next->n > new->n)
		{
			new->next = prev->next;
			prev->next = new;
			return (new);
		}
		if (prev->next == NULL)
		{
			new->next = NULL;
			prev->next = new;
			return (new);
		}
		prev = prev->next;
	}
	return (new);
}
