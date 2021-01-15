#include <stdlib.h>
#include "binary_trees.h"
/**
 * make_heap - makes into max heap, needs some work :(
 * @new_node: the new node to evaluate
 * @value: the value of the new node
 * Return: a pointer to the node that contains the original value
 */
heap_t *make_heap(heap_t *new_node, int value)
{
	int temp = new_node->parent->n;

	if (value > new_node->parent->n)
	{
		new_node->parent->n = value;
		new_node->n = temp;
		return (new_node->parent);
	}
	else
	{
		new_node->n = value;
		return (new_node);
	}
}
/**
 * possition_node - positions the node in the heap
 * @head: the head of the nodes we are working with, not always the root
 * @new_node: the new node to insert into the heap
 * @value: the value of the new node
 * Return: same as above
 */
heap_t *possition_node(heap_t *head, heap_t *new_node, int value)
{
	heap_t *new_head;
	heap_t *node_pointer;

	new_head = head;
	node_pointer = make_heap(new_node, value);
	if (new_head->left == NULL)
	{
		new_head->left = new_node;
		new_node->parent = new_head;
		new_node->left = NULL;
		new_node->right = NULL;
		return (node_pointer);
	}
	else if (new_head->right == NULL)
	{
		new_head->right = new_node;
		new_node->parent = new_head;
		new_node->left = NULL;
		new_node->right = NULL;
		return (node_pointer);
	}
	else
	{
		if (new_head->parent)
			new_head = new_head->parent->left;
		if (!new_head->left->right)
			return (possition_node(new_head->left, new_node, value));
		else
			return (possition_node(new_head->right, new_node, value));
	}
	return (node_pointer);
}
/**
 * heap_insert - inserts a node into a heap
 * @root: the root of the entire heap
 * @value: the value to insert
 * Return: the node that contains the new value
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	heap_t *head;

	/* left_or_right: 0 for left 1 for right */
	head = *root;

	/* Step 0: make a new node if no memory avaliable return NULL */
	new_node = binary_tree_node(head, value);

	/* Step 1: position the new node */
	if (head == NULL)
	{
		*root = new_node;
		head = new_node;
		new_node->n = value;
		new_node->parent = NULL;
		new_node->left = NULL;
		new_node->right = NULL;
		return (new_node);
	}
	else
		return (possition_node(head, new_node, value));
}