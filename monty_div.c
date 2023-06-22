#include "monty.h"


/**
  *monty_div- divides the second top element by the top element
  *@head: The head
  *@count: The counter
  *
  */

void monty_div(stack_t **head, unsigned int count)
{
	stack_t *hd;
	int length = 0, res;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(que.fd);
		free(que.ptr_content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(que.fd);
		free(que.ptr_content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	res = hd->next->n / hd->n;
	hd->next->n = res;
	*head = hd->next;
	free(hd);
}
