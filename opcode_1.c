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
	if (gb.ex_stack == NULL || gb.ex_queue == NULL)
	{
		print_error("can't_add");
	}

	if (gb.ex_stack->next == NULL && gb.ex_queue->prev == NULL)
	{
		print_error("can't_add");
	}

	if (to_verify())
	{
		gb.ex_stack->next->n += gb.ex_stack->n;
		gb.ex_stack = gb.ex_stack->next;
		free(gb.ex_stack->prev);
		return;
	}

	gb.ex_queue->prev->n += gb.ex_queue->n;
	gb.ex_queue = gb.ex_queue->prev;
	free(gb.ex_queue->next);

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

/**
 * _sub -  subtracts the top two elements of the stack
 * @stack: the pointer to the linked list
 * @line_number: where the instructions appear
 *
 * Return: void
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	if (gb.ex_stack == NULL || gb.ex_queue == NULL)
	{
		print_error("can't_sub");
	}

	if (gb.ex_stack->next == NULL && gb.ex_queue->prev == NULL)
	{
		print_error("can't_sub");
	}

	if (to_verify())
	{
		gb.ex_stack->next->n -= gb.ex_stack->n;
		gb.ex_stack = gb.ex_stack->next;
		free(gb.ex_stack->prev);
		return;
	}

	gb.ex_queue->prev->n -= gb.ex_queue->n;
	gb.ex_queue = gb.ex_queue->prev;
	free(gb.ex_queue->next);

	(void)stack;
	(void)line_number;
}

/**
 * _div -  divides the top two elements of the stack
 * @stack: the pointer to the linked list
 * @line_number: where the instructions appear
 *
 * Return: void
*/
void _div(stack_t **stack, unsigned int line_number)
{
	if (gb.ex_stack == NULL || gb.ex_queue == NULL)
	{
		print_error("can't_div");
	}

	if (gb.ex_stack->next == NULL && gb.ex_queue->prev == NULL)
	{
		print_error("can't_div");
	}

	if (to_verify())
	{
		if (gb.ex_stack->n == 0)
		{
			print_error("can't_div_1");
		}
		gb.ex_stack->next->n /= gb.ex_stack->n;
		gb.ex_stack = gb.ex_stack->next;
		free(gb.ex_stack->prev);
		return;
	}

	if (gb.ex_queue->n == 0)
	{
		print_error("can't_div_1");
	}
	gb.ex_queue->prev->n /= gb.ex_queue->n;
	gb.ex_queue = gb.ex_queue->prev;
	free(gb.ex_queue->next);

	(void)stack;
	(void)line_number;
}

/**
 * _mul -  multiplies the top two elements of the stack
 * @stack: the pointer to the linked list
 * @line_number: where the instructions appear
 *
 * Return: void
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	if (gb.ex_stack == NULL || gb.ex_queue == NULL)
	{
		print_error("can't_mul");
	}

	if (gb.ex_stack->next == NULL && gb.ex_queue->prev == NULL)
	{
		print_error("can't_mul");
	}

	if (to_verify())
	{
		gb.ex_stack->next->n *= gb.ex_stack->n;
		gb.ex_stack = gb.ex_stack->next;
		free(gb.ex_stack->prev);
		return;
	}

	gb.ex_queue->prev->n *= gb.ex_queue->n;
	gb.ex_queue = gb.ex_queue->prev;
	free(gb.ex_queue->next);

	(void)stack;
	(void)line_number;
}
