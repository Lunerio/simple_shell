#include "shell_header.h"

char *get_newline(void)
{
	char *cont = "\n";

	int i = getline(&string, &buf, stdin);

	if (i == -1)
	{
		if (i == EOF)
		{
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

	if(_strcmp(string, "env") == 0)
	{
		_printenv();
		return (cont);
	}

	return (string);
}
