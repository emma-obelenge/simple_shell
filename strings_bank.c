#include "shell.h"

/**
 * _strlen - For computing the string length
 * @str: string taken as input
 *
 * Return: The string length is returned
 */

int _strlen(char *str)
{
	int len = 0;

	while (*(str + len) != 0)
	{
		len++;
	}
	return (len);
}
