#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts node to the left
 * @parent: parent node
 * @value: value of the node
 * Return: the binary node ot NULL when it falls
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	binary_node = binary_tree_node(parent, value);
	if (binary_node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		binary_node->left = parent->left;
		parent->left->parent = binary_node;
	}
	parent->left = binary_node;
	return (binary_node);
}
