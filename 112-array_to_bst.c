#include "binary_trees.h"

/**
 * array_to_bst - a function that builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array
 * @size: size of the array
 * Return: a pointer to the racine node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *racine, *if_fail;

	racine = NULL;
	for (i = 0; i < size; i++)
	{
		if_fail = bst_insert(&racine, array[i]);
		if (!if_fail)
			return (NULL);
	}
	return (racine);
}
