#include "shell.h"

char *_strtok(char *str, char delim)
{
	/* Keeping track of the position in the string*/
	static char *token;
	char *end;
	/* If a new string is given, update the token*/
	if (str != NULL)
	{
		token = str;
	}
	else if (token == NULL)
	{
		/*No more tokens left*/
		return (NULL);
	}
	/*Find the next occurrence of the delimiter or the end of the string*/
	end = token;
	while (*end != '\0' && *end != delim)
	{
		++end;
	}
	/*If the token is empty, move to the next character*/
	if (token == end)
	{
		if (*token == '\0')
		{
			/*No more tokens left*/
			token = NULL;
			return (NULL);
		}
		++token;
		return (_strtok(NULL, delim));
	}
	/* Replace the delimiter with null terminator*/
	*end = '\0';
	/* Move to the next character after the delimiter*/
	token = end + 1;
	return (token);
}
