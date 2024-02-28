#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: pointer to the created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nouveau_node;

	if (parent == NULL)
		return (NULL);
	nouveau_node = binary_tree_node(parent, value);
	if (nouveau_node == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		(parent->left)->parent = nouveau_node;
		nouveau_node->left = parent->left;
	}
	parent->left = nouveau_node;
	return (nouveau_node);
}
