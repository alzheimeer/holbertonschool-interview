#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
        listint_t *aux = *head, *ini = *head;
        int i = 0, j;

        if (head == NULL || *head == NULL)
            return (1);
        while (aux->next)
            aux = aux->next, i++;
        while (i)
        {
            if (ini->n == aux->n)
            {
                aux = *head;
                ini = ini->next;
                j = i;
                for (i = 0; i < j - 1; i++)
                    aux = aux->next;
            }
            else
                return (0);
        }
        return (1);
}