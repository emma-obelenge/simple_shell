#include "shell.h"

/**
 * prompt - Would print a custom prompt on screen
 */
void prompt(void)
{
	char *content;
	char *input_str;

	content = "cisfun$ ";
	write(1, content, _strlen(content));

	input_str = input();
	if (input_str == NULL)
	{
		free(input_str);
		exit(EXIT_FAILURE);
	}

}
