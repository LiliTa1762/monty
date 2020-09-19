#include "monty.h"

/**
 * init_varr - initializes the variables
 * @opcod: the structure that contains the opcommands
 *
 * Return: void
*/
void init_varr(instruction_t *opcod)
{
	gb.ex_status = 's';
	gb.ex_stack = NULL;
	gb.ex_queue = NULL;
	gb.buff = NULL;
	gb.ex_line_number = 0;
	gb.ex_opcode = NULL;
	gb.ex_file = NULL;
	gb.opcodes = opcod;
	gb.fp = NULL;
}

/**
 * main - calls to the read_file function
 * @argc: number of arguments
 * @argv: executable file and file name
 *
 * Return: 0
*/
int main(int argc, char **argv)
{
	instruction_t opcodes[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add},
		{"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"stack", s_or_q},
		{"queue", s_or_q},
		{NULL, NULL}
	};

	init_varr(opcodes);
	if (argc != 2)
		print_error("monty_file");
	printf("aronnessonserri\n");
	gb.ex_file = argv[1];

	read_file(gb.ex_file);

	free_stack(gb.ex_stack);
	free(gb.buff);

	return (0);
}

/**
 * read_file - try read the file and call each command
 * @filename: the file name
 *
 * Return: 0
*/
int read_file(char *filename)
{
	size_t buff_size = 0;
	ssize_t gline = 0;
	char *token;

	gb.fp = fopen(filename, "r");
	if (!gb.fp)
		print_error("can't_open");

	gline = getline(&gb.buff, &buff_size, gb.fp);

	while (gline >= 0)
	{
		gb.ex_line_number++;
		token = strtok(gb.buff, " \t\n");
		gb.ex_opcode = token;
		if (token != NULL)
		{
			if ((strcmp(token, "nop")) != 0 && token[0] != '#')
				find_opcode(gb.opcodes, token);
		}
		gline = getline(&gb.buff, &buff_size, gb.fp);
	}

	fclose(gb.fp);

	return (0);
}

/**
 * find_opcode - checks if the opcode exist
 * @opcodes: the struct with the opcodes
 * @str: pointer
 *
 * Return: void
*/
void find_opcode(instruction_t *opcodes, char *str)
{
	int i;

	if (str == NULL)
		return;
	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(str, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(&gb.ex_stack, gb.ex_line_number);
			return;
		}
	}
	if (opcodes[i].opcode == NULL)
		print_error("invalid_instruction");
}
