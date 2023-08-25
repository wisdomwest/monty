#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct b_s_s - variables
 * @arg: value
 * @file: pointer
 * @content: line content
 * @lifi: flag
 */
typedef struct bus
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  b_t;
extern b_t x;
void push(stack_t **top, unsigned int data);
void pall(stack_t **top, unsigned int counter);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **head, unsigned int counter);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void free_s(stack_t *head);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
#endif
