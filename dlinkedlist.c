#include "monty.h"

/**
 * add_right - Function to add a new node at the end of a list
 * @head: pointer to head
 * @n: int
 * Return: the address of new element, or NULL
 */
stack_t *add_right(stack_t **head, const int n)
{
	stack_t *new = NULL, *last = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		print_error("can't_malloc");

	new->n = n;

	new->next = NULL;
	new->prev = NULL;

	if (*head == NULL)
	{
		(*head) = new;
		ex_stack = new;
		return (new);
	}

	last = (*head);

	while (last->next != NULL)
		last = last->next;

	last->next = new;

	new->prev = last;

	return (new);
}

/**
 * add_left - add a new node at the beginning
 * @head: double pointer to head
 * @n: a int variable
 * Return: the address of a new element or NULL
 */
stack_t *add_left(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		print_error("can't_malloc");

	new->n = n;

	new->next = (*head);
	new->prev = NULL;

	if ((*head) == NULL)
		ex_queue = new;

	if ((*head) != NULL)
		(*head)->prev = new;

	(*head) = new;
	return (new);
}

/**
 * print_stack - prints all the elements of a list
 * @h: head of the list
 * Return: the number of nodes
 */
size_t print_stack(const stack_t *h)
{
	int i = 0;

	for (i = 0; h != NULL; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}

/**
 * free_stack - function to free list
 * @head: pointer to head
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
