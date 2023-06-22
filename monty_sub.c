#include "monty.h"


/**
  *monty_sub- subtracts the top element of the stack
  *@head: The head
  *@count: Counter
  *
  */
void monty_sub(stack_t **head, unsigned int count)
{
	stack_t *pt;
	int res, node;

	pt = *head;
	for (node = 0; pt != NULL; node++)
		pt = pt->next;
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(que.fd);
		free(que.ptr_content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	pt = *head;
	res = pt->next->n - pt->n;
	pt->next->n = res;
	*head = pt->next;
	free(pt);
}
