#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if full, 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	else if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) * binary_tree_is_full(tree->right));
	else
		return (0);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t counter = 0;
	binary_tree_t *buff;

	if (!tree)
		return (0);
	buff = (binary_tree_t *)tree;
	while (buff->parent)
	{
		counter++;
		buff = buff->parent;
	}
	return (counter);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the binary tree
 * Return: the height (the longest path possible)
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_right, h_left;

	if (!tree)
		return (0);
	h_right = (tree->right) ? 1 + binary_tree_height(tree->right) : 0;
	h_left = (tree->left) ? 1 + binary_tree_height(tree->left) : 0;
	if (h_right >= h_left)
		return (h_right);
	else
		return (h_left);
}

/**
 * tree_perfect - checks if the leaves of a binary tree are at the same level.
 * the binary tree is full.
 * having same level means having their depth equal to the tree height
 * @tree: a pointer to the root node of the tree to check
 * @tree_height: tree height
 * Return: 1 if perfect, 0 if not
 */
int tree_perfect(const binary_tree_t *tree, int tree_height)
{
	if (!tree->left && !tree->right)
		return (((int)(binary_tree_depth(tree)) == tree_height) ? 1 : 0);
	else
		return (tree_perfect(tree->left, tree_height)
				* tree_perfect(tree->right, tree_height));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * a binary tree is perfect if it's full + all its leaves are at the same level
 * (having same level means having same depth)
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int _height;

	if (!tree || !binary_tree_is_full(tree))
		return (0);
	_height = (int)binary_tree_height(tree);
	return (tree_perfect(tree, _height));
}
