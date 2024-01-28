#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)stack;

	if (!(top && top->prev))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(line);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}

	top->prev->n += top->n;

	temp = top->prev;
	free(top);
	top = temp;
	if (top != NULL)
		top->next = NULL;
}

/**
 * nop - do nothing
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
