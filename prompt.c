#include "shell.h"

/**
 * prompt - Would print a custom prompt on screen
 */
void prompt(void)
{
	char *content;

	content = "cisfun$";
	write(1, content, _strlen(content));

	/*
	 * Here we can call our getline function,
	 * so as to halt the continous printing
	 * of the prompt. I.e, the shell will
	 * now wait for the user to type in
	 * something before it proceeds
	 */
}
