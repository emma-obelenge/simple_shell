#include "shell.h"

/**
 * prompt - Would print a custom prompt on screen
 * Return: Returns the user typed string
 */
char *prompt(void)
{
	char *content;
	char *input_str;

	content = "cisfun$ ";
	write(1, content, _strlen(content));

	/*Taking user input*/
	input_str = input();
	if (input_str == NULL)
		_exit(EXIT_FAILURE);
	return (input_str);
}
