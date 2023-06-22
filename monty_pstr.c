#include "monty.h"

/**
 * monty_pstr - prints the str starting at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: line number being executed
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = *stack;

	while (top)
	{
		if (top->n > 127 || top->n <= 0)
			break;
		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
}
