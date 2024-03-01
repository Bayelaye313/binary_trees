#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *tmp = tree;

	if (!tree)
		return (0);

	while (tmp->parent)
	{
		depth++;
		tmp = tmp->parent;
	}
	return (depth);
}

/**
 * binary_tree_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t d_first, d_snd, d_diff;
	binary_tree_t *node1, *node2;

	if (!first || !second)
		return (NULL);
	d_first = binary_tree_depth(first);
	d_snd = binary_tree_depth(second);
	node1 = (binary_tree_t *)first;
	node2 = (binary_tree_t *)second;
	d_diff = (d_first > d_snd) ? (d_first - d_snd) : (d_snd - d_first);

	while (d_diff--)
	{
		if (d_first > d_snd)
		{
			node1 = node1->parent;
		}
		else
		{
			node2 = node2->parent;
		}
	}
	while (node1 && node2)
	{
		if (node1 == node2)
			return (node1);
		node1 = node1->parent;
		node2 = node2->parent;
	}
	return (NULL);
}
