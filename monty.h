#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct que_s - structure to carry values
 * @val: value
 * @fd: file descriptor
 * @ptr_content: content
 *@f: Integer value
 */
typedef struct que_s
{
	char *val;
	FILE *fd;
	char *ptr_content;
	int f;
} que_t;

extern que_t que;
/*prototypes*/
void monty_free_stack(stack_t *head);
void monty_push(stack_t **head, unsigned int count);
void monty_pall(stack_t **head, unsigned int count);
void monty_addnode(stack_t **head, int n);
void monty_pint(stack_t **head, unsigned int count);
void monty_pop(stack_t **head, unsigned int count);
void monty_swap(stack_t **head, unsigned int count);
void monty_add(stack_t **head, unsigned int count);
void monty_nop(stack_t **head, unsigned int count);
void monty_div(stack_t **head, unsigned int count);
void monty_sub(stack_t **head, unsigned int count);
int execute_opcode(char *line_content,
		   stack_t **stack, unsigned int line_number, FILE *fd);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack,
		__attribute__((unused)) unsigned int line_number);
void monty_rotr(stack_t **stack,
		__attribute__((unused)) unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_add_queue(stack_t **stack, int value);
#endif /*MONTY_H*/
