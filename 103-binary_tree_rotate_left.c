#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *y, *z;

	if (!tree || !tree->right)
		return (tree);
	y = tree->right;
	y->parent = tree->parent;
	z = y->left;
	if (z)
		(y->left)->parent = tree;
	tree->right = z;
	z = tree;
	tree->parent = y;
	while (y->parent)
	{
		y = y->parent;
	}
	return (y);
}
