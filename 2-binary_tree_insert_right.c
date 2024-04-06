#include "binary_trees.h"

/**
 * binary_tree_insert_right-inserts a node as the right-child of another node.
 * @parent: pointer to the node to insert the right-child in.
 * @value: value to store in the new node.
 * Description: If parent already has a right-child, the new node takes its
 * place, and the old right-child is set as the right-child of the new
 * node.
 * Return: pointer to the created node, or NULL on failure or if parent
 * is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	if (parent->right == NULL)
	{
		new->right = NULL;
	} else
	{
		new->right = parent->right;
		(parent->right)->parent = new;
	}
	parent->right = new;
	return (new);
}
