#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * heap_extract - extract top or max value
 * @root: head
 * Return: value max or top
 */
int heap_extract(heap_t **root)
{
	int a;

	if (*root == NULL)
		return (0);

	a = (*root)->n;
	(*root)->n = 0;

	if ((*root)->left->n > (*root)->right->n)
	{
		(*root)->n = (*root)->left->n;
		(*root)->left->n = 0;
		reorden(&(*root)->left);
	}
	else
	{
		(*root)->n = (*root)->right->n;
		(*root)->right->n = 0;
		reorden(&(*root)->right);
	}
	return (a);
}

/**
 * reorden - extract top or max value
 * @root: head
 * Return: finish function
 */

int reorden(heap_t **root)
{
	heap_t *x = (*root)->parent;

	if (!(*root)->left && !(*root)->right)
	{
		if ((*root)->parent->left->n == (*root)->n)
			(*root)->parent->left = NULL;
		else if ((*root)->parent->right->n == (*root)->n)
			(*root)->parent->right = NULL;
		free(*root);
		verify(&x);
		return (0);
	}
	if (!(*root)->left && (*root)->right)
	{
		(*root)->n = (*root)->right->n, (*root)->right->n = 0;
		reorden(&(*root)->right);
	}
	else if (!(*root)->right && (*root)->left)
	{
		(*root)->n = (*root)->left->n, (*root)->left->n = 0;
		reorden(&(*root)->left);
	}
	else if ((*root)->left->n > (*root)->right->n)
	{
		(*root)->n = (*root)->left->n, (*root)->left->n = 0;
		reorden(&(*root)->left);
	}
	else if ((*root)->left->n < (*root)->right->n)
	{
		(*root)->n = (*root)->right->n, (*root)->right->n = 0;
		reorden(&(*root)->right);
	}
	return (0);
}

/**
 * verify - extract top or max value
 * @x: head
 * Return: value max or top
 */
void verify(heap_t **x)
{
	if ((*x)->left && !(*x)->right)
	{
		if ((*x)->parent->right->right)
		{
			(*x)->right = (*x)->parent->right->right;
			(*x)->parent->right->right = NULL;
			(*x)->right->parent = (*x);
		}
		else if ((*x)->parent->right->left)
		{
			(*x)->right = (*x)->parent->right->left;
			(*x)->parent->right->left = NULL;
			(*x)->right->parent = (*x);
		}
	}
	else if (!(*x)->left && (*x)->right)
	{
		if ((*x)->parent->right->right)
		{
			(*x)->left = (*x)->parent->right->right;
			(*x)->parent->right->right = NULL;
			(*x)->left->parent = (*x);
		}
		else if ((*x)->parent->right->left)
		{
			(*x)->left = (*x)->parent->right->left;
			(*x)->parent->right->left = NULL;
			(*x)->left->parent = (*x);
		}
	}
}
