#include "monty.h"

/**
 * _push - function to add an item in the stack
 * @stack: pointer to the data struct
 * @line_number: where the instructions appear
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	char *token = NULL;
	int num = 0, i = 0;

	token = strtok(NULL, " \t\n");

	if (token == NULL)
	{
		print_error("int_is_not_int");
	}

	while (token[i])
	{
		if (token[i] > 57 || token[i] < 48)
		{
			print_error("int_is_not_int");
		}
		i++;
	}

	num = atoi(token);

	if (to_verify())
	{
		temp = add_left(&ex_stack, num);

		if (temp != NULL)
		{
			ex_stack = temp;
		}
		return;
	}
	temp = add_right(&ex_queue, num);
	if (temp != NULL)
		ex_queue = temp;

	(void)stack;
	(void)line_number;
}

/**
 * _pall - Prints all elements of the stack
 * @stack: the pointer to the linked list
 * @line_number: where the instructions appear
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	print_stack(ex_stack);
	(void)stack;
	(void)line_number;
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: the pointer to the linked list
 * @line_number: where the instructions appear
 *
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (ex_stack == NULL || ex_queue == NULL)
	{
		print_error("can't_pint");
	}

	if (to_verify())
	{
		printf("%d\n", ex_stack->n);
		return;
	}
	printf("%d\n", ex_queue->n);

	(void)stack;
	(void)line_number;
}

/**
 * _pop - removes the top element of the stack
 * @stack: the pointer to the linked list
 * @line_number: where the instructions appear
 *
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (ex_stack == NULL || ex_queue == NULL)
	{
		print_error("can't_pop");
	}
	if (to_verify())
	{
		temp = ex_stack;
		if (temp->next != NULL)
		{
			temp->next->prev = NULL;
			ex_stack = ex_stack->next;
			free(temp);
		}
		else
		{
			free(ex_stack);
			ex_stack = NULL;
			ex_queue = NULL;
		}
		return;
	}
	temp = ex_queue;
	if (temp->prev != NULL)
	{
		temp->prev->next = NULL;
		ex_queue = ex_queue->prev;
		free(temp);
	}
	else
	{
		free(ex_queue);
		ex_stack = NULL;
		ex_queue = NULL;
	}
	(void)stack;
	(void)line_number;
}
/**
 * _swap - swaps the top two elements of the stack
 * @stack: the pointer to the linked list
 * @line_number: where the instructions appear
 *
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if (ex_stack == NULL || ex_queue == NULL)
	{
		print_error("can't_swap");
	}

	if (ex_stack->next == NULL && ex_queue->prev == NULL)
	{
		print_error("can't_swap");
	}

	if (to_verify())
	{
		temp = ex_stack->n;
		ex_stack->n = ex_stack->next->n;
		ex_stack->next->n = temp;

		return;
	}

	temp = ex_queue->n;
	ex_queue->n = ex_queue->prev->n;
	ex_queue->prev->n = temp;

	(void)stack;
	(void)line_number;
}
