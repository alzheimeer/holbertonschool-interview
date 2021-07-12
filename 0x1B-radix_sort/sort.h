#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void check_list(const listint_t *list);
void check_array(const int *array, size_t size);
int *rand_array(int len, int max);
void inter_ints(int *a, int *b);
int parti_lomuto(int *array, size_t size, int left, int right);
void sort_lomuto(int *array, size_t size, int left, int right);


void radix_sort(int *array, size_t size);

#endif
