#include "monty.h"
/**
  * free_s - free
  * @head: head
  * Return:void
  */

void free_s(stack_t *head)
{
	stack_t *current;

	current = head;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
