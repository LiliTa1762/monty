#include "monty.h"

char ex_status = 's';
stack_t *ex_stack = NULL;
stack_t *ex_queue = NULL;
char *buff = NULL;
int ex_line_number = 0;
char *ex_opcode = NULL;
char *ex_file = NULL;
instruction_t opcodes[] = {
	{"push", _push}, {"pall", _pall},
	{"pint", _pint}, {"pop", _pop},
	{"swap", _swap},
	{"add", _add},
	{NULL, NULL}
};
FILE *fp;

/**
 * main - calls to the read_file function
 * @argc: number of arguments
 * @argv: executable file and file name
 *
 * Return: 0
*/
int main(int argc, char **argv)
{
	if (argc != 2)
		print_error("monty_file");

	ex_file = argv[1];

	read_file(ex_file);

	free_stack(ex_stack);
	free(buff);

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

	fp = fopen(filename, "r");
	if (!fp)
		print_error("can't_open");

	gline = getline(&buff, &buff_size, fp);

	while (gline >= 0)
	{
		ex_line_number++;
		token = strtok(buff, " \t\n");
		ex_opcode = token;
		if (token != NULL)
		{
			if ((strcmp(token, "nop")) != 0)
				find_opcode(opcodes, token);
		}
		gline = getline(&buff, &buff_size, fp);
	}

	fclose(fp);

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
			opcodes[i].f(&ex_stack, ex_line_number);
			return;
		}
	}
	if (opcodes[i].opcode == NULL)
		print_error("invalid_instruction");
}
