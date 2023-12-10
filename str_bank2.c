#include "shell.h"

/**
 * _putsXnewline - prints a string without new line to stdout
 * @str: string to print
 */
void _putsXnewline(char *str)
{
	while (*str != '\0')
		_putchar(*str++);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strncmp - compares n number of characters between two strings
 * @s1: first string input
 * @s2: second string input
 * @n: number of characters to be compared
 *
 *Return: 0 if the comparism matches
 * <1 or >1 if otherwise
 */
int _strncmp(char *s1, char *s2, int n)
{
	while(n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}





