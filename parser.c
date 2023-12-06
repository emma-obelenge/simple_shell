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
    printf("line 18 in parser: %s\n", temp);
    temp_token = strtok(temp, delim);
    count = 1;
    while(temp_token != NULL)
    {
	temp_token = strtok(NULL, delim);
	count++;
    }
    printf("line 26 in parser: %d\n", count);

    /*Tokenizing user input*/
    tokens = malloc((++count) * sizeof(char *));
    if (tokens == NULL)
    {
	perror("Dynamic memory allocation has failed!");
	return (NULL);
    }
    tokens[i] = strtok(input, delim);
    for(i = 0; tokens[i] != NULL; i++)
	tokens[i] = strtok(NULL, delim);
    free(temp);
    return (tokens);
}
