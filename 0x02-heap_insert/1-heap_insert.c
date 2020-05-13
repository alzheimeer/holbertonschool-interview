#include "binary_trees.h"

/**
* heap_insert - insert node in heap max
* @root: pointer double to root heap
* @value: value n node to insert
* Return: pointer to node insert or NULL if err
*/
heap_t *heap_insert(heap_t **root, int value)
{
	size_t nNode;
	heap_t *nodo;

	if (*root == NULL)
		return (*root = binary_tree_node(NULL, value));
	nNode = get_heap_size(*root) + 1;
	nodo = iwithIndex(*root, value, 1, nNode);

	while (nodo && nodo->parent && nodo->n > nodo->parent->n)
	{
		nodo->n = nodo->parent->n;
		nodo->parent->n = value;
		nodo = nodo->parent;
	}
	return (nodo);
}
/**
 * iwithIndex - Inserts node level ordered
 * @root: Type binary_tree pointer of the parent node
 * @value: Type int value of value inserted into node
 * @idx: Type int index of the node
 * @nNode: number the nodes + 1
 * Return: Node inserted
 */
heap_t *iwithIndex(binary_tree_t *root, int value, size_t idx, size_t nNode)
{
	heap_t *nodel, *noder;
	size_t parent = nNode / 2;

	if (!root)
		return (NULL);
	if (idx == parent)
	{
		if (nNode % 2)
			return (root->right = binary_tree_node(root, value));
		else
			return (root->left = binary_tree_node(root, value));
	}
	nodel = iwithIndex(root->left, value, 2 * idx, nNode);
	noder = iwithIndex(root->right, value, 2 * idx + 1, nNode);
	if (nodel)
		return (nodel);
	else
		return (noder);
}
/**
 * get_heap_size - gets number of nodes in heap
 * @root: pointer to root node
 * Return: number of nodes
 */
size_t get_heap_size(heap_t *root)
{
	int left = 0, right = 0;

	if (!root)
		return (0);
	left = get_heap_size(root->left);
	right = get_heap_size(root->right);
	return (1 + left + right);
}
