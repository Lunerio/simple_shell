#include "shell_header.h"

char *get_newline(char *string)
{
	char *cont = "\n";
	size_t buf = 0;
	int i = getline(&string, &buf, stdin);
	char *exit = "exit";
	char *env = "env";

	if (i == -1)
	{
		if (i == EOF)
		{
			write(1, "\n", 1);
			return (NULL);
		}
		perror("Error");
		return (cont);
	}

	if (string[0] == '\n')
	{
		return (string);
	}

	i = _strlen(string);
	string[i - 1] = '\0';

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
