#include "monty.h"

/**
  *monty_add- addsd the top two elements of the stack.
  *@head: The head
  *@count: Counter
  *
  */

void monty_add(stack_t **head, unsigned int count)
{
	stack_t *hd;
	int length = 0;
	int pt;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(que.fd);
		free(que.ptr_content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	pt = hd->n + hd->next->n;
	hd->next->n = pt;
	*head = hd->next;
	free(hd);
}
