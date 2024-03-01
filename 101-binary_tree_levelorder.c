#include "binary_trees.h"
/**
 * binary_tree_levelorder - apply func function on nodes
 * while going through the binary tree using level order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *tab[1024];
	int i, insert;

	if (!tree || !func)
		return;
	for (i = 0; i < 1024; i++)
		tab[i] = NULL;
	i = 0;
	tab[i] = (binary_tree_t *)tree;
	insert = 1;
	while (tab[i])
	{
		func(tab[i]->n);
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
}
