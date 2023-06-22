#include "monty.h"
que_t que = {NULL, NULL, NULL, 0};

/**
  *main- Entry point
  *@argc: Args count
  *@argv: Args array
  *
  *Return: 0 success
  *
  */

int main(int argc, char *argv[])
{
	char *ptr_content;
	FILE *fd;
	size_t size = 0;
	ssize_t rd_line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	que.fd = fd;
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (rd_line > 0)
	{
		ptr_content = NULL;
		rd_line = getline(&ptr_content, &size, fd);
		que.ptr_content = ptr_content;
		count++;

		if (rd_line > 0)
		{
			execute_opcode(ptr_content, &stack, count, fd);
		}
		free(ptr_content);
	}
	monty_free_stack(stack);
	fclose(fd);

	return (0);
}
