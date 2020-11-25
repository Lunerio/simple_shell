#include "shell_header.h"

/**
 * checker - checks the conditions from getline
 * @glcheck: int from getline return
 * @string: string from getline in order to free
 * Return: 1 for error, 2 on exit condition, 3 in new line, 4 for printenv
 */

int checker(int glcheck, char *string)
{
	int i;

	if (glcheck == -1)
	{
		if (glcheck == EOF)
		{
			free(string);
			return (2); /*for exiting*/
		}
		perror("Error");
		free(string);
		return (1); /*for error*/
	}
	if (string[0] == '\n')
	{
		free(string);
		return (3); /*print new line */
	}
	if (_strcmp(string, "exit\n") == 0)
	{
		free(string);
		return (5); /*for exiting*/
	}
	if (_strcmp(string, "env\n") == 0)
	{
		free(string);
		_printenv();
		return (4);
	}
	for (i = 0; string[i] != '\0'; i++)
	{
	}
	if (string[i - 2] == 32)
	{
		free(string);
		return (3);
	}
	return (0);
}
