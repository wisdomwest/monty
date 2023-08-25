#include "monty.h"

b_t x = {NULL, NULL, NULL, 0};

/**
* execute - executes
* @stack: head
* @counter: ccount
* @file: poiner
* @content: line
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push},
				{"pall", pall},
				{"pop", pop},
				{"swap", swap},
				{"add", add},
				{"nop", nop},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
	{
		free(content);
		return (0);
	}
	x.arg = strtok(NULL, " \n\t");
	free(op);
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			free(content);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_s(*stack);
		exit(EXIT_FAILURE);
	}
	free(content);
	return (1);
}
