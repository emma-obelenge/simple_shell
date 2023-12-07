#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always zero (success)
 */
int main(void)
{
    char *usr_input;
    char **input_tokens;
    int i;

    while (true)
    {
	usr_input = prompt();
	input_tokens = parser(usr_input);
	i = 0;
	while(input_tokens[i] != NULL)
	{
	    printf("token %d is: %s\n", i, input_tokens[i]);
	    i++;
	}
	free(input_tokens);
    }
    return (0);
}
