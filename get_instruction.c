#include "monty.h"
/**
 * get_instruction - select the correct function based on opcode passed
 * @s: the opcode
 *
 * Return: pointer to required function
 */
void (*get_instruction(char *s))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].opcode != NULL)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
