#include "shell_header.h"

int main(void)
{
	char *string;
	char **argv = NULL;
	int glcheck;
	size_t buf = 0;

	while (1)
	{
		string = NULL;
		p_prompt();
		glcheck = getline(&string, &buf, stdin);
		if (glcheck == -1)
		{
			if (glcheck == EOF)
			{
				free(string);
				write(1, "\n", 1);
				break;
			}
			perror("Error");
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
		exec(argv, string);
	}
	return (0);
}
