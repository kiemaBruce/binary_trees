#include "binary_trees.h"
#include <stdio.h>

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
