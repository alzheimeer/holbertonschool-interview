#include "binary_trees.h"

/**
* heap_insert -  inserts a value into a Max Binary Heap
* @root: is a double pointer to the root node of the Heap
* @value: is the value store in the node to be inserted
* Return: a pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *nodo;

    nodo = malloc(sizeof(heap_t));
    if (!nodo)
        return (NULL);

    if (*root == NULL)
    {
        nodo = binary_tree_node(*root, value);
    }




    return (nodo);
}
