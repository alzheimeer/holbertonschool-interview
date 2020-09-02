#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * heap_sort - Heap Sort
 * Heap properties:
 * Left child of array[i] is array[2i + 1] (given 2i + 1 < array.size)
 * Right child of array[i] is array[2i + 2] (given 2i + 2 < array.size)
 * parent of array[i] is array[(i-1)/2]
 * @array: array of numbers
 * @size: Size of the array
 * Return: Always 0
 */
void heap_sort(int *array, size_t size)
{
	size_t len = size, root, temp;
	ssize_t i_ult, padre;
	int tempA;

	if (size < 2)
		return;
	while (len > 1)
	{
		i_ult = size - 1;
		padre = (i_ult - 1) / 2;
		while (padre >= 0)
		{
			padre--;
			root = padre;
			while ((2 * root + 1) < len)
			{
				temp = root;
				if (array[(2 * root + 1)] > array[root])
					temp = (2 * root + 1);
				if (2 * root + 2 < len && array[2 * root + 2] > array[temp])
					temp = 2 * root + 2;
				if (temp == root)
					break;
				tempA = array[root];
				array[root] = array[temp];
				array[temp] = tempA;
				print_array(array, size);
				root = temp;
			}
		}
		tempA = array[0];
		array[0] = array[len - 1];
		array[len - 1] = tempA;
		print_array(array, size);
		len--;
	}
}
