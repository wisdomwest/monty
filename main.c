#include "monty.h"

/**
  * main - main function
  * @argc: argument counter
  * @argv: arguments
  * Return: 0
  */

int main(int argc, char *argv[])
{
	char line[1000];
	int line_number = 1;
	stack_t *stack = NULL;
	FILE *file;
	char *token = strtok(line, " $\n");
	int value = atoi(token);
	
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		while (token != NULL)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " \n\t");
				if (token == NULL)
				{
					fprintf(stderr, "L%d: Missing value for push\n", line_number);
					return (EXIT_FAILURE);
				}
				push(&stack, value);
			}
			else if (strcmp(token, "pop") == 0)
			{
				pop(&stack, line_number);
			}
			else if (strcmp(token, "add") == 0)
			{
				add(&stack, line_number);
			}
			else if (strcmp(token, "nop") == 0)
			{
				nop();
			}
			else if (strcmp(token, "swap") == 0)
			{
				swap(&stack, line_number);
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
	fclose(file);
	return (EXIT_SUCCESS);
}
