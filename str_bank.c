#include "shell.h"

/**
 * _strlen - For computing the string length
 * @str: string taken as input
 *
 * Return: The string length is returned
 */

int _strlen(char *str)
{
	int len = 0;

	while (*(str + len) != 0)
	{
		len++;
	}
	return (len);
}

/**
 * _strdup - Creates a duplicate of the inputed string
 * @str: parameter taken by the function
 *
 * Return: pointer to a dynamically allocated memory of
 * duplicated strings.
 */
char *_strdup(char *str)
{
    char *s;
    unsigned int size;
    if (str == NULL)
	return (NULL);
    size = _strlen(str) + 1;
    
    /*Allocating dynamic memory for string*/
    s = (char *)malloc(size);
    
    /*Condition for allocation that did not succeed*/
    if (s == NULL)
	return (NULL);
    
    /*Copy contents of str into s*/
    return (_strcpy(s, str));
}

/**
 * _strcpy - Copies the string pointed by src into dest
 * @dest: Destination for the string copy
 * @src: Source of the string to be copied
 * Return: return dest value
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
	dest[i] = src[i];
	i++;
    }
    dest[i] = '\0';
    return (dest);
}
