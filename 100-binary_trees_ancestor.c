#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 * Return: pointer to the lowest common ancestor node of the two given nodes.
 * If no common ancestor was found, return NULL. If first or second is NULL,
 * return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *r;
	size_t first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);
	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);
	if (first_depth != second_depth)
		return (binary_trees_ancestor_helper(first, second,
		first_depth, second_depth));
	/**
	 * At least one is a root node, meaning they can't have a
	 * common ancestor.
	 */
	if (first->parent == NULL || second->parent == NULL)
	{
		return (NULL);
	}
	/*Same node, can't have common ancestor.*/
	if (first == second)
		return (NULL);
	while (1)
	{
		if (first == second) /*same parent*/
		{
			r = (binary_tree_t *)first;
			break;
		}
		if (first->parent != NULL)
			first = first->parent;
		if (second->parent != NULL)
			second = second->parent;
	}
	return (r);
}
/**
 * binary_trees_ancestor_helper - helper function for binary_trees_ancestor()
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 * @first_depth: the depth of the node 'first'.
 * @second_depth: the depth of the node 'second'.
 * Description: this function deals with finding ancestor for two nodes that
 * don't have the same depth.
 * Return: pointer to the lowest common ancestor node of the two given nodes.
 * If no common ancestor was found, return NULL. If first or second is NULL,
 * return NULL.
 */
binary_tree_t *binary_trees_ancestor_helper(const binary_tree_t *first,
const binary_tree_t *second, size_t first_depth, size_t second_depth)
{
	binary_tree_t *r;

	/*Get them to the same level*/
	if (first_depth > second_depth)
	{
		while (1)
		{
			if (first_depth == second_depth)
				break;
			first = first->parent;
			first_depth -= 1;
		}
	} else if (second_depth > first_depth)
	{
		while (1)
		{
			if (second_depth == first_depth)
				break;
			second = second->parent;
			second_depth -= 1;
		}
	}
	/* One of the 2 children is the lowest common ancestor */
	if (first == second)
		return ((binary_tree_t *)first);
	while (1)
	{
		if (first->parent != NULL)
			first = first->parent;
		if (second->parent != NULL)
			second = second->parent;
		if (first == second)
		{
			r = (binary_tree_t *)first;
			break;
		}
	}
	return (r);
}
/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the node whose depth is to be measured.
 * Return: depth of the node. If tree is NULL the function returns 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->parent == NULL)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}
