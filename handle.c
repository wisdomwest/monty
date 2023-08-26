#include "monty.h"

/**
 * handle - process the Monty language file
 * @file: FILE pointer to the input file
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE on error
 */
int handle(FILE *file)
{
	stack_t *stack = NULL;

	char line[1000], *token;

	int line_number = 1;

	while (fgets(line, sizeof(line), file))
	{
		token = strtok(line, " $\n");

		while (token)
		{
			if (!strcmp(token, "push"))
			{
				token = strtok(NULL, " \t");
				if (!token)
				{
					fprintf(stderr, "L%d: Missing value for push\n", line_number);
					return (EXIT_FAILURE);
				}
				push(&stack, atoi(token));
			}
			else if (strcmp(token, "pop") == 0)
			{
				pop(&stack, line_number);
			}
			else if (strcmp(token, "pall") == 0)
			{
				pall(stack);
			}
			else
			{
				fprintf(stderr, "L%d: unknown opcode %s\n", line_number, token);
				return (EXIT_FAILURE);
			}
			token = strtok(NULL, " $\n");
		}
		line_number++;
	}
	return (EXIT_FAILURE);
}
