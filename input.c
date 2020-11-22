#include "shell_header.h"
char *builtin(char *string)
{
	char *cont = "\n";
        char *exit = "exit";
	char *env = "env";

	if (_strcmp(string, exit) == 0)
	{
		return (NULL);
	}
	if(_strcmp(string, env) == 0)
	{
		_printenv();
		return (cont);
	}
	return (string);
}
