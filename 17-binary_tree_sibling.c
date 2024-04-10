#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node.
 * @node: pointer to the node whose sibling is to be found.
 * Return: pointer to the sibling of node. If node has no sibling
 * return NULL. If parent is NULL or node is NULL, return NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	parent = node->parent;
	if (parent->left == node)
	{
		/*Check for right sibling*/
		return (parent->right);
	}
	/**
	 * else if (parent->right == node)
	 * Check for left sibling
	 */
	return (parent->left);
}
