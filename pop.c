#include "monty.h"
void pop(stack_t **stack, int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *top = *stack;
    *stack = top->next;

    if (*stack != NULL)
    {
        (*stack)->prev = NULL;
    }

    free(top);
}