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

/**
 * cmd_is_path - vets the existence of usr cmd
 * as an executable path
 * @cmd: pathname of file
 * Return: 1 on success, otherwise 0.
 */
int cmd_is_path(const char *cmd)
{
	if (access(cmd, F_OK | X_OK) == -1)
		return (1);
	return (0);
}

void _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'd')
		{
			int value = va_arg(args, int);

			printf("%d", value);
			/*move format to the next specifier*/
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 's')
		{
			char *value = va_arg(args, char *);
			printf("%s", value);
			/*move format to the next specifier*/
			format += 2;
		}
		else
		{
			putchar(*format);
			format++;
		}
	}
	va_end(args);
}
