#include "shell.h"

/**
 * _strlen - For computing the string length
 * @str: string taken as input
 *
 * Return: The string length is returned
 */

int _strlen(const char *str)
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
		_exit(EXIT_FAILURE);

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
/**
 * _strapp - Appends the content of src to dest
 * @dest: pointer to array of char where the src str will be appended
 * @src: pointer to the str to be appended
 * @dest_len: size of the dest array including the extra space for src
 */
void _strapp(char *dest, char *src, int dest_len)
{
	int i, counter;

	counter = 0;
	while (*(dest + counter) != '\0')
		counter++;
	for (i = 0; src[i] != '\0'; i++)
	{
		if (counter < dest_len)
			dest[counter++] = src[i];
	}
	dest[counter] = '\0';
}

/**
 * _strcmp - Function for comparing two strings
 * @str1: the first string input
 * @str2: the second string input
 *
 * Return: would return 0 when the strings match, and -1
 * on a reverse scenario.
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}
		i++;
	}
	/* Check if both strings have the same length*/
	if (str1[i] != '\0' || str2[i] != '\0')
	{
		return (-1);
	}
	return (0);
}
