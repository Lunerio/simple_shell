#include "shell_header.h"

/**
 * tokenizer - tokenize the string from getline and asign them to argv
 * @string: string to tokenize
 * Return: argv with tokens
 */

char **tokenizer(char *string)
{
	char *toc = NULL;
	int i = 0, toklen = 0;
	char **argv = NULL;

	argv = malloc(sizeof(char *) * 64);

	toc = strtok(string, " ");
	while (toc != NULL)
	{
		toklen = _strlen(toc);
		argv[i] = malloc(toklen + 1);
		_strcpy(argv[i], toc);
		toc = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
