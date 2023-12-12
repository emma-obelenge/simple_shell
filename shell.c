#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always zero (success)
 */
int main(void)
{

	while (true)
	{
		strArr_int tokensNcount;
		char *usr_input;
		char *found_path;
		int builtin_value, checker_report;

		usr_input = NULL;
		found_path = NULL;
		builtin_value = -1;
		usr_input = prompt();
		tokensNcount = parser(usr_input);
		if (tokensNcount.tokens = NULL)
			_exit(EXIT_FAILURE);
		checker_report = checker(tokensNcount, &builtin_value, &found_path);
		if (checker_report >= 0 && checker_report < 5)
		{
			builtin_exec(tokensNcount.tokens, builtin_value, usr_input);
			call_free(tokensNcount.tokens);

		}
		else if(checker_report == 6)
			printf("execve will be called here");
			/*cmd_exec(tokensNcount.tokens, found_path);*/
		else
		{
			_putsXnewline("tokensNcount.tokens");
			_putsXnewline(": command not found\n");
			free(tokensNcount.tokens);
			free(usr_input);
		}
		/*free(tokensNcount.tokens);*/
		free(usr_input);
		free(found_path);
		usr_input = NULL;
		found_path = NULL;
	}
	return (0);
}
