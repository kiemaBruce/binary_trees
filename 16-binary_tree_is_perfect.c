#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfect and 0 if it isn't. If tree is NULL
 * return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int full, same_level;

	if (tree == NULL)
		return (0);
	/**
	 * Algorithm to check if the tree is perfect.
	 * 1. Check if the tree is full(that each node has 0 or 2 children)
	 * 2. Traverse through the entire tree and check that each leaf is at
	 * the same level, if any are at different levels means that the tree
	 * isn't perfect.
	 */
	full = binary_tree_is_full(tree);
	if (full == 0)
		return (0);
	same_level = leaf_level_checker(tree, -1, -1);
	if (same_level == -2)
		return (0);
	return (1);
}
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
/**
 * leaf_level_checker - checks if all leaves in binary tree are at same level.
 * @tree: pointer to the root node of the tree to check.
 * @level: the level of the current node. Pass in an initial value of -1 when
 * calling the function.
 * @last_leaf_level: the level of the last encountered leaf when traversing the
 * tree. Used to compare to newly found leaves. Pass in an initial value of -1
 * when calling the function.
 * Description: the function works with the assumption that the binary tree is
 * full, and so would fail if the binary tree isn't already verified to be
 * full.
 * Return: If all leaves are at the same level, return the level of the leaves.
 * If they aren't at same level, return -2.
 */
int leaf_level_checker(const binary_tree_t *tree, int level,
int last_leaf_level)
{
	int r_left, r_right;

	level += 1;

	if (tree->left == NULL && tree->right == NULL) /*leaf, return level*/
		return (level);
	r_left = leaf_level_checker(tree->left, level, last_leaf_level);
	if (last_leaf_level == -1 && r_left != -2)
		last_leaf_level = r_left;
	if (r_left != last_leaf_level)
		return (-2);
	r_right = leaf_level_checker(tree->right, level, last_leaf_level);
	if (last_leaf_level == -1 && r_right != -2)
		last_leaf_level = r_right;
	if (r_right != last_leaf_level)
		return (-2);
	return (last_leaf_level);
}
