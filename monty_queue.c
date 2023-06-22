#include "monty.h"

/**
 * monty_queue - sets the format of the data to a queue(FIFO)
 * @stack: Pointer to the stack
 * @line_number: line number being executed
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	que.f = 1;
}

/**
 * monty_add_queue - Adds a node to the tail of the stack
 * @stack: Pointer to the stack
 * @value: Value to be added to the stack
 */
void monty_add_queue(stack_t **stack, int value)
{
	stack_t *new_node, *last_node;

	last_node = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error\n");

	new_node->n = value;
	new_node->next = NULL;
	if (last_node)
	{
		while (last_node->next)
			last_node = last_node->next;
	}
	if (!last_node)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
