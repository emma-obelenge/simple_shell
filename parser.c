#include "shell.h"
/**
 * inputIsNull - For returning NULL when input equals NULL
 * Return: Returns struct type data with array of strings = NULL
 */
void inputIsNull(void)
{
	printf("input is NULL");
	parse.tokens = NULL;
	parse.tok_count = 0;
	return (parse);
}
/**
 * parser - Breaks the user input into tokens
 * @input: the user typed string
 *
 * Return: Function returns pointer to a dynamic
 * array of strings entered by the user, else NULL.
 */
struct strArr_int parser(char *input)
{
	struct strArr_int parse;
	char **tokens;
	int i, count;
	char *temp_token, *temp;
	char delim[] = " ";

	if (input == NULL)
		return (inputIsNull());

	/*Getting number of tokens*/
	temp = _strdup(input);
	temp_token = strtok(temp, delim);
	count = 0;
	while (temp_token != NULL)
	{
		count++;
		temp_token = strtok(NULL, delim);
	}

	/*Tokenizing user input*/
	tokens = malloc((count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Dynamic memory allocation has failed!");
		parse.tokens = NULL;
		parse.tok_count = 0;
		return (parse);
	}
	i = 0;
	tokens[i] = strtok(input, delim);
	while (tokens[i] != NULL)
	{
		i++;
		tokens[i] = strtok(NULL, delim);
	}
	free(temp);
	parse.tokens = tokens;
	parse.tok_count = count;
	return (parse);
}
