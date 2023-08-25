#include "monty.h"
/**
  * pall - pall
  * @stack: stack
  * @counter: counter
  * Return: void
  */

void pall(stack_t **stack, unsigned int counter)
{
	 stack_t *current;
	 (void)counter;

	 current = *stack;

	 while (current != NULL)
	 {
		 printf("%d\n", current->n);
		 current = current->next;
	 }
}
