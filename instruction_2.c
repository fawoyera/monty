#include "monty.h"

/**
 * pchar - print the char at the top of the stack
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = top;
	(void)stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(line);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(line);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", temp->n);
}

/**
 * pstr - print the string starting at the top of the stack
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = top;
	(void)line_number;
	(void)stack;

	if (top == NULL)
	{
		printf("\n");
		return;
	}

	while (temp)
	{
		if (temp->n == 0 || temp->n < 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->prev;
	}
	printf("\n");
}

/**
 * rotl - rotate the stack to the top
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *temp;
	(void)stack;
	(void)line_number;

	if (top == NULL || top->prev == NULL)
		return;

	last = top;
	top = top->prev;
	top->next = NULL;

	temp = top;
	while (temp && temp->prev)
	{
		temp = temp->prev;
	}
	temp->prev = last;
	last->next = temp;
	last->prev = NULL;
}

/**
 * rotr - rotate the stack to the bottom
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last, *temp;
	(void)stack;
	(void)line_number;

	if (top == NULL || top->prev == NULL)
		return;

	temp = top;
	while (temp && temp->prev)
	{
		last = temp;
		temp = temp->prev;
	}
	last->prev = NULL;
	first = temp;
	first->prev = top;
	first->next = NULL;
	top = first;
}
