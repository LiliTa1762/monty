#include "monty.h"

/**
 * _add -  adds the top two elements of the stack
 * @stack: the pointer to the linked list
 * @line_number: where the instructions appear
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{

	if (ex_stack == NULL || ex_queue == NULL)
	{
		print_error("can't_add");
	}

	if (ex_stack->next == NULL && ex_queue->prev == NULL)
	{
		print_error("can't_add");
	}

	if (to_verify())
	{
		ex_stack->next->n += ex_stack->n;
		ex_stack = ex_stack->next;
		free(ex_stack->prev);
		return;
	}

	ex_queue->prev->n += ex_queue->n;
	ex_queue = ex_queue->prev;
	free(ex_queue->next);

	(void)stack;
	(void)line_number;
}

/**
 * _nop -  doesn't do anything
 * @stack: the pointer to the linked list
 * @line_number: where the instructions appear
 *
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
