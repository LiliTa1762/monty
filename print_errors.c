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
		fprintf(stderr, "Error: Can't open file %s\n", gb.ex_file);
	else if (strcmp(str, "invalid_instruction") == 0)
	{
		fprintf(stderr, "L%d: unknown instruction", gb.ex_line_number);
		fprintf(stderr, " %s\n", gb.ex_opcode);
	}
	else if (strcmp(str, "can't_malloc") == 0)
		fprintf(stderr, "Error: malloc failed\n");
	else if (strcmp(str, "int_is_not_int") == 0)
		fprintf(stderr, "L%d: usage: push integer\n", gb.ex_line_number);
	else if (strcmp(str, "can't_pint") == 0)
		fprintf(stderr, "L%d: can't pint, stack empty\n", gb.ex_line_number);
	else if (strcmp(str, "can't_pop") == 0)
		fprintf(stderr, "L%d: can't pop an empty stack\n", gb.ex_line_number);
	else if (strcmp(str, "can't_swap") == 0)
		fprintf(stderr, "L%d: can't swap, stack too short\n", gb.ex_line_number);
	else if (strcmp(str, "can't_add") == 0)
		fprintf(stderr, "L%d: can't add, stack too short\n", gb.ex_line_number);
	else if (strcmp(str, "can't_sub") == 0)
		fprintf(stderr, "L%d: can't sub, stack too short\n", gb.ex_line_number);
	else if (strcmp(str, "can't_div") == 0)
		fprintf(stderr, "L%d: can't div, stack too short\n", gb.ex_line_number);
	else if (strcmp(str, "can't_div_1") == 0)
		fprintf(stderr, "L%d: division by zero\n", gb.ex_line_number);
	else if (strcmp(str, "can't_mul") == 0)
		fprintf(stderr, "L%d: can't mul, stack too short\n", gb.ex_line_number);

	printf("aronnessonserri\n");
	free_stack(gb.ex_stack);
	printf("aronnessonserri\n");
	free(gb.buff);
	printf("aronnessonserri\n");
	if (gb.fp != NULL)
		fclose(gb.fp);
	exit(EXIT_FAILURE);
}

/**
 * to_verify - to verify the status of the struct
 *
 * Return: an int, 0 for stack or 1 for queue
*/
int to_verify(void)
{
	if (gb.ex_status == 's')
	{
		return (1);
	}

	return (0);
}
