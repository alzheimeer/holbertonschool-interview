#include "binary_trees.h"

/**
* binary_tree_node - creates a binary tree node
* @parent: is a pointer to the parent node of the node to create
* @value: is the value to put in the new node
* Return: New nodo
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newN = (binary_tree_t *) malloc(sizeof(binary_tree_t));

	if (!newN)
		return (NULL);

	newN->n = value;
	newN->left = NULL;
	newN->right = NULL;
	newN->parent = parent;
	return (newN);
}
