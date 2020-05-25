#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *ini = *head;
	int i = 0, j = 0;
	int l[4096];

	if (head == NULL || *head == NULL)
		return (1);
	while (ini->next)
		ini = ini->next, i++;
	ini = *head;
	while (ini)
	{
		l[j] = ini->n;
		ini = ini->next;
		j++;
	}
	ini = *head;
	while (ini)
	{
		if (ini->n == l[i])
			ini = ini->next;
		else
			return (0);
		i--;
	}
	return (1);
}
