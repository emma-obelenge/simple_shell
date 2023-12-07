#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always zero (success)
 */
int main(void)
{
	struct strArr_int input_tokens;
	char *usr_input;

	while (true)
	{
		usr_input = prompt();
		input_tokens = parser(usr_input);
		free(input_tokens.tokens);
		free(usr_input);
	}
	return (0);
}
