#include "monty.h"

/**
 * s_or_q - changes the mode
 * @stack: head of the linked list or the beginning
 * @line_number: where the instruction appears
 * Return: void
 */
void s_or_q(stack_t **stack, unsigned int line_number)
{
	if (strcmp(gb.ex_opcode, "stack") == 0)
	{
		gb.ex_status = 's';
	}
	else
	{
		gb.ex_status = 'q';
	}
	(void)stack;
	(void)line_number;
}
