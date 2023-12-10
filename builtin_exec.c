#include "shell.h"
/**
 * builtin_exec - Toggles any of the builtin command and
 * places a call to execute them as required
 * @usr_cmd: array of strings of the user typed command
 * @_case: the case returned by the checker for executing builtin
 */
void builtin_exec(char **usr_cmd, int _case, char *untokenized_str_buf)
{
	if (_case > 0 && _case < 6)
	{
		switch (_case)
		{
			case 0:
				/*env call*/
				_cd();
				break;
			case 1:
				/*env call*/
				_env();
				break;
			case 2:
				/*exit call*/
				free(usr_cmd);
				free(untokenized_str_buf);
				_exit(EXIT_FAILURE);
				break;
			case 3:
				/*setenv call*/
				_setenv();
				break;
			case 4:
				/*unsetenv call*/
				_unsetenv();
				break;
			default:
				break;
		}
	}
}
