#include "shell.h"
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
	char delim[] = "\r\n\t ";

	if (input == NULL)
	{
		printf("input is NULL");
		parse.tokens = NULL;
		parse.tok_count = 0;
		return (parse);
	}
	temp = _strdup(input);
	temp_token = strtok(temp, delim);
	count = 0;

	while (temp_token != NULL)
	{
		count++;
		temp_token = strtok(NULL, delim);
	}
	tokens = malloc((count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
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
