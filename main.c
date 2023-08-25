#include "monty.h"
#include <stdio.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/**
  * main - main function
  * @argc: argument count
  * @argv: arguments
  * Return: 0
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read = 1;
	stack_t **stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		content = NULL;
		read = getline(&content, &size, file);
		count++;
		if (read > 0)
		{
			execute(content, stack, count, file);
		}
		free(content);
	}
	free_s(*stack);
	fclose(file);
	return (0);
}
