#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/*
 * heap_extract : extract top or max value
 * @root: head
 * Return: value max or top
 */
int heap_extract(heap_t **root)
{
	int a;

	if (*root == NULL)
		return (0);

        a = ("%d",(*root)->n);
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

	return(a);
}


int reorden(heap_t **root)
{
	heap_t *x = *root;

	if (!(*root)->left && !(*root)->right)
	{
		if((*root)->parent->left->n == (*root)->n)
		{
			x = x->parent;
			x->left = NULL;
			free(*root);
			return;
		}
		if((*root)->parent->right->n == (*root)->n)
		{
			x = x->parent;
			x->right = NULL;
			free(*root);
			return;
		}
		return;

	}
	if (!(*root)->left && (*root)->right)
	{
		(*root)->n = (*root)->right->n;
		(*root)->right->n = 0;
		reorden(&(*root)->right);
		return;
	}
	else if (!(*root)->right && (*root)->left)
	{
		(*root)->n = (*root)->left->n;
		(*root)->left->n = 0;
		reorden(&(*root)->left);
		return;
	}
	if ((*root)->left->n > (*root)->right->n)
	{
		(*root)->n = (*root)->left->n;
		(*root)->left->n = 0;
		reorden(&(*root)->left);
		return;

	}
	else if((*root)->left->n < (*root)->right->n)
	{
		(*root)->n = (*root)->right->n;
		(*root)->right->n = 0;
		reorden(&(*root)->right);
		return;
	}
}
