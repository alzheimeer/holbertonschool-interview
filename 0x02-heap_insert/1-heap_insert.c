#include "binary_trees.h"

/**
* heap_insert: inserta un valor en un montón binario máximo
* @root: es un puntero doble al nodo raíz del montón
* @value: es el valor almacenado en el nodo que se va a insertar
* Retorno: un puntero al nodo insertado, o NULL en caso de falla
*/

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *nodo;

    nodo = malloc(sizeof(heap_t));
    if (!nodo)
        return (NULL);
    nodo->n = value;
    if (*root == NULL)
    {
        *root = nodo;
		return (nodo);
    }




    return (nodo);
}
