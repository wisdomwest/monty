#include "monty.h"

/**
  * pop - pop
  * @stack: stack
  * @line_number: line
  * Return: void
  */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = top->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(top);
}
