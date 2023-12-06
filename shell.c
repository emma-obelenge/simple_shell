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
	printf("First print test: %s\n", usr_input);
	input_tokens = parser(usr_input);
	for (i = 0; input_tokens[i] != NULL; i++)
	    printf("%s", input_tokens[i]);
    }
    return (0);
}
