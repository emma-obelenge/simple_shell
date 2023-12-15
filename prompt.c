#include "shell.h"

/**
 * prompt - Would print a custom prompt on screen
 * Return: Returns the user typed string
 */
char *prompt(void)
{
	const char *content = "cisfun$ ";
	char *input_str = NULL;
	int str_len;
	ssize_t bytes;

	bytes = write(1, content, _strlen(content));
	if (bytes == -1)
	{
		perror("prompt display failed");
		return (NULL);
	}
	/*Taking user input*/
	str_len = input(&input_str);
	if (str_len == -1)
	{
		free(input_str);
		_exit(EXIT_FAILURE);
	}
	if (*input_str  == '\0')
	{
		free(input_str);
		input_str = NULL;
		return (NULL);
	}
	return (input_str);
}

/**
 * input - get user input from stdin
 * @input_str: the string typed by the user
 * Return: the user input
 */
int input(char **input_str)
{
	size_t n = 0;
	ssize_t len;
	int i;

	i = 0;
	len = getline(input_str, &n, stdin);
	if (len == -1)
		return (-1);
	while ((*(*input_str + i) != '\0'))
	{
		if (*(*input_str + i) == '\n')
		{
			(*input_str)[i] = '\0';
			break;
		}
		i++;
	}
	return (i);
}
