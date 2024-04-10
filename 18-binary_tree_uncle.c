#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node.
 * @node: pointer to the node whose uncle is to be found.
 * Return: pointer to the uncle node. If node has no uncle, return NULL.
 * If node is NULL, return NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grand_parent;

	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	parent = node->parent;
	grand_parent = parent->parent;
	if (grand_parent == NULL) /*Means parent is root node*/
		return (NULL);
	/*Check if parent has a sibling*/
	if (grand_parent->left == parent)
		return (grand_parent->right);
	return (grand_parent->left);
}
