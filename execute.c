#include "shell_header.h"

/**
 * exec - execute given command with its arguments
 * @argv: pointer with arguements tokenized
 * @string: string received from getline to free
 * @av: program name
 * Return: void
 */

void exec(char **argv, char *string, char **av)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror(av[0]);
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(av[0]);
		}
		free(string);
		fargv(argv);
		exit(0);
	}
	else
		wait(&status);
	free(string);
	fargv(argv);
}
