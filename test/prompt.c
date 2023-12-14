#include "shell.h"

/**
 * prompt - Would print a custom prompt on screen
 * Return: Returns the user typed string
 */
char *prompt(void)
{
	char *content;
	char *input_str;
	int str_len;

	content = "cisfun$ ";
	write(1, content, _strlen(content));

	/*Taking user input*/
	input_str = NULL;
	str_len = input(&input_str);
	if (str_len == -1)
	{
		free(input_str);
		_putchar('\n');
		_exit(EXIT_FAILURE);
	}
	if (*input_str == '\0')
	{
		free(input_str);
		return (NULL);
	}
	return (input_str);
}

/**
 * input - get user input from stdin
 *
 * Return: the user input
 */
int input(char **input_str)
{
	size_t n = 0;
	ssize_t len;
	int i;

	len = getline(input_str, &n, stdin);
	if (len == -1)
		return (-1);
	while (*(*input_str + i))
	{
		if (*(*input_str + i) == '\n')
		{
			*(*input_str + i) = '\0';
		}
		i++;
	}
	return (len);
}
