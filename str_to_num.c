#include "monty.h"

int _power(int, int);

/**
 * str_to_num - convert a string to an integer
 * @s: string input
 * Return: int
 */
long int str_to_num(char *s)
{
	int i = 0, j, n = 0;
	long int m, sum = 0;

	while (*(s + i) != '\0')
		i++;
	for (j = i - 1; j >= 0; j--)
	{
		if ((int)*(s + j) < (int)'0' || (int)*(s + j) > (int)'9')
			return (-1);
		m = ((int) *(s + j) - (int) '0');
		m = m * _power(10, n);
		sum = sum + m;
		n++;
	}
	return (sum);
}

/**
 * _power - return base num raise to the power of exponent num
 * @base: the base num
 * @exponent: the exponent num
 * Return: int
 */
int _power(int base, int exponent)
{
	int result = 1;
	int raise;

	for (raise = exponent; raise > 0; raise--)
	{
		result = result * base;
	}
	return (result);
}

