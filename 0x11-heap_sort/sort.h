#ifndef LISTS_H
#define LISTS_H
#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void verify(int *array, size_t size, int father, int sizes);

#endif
