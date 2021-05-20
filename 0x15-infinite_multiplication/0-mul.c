#include "holberton.h"

/**
 * _isdigit - check if a string is a digit
 * Description - This function is to check if a string is a digit
 * @n: Sring to guess if is an uppercase character
 * Return: 1 if n is a digit, 0 otherwise
 */
int _isdigit(char *n)
{
	int i;

	i = 0;
	while (*(n + i) != '\0')
	{
		if (*(n + i) < '0' || *(n + i) > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - Return the len of a string
 * Description: This function shows the length of a given string
 * @s: Pointer that contains the string
 * Return: @s len
 */
int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * is_error - error checker
 * @argc: number of arguments
 * @argv: an array consisting arguments
 *
 * Return: 0 on  succsess
 */

int is_error(int argc, char **argv)
{
	if (argc != 3 || !(_isdigit(argv[1])) || !(_isdigit(argv[2])))
	{
		puts("Error");
		exit(98);
	}
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		printf("0\n");
		return (0);
	}
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: an array consisting arguments
 *
 * Return: 0 or 1
 */

int main(int argc, char **argv)
{
	int len1, len2, carry, a, b, i, j;
	int *result;

	is_error(argc, argv);
	result = calloc(len1 + len2, sizeof(*result));
	if (!result)
		return (EXIT_FAILURE);
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		a = argv[1][i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			b = argv[2][j] - '0';
			carry += result[i + j + 1] + (a * b);
			result[j + i + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[i + j + 1] += carry;
	}
	a = result[0] == 0 ? 1 : 0;
	for (; a < len1 + len2; a++)
		printf("%d", result[a]);
	printf("\n");
	free(result);
	return (EXIT_SUCCESS);
}
