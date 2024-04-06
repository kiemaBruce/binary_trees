#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf.
 * @node: pointer to the node to check.
 * Return: 1 if node is a leaf, otherwise 0. If node is NULL, it
 * returns 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int checker, r;

	if (node == NULL)
		return (0);
	checker = 0;
	if (node->left == NULL)
		checker += 1;
	if (node->right == NULL)
		checker += 1;
	if (checker == 2)
		r = 1;
	else
		r = 0;
	return (r);
}
