#include "monty.h"
/**
  *monty_pint- prints the value at the top of the stack
  *@head: The head
  *@count: Line counter
  *
  */
void monty_pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(que.fd);
		free(que.ptr_content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
