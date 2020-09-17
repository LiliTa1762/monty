#include "monty.h"

/**
 * print_error - Function to print errors
 * @str: string to print the error
 *
 * Return: the address of new element, or NULL
 */
void print_error(char *str)
{
	if (strcmp(str, "monty_file") == 0)
		fprintf(stderr, "Error: USAGE: monty file\n");
	else if (strcmp(str, "can't_open") == 0)
		fprintf(stderr, "Error: Can't open file %s\n", ex_file);
	else if (strcmp(str, "invalid_instruction") == 0)
		fprintf(stderr, "L%d: unknown instruction %s\n", ex_line_number, ex_opcode);
	else if (strcmp(str, "can't_malloc") == 0)
		fprintf(stderr, "Error: malloc failed\n");
	else if (strcmp(str, "int_is_not_int") == 0)
		fprintf(stderr, "L%d: usage: push integer\n", ex_line_number);
	else if (strcmp(str, "can't_pint") == 0)
		fprintf(stderr, "L%d: can't pint, stack empty\n", ex_line_number);
	else if (strcmp(str, "can't_pop") == 0)
		fprintf(stderr, "L%d: can't pop an empty stack\n", ex_line_number);
	else if (strcmp(str, "can't_swap") == 0)
		fprintf(stderr, "L%d: can't swap, stack too short\n", ex_line_number);
	else if (strcmp(str, "can't_add") == 0)
		fprintf(stderr, "L%d: can't add, stack too short\n", ex_line_number);

	exit(EXIT_FAILURE);
}

/**
 * to_verify - to verify the status of the struct
 *
 * Return: an int, 0 for stack or 1 for queue
 */
int to_verify(void)
{
	if (ex_status == 's')
	{
		return (1);
	}

	return (0);
}
