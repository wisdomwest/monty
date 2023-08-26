#include "monty.h"

/**
 * pall - reads a stack
 * @stack: first argument
 * Return:nothing
 */
void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
