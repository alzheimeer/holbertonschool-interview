#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"


/**
 * order - Prints out order array of integer, followed by a new line
 * @line: points to an array of integers
 * @size: Number of elements
 * @direction: direction
 * Return: return 1 upon success, or 0 upon failure
 */
void order(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == 0)
	{
		for (i = 1; i < size - 1; i++)
		{
			if (line[i + 1] != 0 && line[i] == 0)
			{
				line[i] = line[i + 1];
				line[i + 1] = 0;
				i = -1;
			}
		}
	}
	if (direction == 1)
	{
		for (i = size - 1; i > 0; i--)
		{
			if (line[i - 1] != 0 && line[i] == 0)
			{
				line[i] = line[i - 1];
				line[i - 1] = 0;
				i = size;
			}
		}
	}
}
/**
 * slide_line - Prints out an array of integer, followed by a new line
 * @line: points to an array of integers
 * @size: Number of elements
 * @direction: direction
 * Return: return 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	if (!line)
		return (0);

	order(line, size, direction);

	if (direction == 0)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i + 1] + line[i];
				line[i + 1] = 0;
			}
		}
	}
	if (direction == 1)
	{
		for (i = size - 1; i > 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i - 1] + line[i];
				line[i - 1] = 0;
			}
		}
	}
	order(line, size, direction);
	return (1);
}
