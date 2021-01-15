#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - returns new_node on success, NULL on fail.
 * @parent: The parrent of the new_node
 * @value: The value of the new_node
 * Return: address of new_node, or NULL if malloc fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
