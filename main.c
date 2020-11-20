#include "shell_header.h"

int main(void)
{
	char *string = NULL, *str = NULL;
	char **argv = NULL, **av = NULL;
	int status, a, i, fd = 0;
	pid_t child_pid;

	av = malloc(64);
	str = malloc(64);
	for (i = 0; i < 64; i++)
	{
		av[i] = malloc(64);
	}
	while (1)
	{
        	a = isatty(fd);
		if (a == 1)
		{
			write(1, "($) ", 4);
		}
		str = get_newline(string);
		if (str == NULL)
		{
			return (0);
		}
		if (str[0] == '\n')
			continue;
		argv = tokenizer(str, av);
		child_pid = fork();
		if (child_pid == -1)
		{
			free(str);
			for (i = 0; i < 64; i++)
			{
				free(av[i]);
			}
			free(av);
			perror("Error");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error"); return (1);
			}
			free(str);
			for (i = 0; i < 64; i++)
			{
				free(av[i]);
			}
			free(av);
			return (0);
		}
		else
		{
			wait(&status);
		}
	}
	free(str);
	for (i = 0; i < 64; i++)
	{
		free(av[i]);
	}
	free(av);
	return (0);
}
