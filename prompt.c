#include "shell.h"

/**
 * prompt - Would print a custom prompt on screen
 *
 * Return: user input
 */
char *prompt(void)
{
	char *content;
	char *input_str;

	content = "cisfun$ ";
	write(1, content, _strlen(content));

	/*
	 * Taking user input
	 */
	input_str = input();
	if (input_str == NULL)
		exit(EXIT_FAILURE);
	return (input_str);
}
