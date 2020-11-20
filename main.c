#include "shell_header.h"

int main(void)
{
	char *string = malloc(512);
	char **argv = malloc(512);
	int status;
	pid_t child_pid;
	char *str = NULL;

	while (1)
	{
		write(1, "($) ", 4);
		str = get_newline(string);
		if (str == NULL)
			break;
		if (str[0] == '\n')
			continue;
		argv = tokenizer(str, argv);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error"); continue;
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error"); exit(25); continue;
			}
			break;
		}
		else
			wait(&status);
	}
	free(string);
	free(argv);
	return (0);
}
