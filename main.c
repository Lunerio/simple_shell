#include "shell_header.h"

int main(void)
{
	char *string;
	char **argv = NULL;
	int status, glcheck, i;
	pid_t child_pid;
	size_t buf = 0;

	while (1)
	{
		string = NULL;

		p_prompt();

		glcheck = getline(&string, &buf, stdin);
		if (glcheck == -1)
		{
			if(glcheck == EOF)
			{
				free(string);
				return (0);
			}
			free(string);
			break;
		}
		if (string[0] == '\n')
		{
			free(string);
			continue;
		}

		if (_strcmp(string, "exit\n") == 0)
		{
			free(string);
			return (0);
		}
		if (_strcmp(string, "env\n") == 0)
		{
			free(string);
			_printenv();
			write(1, "\n", 1);
		}

		argv = tokenizer(string);

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (child_pid == 0)
		{
			if(execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
			}
			free(string);
			for (i = 0; argv[i] != NULL; i++)
			{
				free(argv[i]);
			}
			free(argv);
			return(0);
		}
		else
		{
			wait(&status);
		}
		free(string);
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
	return (0);
}
