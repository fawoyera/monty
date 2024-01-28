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
