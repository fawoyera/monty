#include "monty.h"
/**
 * push - add a data to top of stack
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	if (top == NULL)
	{
		top = node;
		top->prev = NULL;
		top->next = NULL;
		return;
	}
	top->next = node;
	node->prev = top;
	node->next = NULL;
	top = node;
}

/**
 * pall - print all the values on the stack
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = top;
	(void)line_number;
	(void)stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}

/**
 * pint - print the value at the top of the stack
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = top;
	(void)stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(line);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}

/**
 * pop - remove the top element of the stack
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(line);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}

	temp = top->prev;
	free(top);
	top = temp;
	if (top != NULL)
		top->next = NULL;
}
