#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always zero (success)
 */
int main(void)
{
	struct strArr_int tokensNcount;
	char *usr_input;
	char *found_path;
	int builtin_value, checker_report;

	while (true)
	{
		builtin_value = -1;
		usr_input = prompt();
		tokensNcount = parser(usr_input);
		checker_report = checker(tokensNcount, &builtin_value, &found_path);
		if (checker_report > 0 && checker_report < 6)
			builtin_exec(tokensNcount.tokens, builtin_value, usr_input);
		else if (checker_report == 0)
			/*cmd_exec(tokensNcount.tokens, found_path);*/
			;
		else
		{
			_putsXnewline("tokensNcount.tokens");
			_putsXnewline(": command not found\n");
			free(tokensNcount.tokens);
			free(usr_input);
		}
		free(tokensNcount.tokens);
		free(usr_input);
		free(found_path);
	}
	return (0);
}
