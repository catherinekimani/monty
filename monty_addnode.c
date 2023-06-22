#include "monty.h"

/**
 * monty_addnode - add node
 * @head: head
 * @n: Value
 *
*/
void monty_addnode(stack_t **head, int n)
{

	stack_t *newNode, *pt;

	pt = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{ printf("Error\n");
		exit(0); }
	if (pt)
		pt->prev = newNode;
	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}
