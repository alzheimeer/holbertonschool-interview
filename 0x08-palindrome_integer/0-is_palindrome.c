#include "palindrome.h"

/**
 * is_palindrome - checks a given unsigned integer is a palindrome
 * @n: number
 * Return:  return 1 if n is a palindrome, and 0 otherwise
 * not allowed to allocate memory dynamically (malloc, calloc, …)
 **/
int is_palindrome(unsigned long n)
{
	size_t count = intLength(n), c1 = intLength(n);
	size_t i;

	if (count == 0)
		return (0);
	char cadena[count];
	char cadena2[count];

	itoa(n, cadena, 10);
	itoa(n, cadena2, 10);

	for (i = 0; i < c1; i++)
	{
		cadena2[i] = cadena[count - 1];
		count--;
	}
	if (strcmp(cadena, cadena2) == 0)
		return (1);
	else
		return (0);
}

/**
 * intLength - Count long n
 * @i: number
 * Return: number of long
 **/
int intLength(unsigned long i)
{
	int l = 0;

	for (; i; i /= 10)
		l++;
	return (l == 0 ? 1 : l);
}
