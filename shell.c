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
    }
    return (0);
}
