#include "monty.h"

void pall(stack_t *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}