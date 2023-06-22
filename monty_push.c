#include "monty.h"

/**
  *monty_push-add node to the stack
  *@head: Head pointer
  *@count: Counter
  *
  */
void monty_push(stack_t **head, unsigned int count)
{
	int x, idx = 0, flags = 0;

	if (que.val)
	{
		if (que.val[0] == '-')
			idx++;
		for (; que.val[idx] != '\0'; idx++)
		{
			if (que.val[idx] > 57 || que.val[idx] < 48)
				flags = 1;
		}
		if (flags == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(que.fd);
			free(que.ptr_content);
			monty_free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(que.fd);
		free(que.ptr_content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	x = atoi(que.val);

	if (que.f == 0)
		monty_addnode(head, x);
	else
		monty_add_queue(head, x);
}
