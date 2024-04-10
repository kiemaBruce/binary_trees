#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if the tree is full and 0 if it isn't. If
 * tree is NULL, return 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bin_tree_is_full(tree));
}
/**
 * bin_tree_is_full - recursively checks whether a binary tree is full.
 * @tree: the pointer to the root node of the tree to check.
 * Return: 1 if the tree is full and 0 if it isn't.
 *
 */
int bin_tree_is_full(const binary_tree_t *tree)
{
	int r_left, r_right, children;

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	children = 0;
	if (tree->left != NULL)
		children += 1;
	if (tree->right != NULL)
		children += 1;
	if (children == 1)
		return (0);
	r_left = bin_tree_is_full(tree->left);
	r_right = bin_tree_is_full(tree->right);
	if (r_left == 0 || r_right == 0)
		return (0);
	return (1);
}
