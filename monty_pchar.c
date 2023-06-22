#include "monty.h"

/**
 * monty_pchar - prints the character at the top of the stack
 * @stack:Pointer to the stack
 * @line_number: line number being executed
*/
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;

	if (!top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(que.fd);
		free(que.ptr_content);
		monty_free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(que.fd);
		free(que.ptr_content);
		monty_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}
