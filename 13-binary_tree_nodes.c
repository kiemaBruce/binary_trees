#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of nodes.
 * Return: the number of nodes with at least one child. If tree is NULL return
 * 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count;

	if (tree == NULL)
		return (0);
	/*Use inorder traversal, not for any reason in particular*/
	count = binary_tree_nodes(tree->left); /*count nodes on left subtree*/
	/* add root if it is a node */
	if (tree->left != NULL || tree->right != NULL)
		count += 1;
	/*count nodes on right subtree*/
	count += binary_tree_nodes(tree->right);
	return (count);
}
