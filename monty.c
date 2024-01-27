#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "monty.h"

/**
 * main - monty byte code interpreter
 * @argc: argument count
 * @argv: array of arguments
 *
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL, *line_cpy, *opcode, *arg;
	long int *argument;
	size_t n = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL, *temp;
	void (*inst)(stack_t **, unsigned int);

	top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty %s\n", "file");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &n, file) != -1)
	{
		line_number++;
		line_cpy = strdup(line);
		opcode = strtok(line_cpy, " \n\t");
		if (opcode == NULL)
		{
			free(line);
			free(line_cpy);
			line = NULL;
			n = 0;
			continue;
		}

		inst = get_instruction(opcode);
		if (inst == NULL)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_number, opcode);
			free(line);
			free(line_cpy);
			exit(EXIT_FAILURE);
		}

		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \n\t");
			if (arg == NULL)
			{
				fprintf(stderr, "L%d: usage: %s integer\n", line_number, opcode);
				free(line);
				free(line_cpy);
				exit(EXIT_FAILURE);
			}
			argument = str_to_num(arg);
			if (argument == NULL)
			{
				
				fprintf(stderr, "L%d: usage: %s integer\n", line_number, opcode);
				free(line);
				free(line_cpy);
				exit(EXIT_FAILURE);
			}
			stack = malloc(sizeof(stack_t *));
			if (stack == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				free(line);
				free(line_cpy);
				exit(EXIT_FAILURE);
			}
			stack->n = (int)*argument;
		}
		
		inst(&stack, line_number);
		free(line);
		free(line_cpy);

		line = NULL;
		n = 0;
	}
	free(line);

	while (top)
	{
		temp = top->prev;
		free(top);
		top = temp;
	}

	fclose(file);

	return (0);
}
