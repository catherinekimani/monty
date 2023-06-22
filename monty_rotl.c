#include "monty.h"

/**
 * monty_rotl - Rotates the stack to the top
 * @stack: Pointer to the stack
 * @line_number: line number being executed
 */
void monty_rotl(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second_top;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	second_top = (*stack)->next;
	second_top->prev = NULL;

	while (top->next != NULL)
		top = top->next;

	top->next = *stack;

	(*stack)->next = NULL;
	(*stack)->prev = top;
	(*stack) = second_top;
}
