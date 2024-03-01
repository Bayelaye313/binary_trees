#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if complete, 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *tab[1024];
	int i, insert, if_no_child = 0;

	if (!tree)
		return (0);
	for (i = 0; i < 1024; i++)
		tab[i] = NULL;
	i = 0;
	tab[i] = (binary_tree_t *)tree;
	insert = 1;
	while (tab[i])
	{
		if (!tab[i]->left && tab[i]->right)
			return (0);
		if ((tab[i]->right || tab[i]->left) && if_no_child == 1)
			return (0);
		if (!tab[i]->right)
			if_no_child = 1;
		if (tab[i]->left)
		{
			tab[insert] = tab[i]->left;
			insert++;
		}
		if (tab[i]->right)
		{
			tab[insert] = tab[i]->right;
			insert++;
		}
		i++;
	}
	return (1);
}
