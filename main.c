#include "shell_header.h"

int main(void)
{
	char *string = malloc(256);
	char **argv = malloc(64);
	int i, status;
	pid_t child_pid;

	for (i = 0; i < 64; i++)
		argv[i] = malloc(64);
	while (1)
	{
		write(1, "($) ", 4);
		string = get_newline(string);
		if (string == NULL)
		{
			write(1, "\n", 1); break;
		}
		if (string[0] == '\n')
		{
			write(1, "\n", 1); continue;
		}
		argv = tokenizer(string, argv);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error"); continue;
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error"); continue;
			}
		}
		else
			wait(&status);
	}
	free(string);
	for (i = 0; i < 64; i++)
		free(argv[i]);
	free(argv);
	return (0);
}
