#include "monty.h"

/**
 * monty_mod - computes the rest of the division of the second top
 *              element of the stack by top element of the stack
 * @stack: double ptr to the stack
 * @line_number: current line number
 *
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *second_top;
	int stack_len = 0, result;

	second_top = *stack;

	while (second_top)
	{
		second_top = second_top->next;
		stack_len++;
	}

	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(que.fd);
		free(que.ptr_content);
		monty_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	second_top = *stack;
	if (second_top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(que.fd);
		free(que.ptr_content);
		monty_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = second_top->next->n % second_top->n;
	second_top->next->n = result;
	*stack = second_top->next;
	free(second_top);
}
