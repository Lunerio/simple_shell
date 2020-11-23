#include "shell_header.h"

char **tokenizer(char *string, char *value)
{
	char *toc = NULL, *cm = NULL;
	int i = 0, j = 0, toklen = 0;
	char **argv = NULL;

	argv = malloc(sizeof(char *) * 64);

	ch = chcommand(value, string);

	j = _strlen(string);
	string[j - 1] = '\0';

	toc = strtok(string, " ");
	while (toc != NULL)
	{
		toklen = _strlen(toc);
		argv[i] = malloc(toklen + 1);
		_strcpy(argv[i], toc);
		toc = strtok(NULL, " ");
		i++;
	}
	argv[0] = cm;
	argv[i] = NULL;
	return (argv);
}
