#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree.
 * @parent: pointer to the parent node of the node to create.
 * @value: value to put in the new node.
 * Description: when created, a node does not have any child.
 * Return: Pointer to the new node or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	(*new).parent = parent;
	new->left = NULL;
	new->right = NULL;
	if (parent == NULL)
		return (new);
	if (value < parent->n)
		parent->left = new;
	else if (value > parent->n)
		parent->right = new;
	return (new);
}
