#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always zero (success)
 */
int main(void)
{
	char *usr_input;
	struct strArr_int input_tokens;
	int i, j;

	while (true)
	{
		usr_input = prompt();
		input_tokens = parser(usr_input);

		if (strcmp(input_tokens.tokens[0], "exit") == 0)
		{
			free(usr_input);
			free(input_tokens.tokens);
			exit(EXIT_SUCCESS);
		}
		i = 0;

		while (input_tokens.tokens[i] != NULL)
		{
			printf("token %d is: %s\n", i, input_tokens.tokens[i]);
			i++;
		}
		printf("token count is: %d\n", input_tokens.tok_count);

		free(input_tokens.tokens);
		free(usr_input);
	}
	return (0);
}
