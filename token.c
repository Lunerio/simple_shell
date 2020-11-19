#include "shell_header.h"

char **tokenizer(char *string, char **argv)
{
	char *toc;
	int i = 0;

	toc = strtok(string, " ");

	while (toc)
	{
		argv[i] = toc;
		toc = strtok(NULL, " ");
		i++;
	}

	argv[i] = NULL;

	return (argv);
}
