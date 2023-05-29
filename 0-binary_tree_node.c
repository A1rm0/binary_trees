#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary node
 * @parent: parent node
 * @value: Value of the node
 * Return: the created binary node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_node;

	binary_node = malloc(sizeof(binary_tree_t));
	if (binary_node == NULL)
	{
		return (NULL);
	}
	binary_node->n = value;
	binary_node->parent = parent;
	binary_node->left = NULL;
	binary_node->right = NULL;
	return (binary_node);
}