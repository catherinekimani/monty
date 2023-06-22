#include "monty.h"

/**
  *monty_pall- prints all the values on the stack
  *@head: The head of the stack
  *@count: counter
  *
  */

void monty_pall(stack_t **head, unsigned int count)
{
	stack_t *hd;
	(void)count;

	hd = *head;
	if (hd == NULL)
		return;

	while (hd)
	{
		printf("%d\n", hd->n);
		hd = hd->next;
	}
}
