#include "shell.h"
/**
 * parser - Breaks the user input into tokens
 * @input: the user typed string
 *
 * Return: Function returns pointer to a dynamic
 * array of strings entered by the user, else NULL.
 */
char **parser (char *input)
{
    char **tokens;
    int i, count;
    char *temp_token, *temp;
    char delim[] = " ";
    
    /*Getting number of tokens*/
    temp = _strdup(input);
    temp_token = strtok(temp, delim);
    count = 0;
    while(temp_token != NULL)
    {
	count++;
	temp_token = strtok(NULL, delim);
    }

    /*Tokenizing user input*/
    tokens = malloc((count + 1) * sizeof(char *));
    if (tokens == NULL)
    {
	perror("Dynamic memory allocation has failed!");
	return (NULL);
    }
    i = 0;
    tokens[i] = strtok(input, delim);
    while(tokens[i] != NULL)
    {
	i++;
	tokens[i] = strtok(NULL, delim);
    }
    free(temp);
    return (tokens);
}
