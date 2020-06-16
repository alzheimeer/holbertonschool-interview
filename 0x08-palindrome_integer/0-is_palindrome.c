#include "palindrome.h"

/**
 * is_palindrome - checks a given unsigned integer is a palindrome
 * @n: number
 * Return:  return 1 if n is a palindrome, and 0 otherwise
 * not allowed to allocate memory dynamically (malloc, calloc, …)
 **/
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, a = 0, num = n;

	for (;n != 0; n = n / 10)
		a = n % 10, rev = rev * 10 + a;
	if (rev == num)
		return (1);
	return (0);
}
