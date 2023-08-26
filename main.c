#include "monty.h"


// void push(stack_t **stack, int value)
// {
//     stack_t *new_node = malloc(sizeof(stack_t));
//     if (new_node == NULL)
//     {
//         fprintf(stderr, "Error: malloc failed\n");
//         exit(EXIT_FAILURE);
//     }

//     new_node->n = value;
//     new_node->prev = NULL;
//     new_node->next = *stack;

//     if (*stack != NULL)
//     {
//         (*stack)->prev = new_node;
//     }

//     *stack = new_node;
// }

// void pop(stack_t **stack, int line_number)
// {
//     if (*stack == NULL)
//     {
//         fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
//         exit(EXIT_FAILURE);
//     }

//     stack_t *top = *stack;
//     *stack = top->next;

//     if (*stack != NULL)
//     {
//         (*stack)->prev = NULL;
//     }

//     free(top);
// }
// void swap(stack_t **stack, int line_number) {
//     if (*stack == NULL || (*stack)->next == NULL) {
//         fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
//         exit(EXIT_FAILURE);
//     }

//     int temp = (*stack)->n;
//     (*stack)->n = (*stack)->next->n;
//     (*stack)->next->n = temp;
// }
// void add(stack_t **stack, int line_number) {
//     if (*stack == NULL || (*stack)->next == NULL) {
//         fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
//         exit(EXIT_FAILURE);
//     }

//     (*stack)->next->n += (*stack)->n;
//     pop(stack, line_number);
// }
// void nop() {}

// void pall(stack_t *stack)
// {
//     while (stack != NULL)
//     {
//         printf("%d\n", stack->n);
//         stack = stack->next;
//     }
// }

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    stack_t *stack = NULL;
    char line[1000];

    int line_number = 1;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *token = strtok(line, " $\n");
        while (token != NULL)
        {
            if (strcmp(token, "push") == 0)
            {
                token = strtok(NULL, " \t"); // Get the next token (value)
                if (token == NULL)
                {
                    fprintf(stderr, "L%d: Missing value for push\n", line_number);
                    return EXIT_FAILURE;
                }
                int value = atoi(token);
                push(&stack, value);
            }
            else if (strcmp(token, "pop") == 0)
            {
                pop(&stack, line_number);
            }
            else if (strcmp(token, "add") == 0) {
                add(&stack, line_number);
            }
            else if (strcmp(token, "nop") == 0) {
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
                return EXIT_FAILURE;
            }
            token = strtok(NULL, " $\n"); // Get the next token
        }
        line_number++;
    }

    fclose(file);
    return EXIT_SUCCESS;
}
