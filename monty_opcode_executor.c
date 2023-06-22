#include "monty.h"

/**
 * execute_opcode - executes the specified opcode
 * @stack: Pointer to the head of the stack
 * @line_number: Current Line number
 * @fd: Pointer to monty file being executed
 * @line_content: content of the current line
 *
 * Return: If the opcode is found and successfully executed,
 *         return 0 else return 1 to indicate error
*/
int execute_opcode(char *line_content,
			stack_t **stack,
			unsigned int line_number,
			FILE *fd)
{
	instruction_t opcode_list[] = {
		{"push", monty_push}, {"pall", monty_pall}, {"pint", monty_pint},
		{"pop", monty_pop}, {"swap", monty_swap}, {"add", monty_add},
		{"nop", monty_nop}, {"sub", monty_sub}, {"div", monty_div},
		{"mul", monty_mul}, {"mod", monty_mod}, {"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"queue", monty_queue},
		{"stack", monty_stack},
		{NULL, NULL},
	};

	unsigned int idx = 0;
	char *opc;

	opc = strtok(line_content, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	que.val = strtok(NULL, " \n\t");

	while (opcode_list[idx].opcode && opc)
	{
		if (strcmp(opc, opcode_list[idx].opcode) == 0)
		{
			opcode_list[idx].f(stack, line_number);
			return (0);
		}
		idx++;
	}
	if (opc && opcode_list[idx].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opc);
		fclose(fd);
		free(line_content);
		monty_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
