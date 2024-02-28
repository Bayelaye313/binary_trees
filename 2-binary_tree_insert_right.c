#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: pointer to the created node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nouveau_node;

	if (parent == NULL)
		return (NULL);
	nouveau_node = binary_tree_node(parent, value);
	if (nouveau_node == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		(parent->right)->parent = nouveau_node;
		nouveau_node->right = parent->right;
	}
	parent->right = nouveau_node;
	return (nouveau_node);
}
