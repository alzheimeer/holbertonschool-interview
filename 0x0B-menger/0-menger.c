#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * zeros_right - Remove zeros
 *
 * @line: Pointer to the array of int
 * @size: Number of elements in @line
 */
void zeros_right(int *line, size_t size)
{
	size_t i;
	int found, zeros, aux, tmp, act;

	i = size - 1;
	do {
		found = 0;
		zeros = 0;
		for (act = i; act >= 0; act--)
		{
/*printf(">%d\n}1;5202;0c", line[act]);*/
			if (line[act] == 0)
			{
				zeros += 1;
/*printf("ZEROOOO\n");*/
			}
			else if (line[act] != 0)
			{
/*printf("FOUND\n");*/
				found = 1;
				break;
			}
		}
		aux = i - zeros;
		if (aux >= 0)
		{
			tmp = line[i];
			line[i] = line[aux];
			line[aux] = tmp;
		}
		i--;
	} while (found);
}

/**
 * add_right - move right
 *
 * @line: Pointer to the array of int
 * @size: Number of elements in @line
 */

void add_right(int *line, size_t size)
{
	size_t i;
	int aux;

	for (i = size - 1; i > 0; i--)
	{
		aux = i - 1;
		if (line[i] == line[aux])
		{
			line[i] += line[aux];
			line[aux] = 0;
		}
	}
}

/**
 * add_left - move left
 *
 * @line: Pointer to the array of int
 * @size: Number of elements in @line
 */
void add_left(int *line, size_t size)
{
	size_t i;
	int aux;

	for (i = 0; i < (size - 1); i++)
	{
		aux = i + 1;
		if (line[i] == line[aux])
		{
			line[i] += line[aux];
			line[aux] = 0;
		}
	}
}

/**
 * zeros_left - Remove zeros
 *
 * @line: Pointer to the array of int
 * @size: Number of elements in @line
 */
void zeros_left(int *line, size_t size)
{
	int found, zeros, aux, tmp, i, act, s;

	s = size;
	i = 0;
	do {
		found = 0;
		zeros = 0;
		for (act = i; act < s; act++)
		{
/*printf(">%d\n}1;5202;0c", line[act]);*/
			if (line[act] == 0)
			{
				zeros += 1;
/*printf("ZEROOOO\n");*/
			}
			else if (line[act] != 0)
			{
	    /*printf("FOUND\n");*/
				found = 1;
				break;
			}
		}
		aux = i + zeros;
		if (aux < s)
		{
			tmp = line[i];
			line[i] = line[aux];
			line[aux] = tmp;
		}
		i++;
	} while (found);
}

/**
 * slide_line - move the numbers
 *
 * @line: Line to count
 * @size: Length of numbers
 * @direction: Right or left
 * Return: 1 on success 0 on failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction == 0)
	{
		zeros_left(line, size);
		add_left(line, size);
		zeros_left(line, size);
	}
	else if (direction == 1)
	{
		zeros_right(line, size);
		add_right(line, size);
		zeros_right(line, size);
	}
	else
		return (0);
	return (1);
}
