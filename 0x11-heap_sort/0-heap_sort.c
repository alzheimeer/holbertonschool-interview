#include "sort.h"
/**
 * verify - verify childs of father
 * @array: The array to be printed
 * @father: father
 * @size: Number of elements in array
 * @sizes: number limit
 * Return: None
 */
void verify(int *array, size_t size, int father, int sizes)
{
	int left, right, tmp, pepe = 0;

	left = 2 * father + 1;
	right = 2 * father + 2;
	if (right <= sizes)
	{
		if (array[left] > array[right]
		    && array[left] > array[father] && left <= sizes)
			pepe = left;
		if (array[right] > array[left] && array[right] > array[father])
			pepe = right;
	}
	else
		if (array[left] > array[father] && left <= sizes)
			pepe = left;
	if (pepe != 0)
	{
		tmp = array[pepe];
		array[pepe] = array[father];
		array[father] = tmp;
		print_array(array, size);
		verify(array, size, pepe, sizes);
	}
}

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
	int tmp;
	int len = size, sizes = size - 1;
	int father;

	if (size < 2)
		return;
	while (len > 1)
	{
		while (sizes)
		{
			father =  (sizes - 1) / 2;
			verify(array, size, father, len - 1);
			sizes--;
		}
		tmp = array[0];
		array[0] = array[len - 1];
		array[len - 1] = tmp;
		print_array(array, size);
		len--;
		sizes = len - 1;
	}
}
