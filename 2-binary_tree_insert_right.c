#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts node in to the right
 * @parent: parent node
 * @value: value of the node
 * Return: the binary node ot NULL when it falls
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right != NULL)
	{
		binary_node->right = parent->right;
		parent->right->parent = binary_node;
	}
	parent->right = binary_node;
	return (binary_node);
}