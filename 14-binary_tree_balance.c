#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree:  pointer to the root node of the tree whose balance factor is to be
 * measured.
 * Return: the balance factor of the tree. If tree is NULL return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bin_tree_balance(tree, 0, 0));
}
/**
 * bin_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree whose balance factor is to be
 * measured.
 * @h_diff: difference between left and right subtrees of current node. Pass in
 * an initial value of 0 when calling the function.
 * @balance_f: the balance factor of the tree. Pass in an initial value of 0
 * when calling the function.
 * Description: the balance factor is the greatest difference in heights
 * between the left and right subtrees for all nodes.
 * Return: the balance factor of the binary tree. Return 0 if tree is NULL.
 */
int bin_tree_balance(const binary_tree_t *tree, int h_diff, int balance_f)
{
	size_t left_subtree_height, right_subtree_height;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL)
		left_subtree_height = -1;
	else
		left_subtree_height = binary_tree_height(tree->left);
	if (tree->right == NULL)
		right_subtree_height = -1;
	else
		right_subtree_height = binary_tree_height(tree->right);
	h_diff = left_subtree_height - right_subtree_height;
	if (absolute_val(h_diff) > absolute_val(balance_f))
		balance_f = h_diff;
	h_diff = bin_tree_balance(tree->left, 0, balance_f);
	if (absolute_val(h_diff) > absolute_val(balance_f))
		balance_f = h_diff;
	h_diff = bin_tree_balance(tree->right, 0, balance_f);
	if (absolute_val(h_diff) > absolute_val(balance_f))
		balance_f = h_diff;
	return (balance_f);
}
/**
 * absolute_val - returns the absolute value of an int.
 * @x: the int whose absolute value is to be returned.
 * Return: the absolute value of x.
 */
int absolute_val(int x)
{
	if (x >= 0)
		return (x);
	return (x * -1);
}
/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree whose height is to be measured.
 * Return: the height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (b_tree_height(tree, tree, 0, 0));
}
/**
 * b_tree_height - recursively calculates the height of a binary tree.
 * @tree: pointer to the root node of the tree whose height is to be measured.
 * @trav: pointer of a binary tree object. This pointer is used to traverse the
 * binary tree in order to determine the height, and the root node of the tree
 * should be passed as its value when the function is called.
 * @path_length: length of the current path. When the function is called, pass
 * a value of 0.
 * @height: height of the tree. Pass in a value of 0 when the function is
 * called.
 * Return: the height of the binary tree.
 */
size_t b_tree_height(const binary_tree_t *tree, const binary_tree_t *trav,
size_t path_length, size_t height)
{
	size_t p_old;

	if (trav == NULL)
	{
		return (path_length);
	}
	if (trav != tree)
		path_length += 1;
	/**
	 * save current length before traversing left and right subtrees.
	 */
	p_old = path_length;
	path_length = b_tree_height(tree, trav->left, path_length, height);
	if (path_length > height)
		height = path_length;
	if (trav->left != NULL)
		path_length = p_old;
	path_length = b_tree_height(tree, trav->right, path_length, height);
	if (path_length > height)
		height = path_length;
	if (trav->right != NULL)
		path_length = p_old;
	return (height);
}
