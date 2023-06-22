#include "monty.h"

/**
 * monty_rotr - Rotates the stack to the bottom
 * @stack: Pointer to the stack
 * @line_number: line number being executed
 */
void monty_rotr(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *top;

	top = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (top->next)
		top = top->next;

	top->next = *stack;
	top->prev->next = NULL;
	top->prev = NULL;
	(*stack)->prev = top;
	(*stack) = top;
}
