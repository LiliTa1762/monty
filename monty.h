#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* EXTERN VARIABLES */
/**
 * struct varr - the struct with all variables
 * @ex_status: s (stack mode) or q (queue mode) depending of the mode
 * @ex_stack: pointer to the beginning or head of the linked list
 * @ex_queue: pointer to the end or tail of the linked list
 * @buff: the line to read
 * @ex_line_number: where the instruction appears
 * @ex_opcode: the command
 * @ex_file: pointer file type
 * @opcodes: struct to know what opcode to use
 * @fp: the monty file to use
 *
*/
typedef struct varr
{
	char ex_status;
	stack_t *ex_stack;
	stack_t *ex_queue;
	char *buff;
	int ex_line_number;
	char *ex_opcode;
	char *ex_file;
	instruction_t *opcodes;
	FILE *fp;
} gb_t;

extern gb_t gb;
gb_t gb;

/* MAIN */
int read_file(char *filename);
void find_opcode(instruction_t *opcodes, char *str);

/* OPCODE */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void s_or_q(stack_t **stack, unsigned int line_number);

/* DLINKEDLIST */
stack_t *add_right(stack_t **head, const int n);
stack_t *add_left(stack_t **head, const int n);
size_t print_stack(const stack_t *h);
void free_stack(stack_t *head);

/* PRINT_ERRORS */
int to_verify(void);
void print_error(char *str);

#endif /* MONTY_H */
