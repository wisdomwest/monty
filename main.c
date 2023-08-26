#include "monty.h"

/**
 * main - entry point
 * @argc: argc num
 * @argv: argv
 * Return: result
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	int result = handle(file);

	fclose(file);
	return (result);
}
