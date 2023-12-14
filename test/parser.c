#include "shell.h"

/**
 * parser - Breaks the user input into tokens
 * @input: the user typed string
 *
 * Return: Function returns pointer to a dynamic
 * array of strings entered by the user, else NULL.
 */
char **parser(char *input)
{
	char **tokens;
	int i, count;
	char delim[] = " ";

	if (input == NULL)
		return (NULL);

	/*Getting number of tokens*/
	count = tok_count(input);

	/*Tokenizing user input*/
	tokens = malloc((count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Dynamic memory allocation for parser failed!");
		_exit(EXIT_FAILURE);
	}
	i = 0;
	tokens[i] = _strdup(strtok(input, delim));
	while (tokens[i] != NULL)
	{
		i++;
		tokens[i] = _strdup(strtok(NULL, delim));
	}
	free(input);
	return (tokens);
}

/**
 * tok_count - counts the number of tokens in usr_input
 * @input: the user typed string
 *
 * Return: returns the number of tokens counteed
 */
int tok_count(char *input)
{
	char *temp_token, *temp;
	int count;
	char delim[] = " ";
	
	temp = _strdup(input);
	temp_token = strtok(temp, delim);
	count = 0;
	while (temp_token != NULL)
	{
		count++;
		temp_token = strtok(NULL, delim);
	}
	free(temp);
	temp = NULL;
	return (count);
}
