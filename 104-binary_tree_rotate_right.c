#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *r;

	if (!tree || !tree->left)
		return (tree);
	r = tree->left;
	r->parent = tree->parent;
	if (r->right)
		(r->right)->parent = tree;
	tree->left = r->right;
	r->right = tree;
	tree->parent = r;
	while (r->parent)
	{
		r = r->parent;
	}
	return (r);
}
