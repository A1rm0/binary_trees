#include "binary_trees.h"

/**
 * heapify_down - Performs the heapify down operation.
 * @root: Double pointer to the root node of the heap.
 */
void heapify_down(heap_t **root)
{
	heap_t *parent = *root;
	heap_t *child = NULL;
	int value;

	while (parent->left != NULL)
	{
		child = parent->left;

		if (parent->right != NULL && parent->right->n > child->n)
			child = parent->right;

		if (parent->n >= child->n)
			break;

		value = parent->n;
		parent->n = child->n;
		child->n = value;

		parent = child;
	}
}

/**
 * get_last_node - Gets the last level-order node of the heap.
 * @root: Pointer to the root node of the heap.
 *
 * Return: Pointer to the last level-order node, or NULL if the heap is empty.
 */
heap_t *get_last_node(heap_t *root)
{
	queue_t *queue = NULL;
	heap_t *node = NULL;

	queue = enqueue(queue, root);

	while (queue != NULL)
	{
		node = dequeue(&queue);

		if (node->left != NULL)
			queue = enqueue(queue, node->left);

		if (node->right != NULL)
			queue = enqueue(queue, node->right);
	}

	return (node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: Value stored in the root node, or 0 if the extraction fails.
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node = NULL;
	heap_t *parent = NULL;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;

	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last_node = get_last_node(*root);
	parent = last_node->parent;

	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;

	(*root)->n = last_node->n;

	free(last_node);
	heapify_down(root);

	return (value);
}
