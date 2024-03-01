#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double point to the racine node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a point to the created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *racine, *last, **point;

	if (!tree)
	{
		racine = binary_tree_node(NULL, value);
		if (!racine)
			return (NULL);
		tree = &racine;
		return (racine);
	}
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	racine = *tree;
	while (racine)
	{
		if (value == racine->n)
			return (racine);
		last = racine;
		if (value < racine->n)
		{
			point = &(racine->left);
			racine = racine->left;
		}
		else if (value > racine->n)
		{
			point = &(racine->right);
			racine = racine->right;
		}
	}
	*point = binary_tree_node(last, value);
	return (*point);
}
