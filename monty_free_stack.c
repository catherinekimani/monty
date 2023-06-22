#include "monty.h"

/**
  *monty_free_stack - Frees list
  *@head: Head of stack
  *
  */

void monty_free_stack(stack_t *head)
{
	stack_t *pt;

	pt = head;
	while (head)
	{
		pt = head->next;
		free(head);
		head = pt;
	}
}
