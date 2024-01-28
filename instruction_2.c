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

/**
 * sub - subtract the top element from the second top 
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)stack;

	if (!(top && top->prev))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(line);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}

	top->prev->n -= top->n;

	temp = top->prev;
	free(top);
	top = temp;
	if (top != NULL)
		top->next = NULL;
}

/**
 * _div - divide the second top element by the top 
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)stack;

	if (!(top && top->prev))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(line);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(line);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}

	top->prev->n /= top->n;

	temp = top->prev;
	free(top);
	top = temp;
	if (top != NULL)
		top->next = NULL;
}

/**
 * mul - multiply the second top element with the top 
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)stack;

	if (!(top && top->prev))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(line);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}

	top->prev->n *= top->n;

	temp = top->prev;
	free(top);
	top = temp;
	if (top != NULL)
		top->next = NULL;
}

/**
 * mod - remainder when the second top element is divided by top 
 * @stack: the given stack node
 * @line_number: line number in file
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)stack;

	if (!(top && top->prev))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(line);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{	
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(line);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}

	top->prev->n %= top->n;

	temp = top->prev;
	free(top);
	top = temp;
	if (top != NULL)
		top->next = NULL;
}
