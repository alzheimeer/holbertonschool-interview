#include "binary_trees.h"

/**
* heap_insert: inserta un valor en un montón binario máximo
* @root: es un puntero doble al nodo raíz del montón
* @value: es el valor almacenado en el nodo que se va a insertar
* Retorno: un puntero al nodo insertado, o NULL en caso de falla
*/

heap_t *heap_insert(heap_t **root, int value)
{
    size_t n = get_heap_size(*root) + 1;
    heap_t *nodo;

    nodo = malloc(sizeof(heap_t));
    if (!nodo)
        return (NULL);
    nodo->n = value;
    nodo->left = NULL;
    nodo->right = NULL;
    if (*root == NULL)
    {
        *root = nodo;
		return (nodo);
    }




    return (heapify(nodo));
}
/**
 * get_heap_size - gets number of nodes in heap
 * @root: pointer to root node
 * Return: number of nodes
 */
size_t get_heap_size(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + get_heap_size(root->left) + get_heap_size(root->right));
}

/**
 * heapify - ubique to node in Max Heap
 * @node: new noden
 * Return: pointer to starting node
 */
heap_t *heapify(heap_t *node)
{
	while (node && node->parent && node->n > node->parent->n)
	{
		node->parent->n -= node->n;
		node->n = node->parent->n + node->n;
		node->parent->n = node->n - node->parent->n;
		node = node->parent;
	}
	return (node);
}