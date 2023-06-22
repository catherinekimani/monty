#include "monty.h"

/**
  *monty_pop- removes the top element of the stack.
  *@head: Head
  *@count: Counter
  *
  */

void monty_pop(stack_t **head, unsigned int count)
{
	stack_t *hd;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(que.fd);
		free(que.ptr_content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	*head = hd->next;
	free(hd);
}
