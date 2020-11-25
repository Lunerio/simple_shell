#include "shell_header.h"

/**
 * main - calls functions for the simple shell
 * @av: list of arguments on execution
 * @ac: arguments count
 * Return: returns 0 when finishes
 */

int main(int ac, char **av)
{
	char *string, **argv = NULL;
	int glcheck, a, cp;
	size_t buf = 0;

	(void)ac;

	while (1)
	{
		string = NULL;
		cp = p_prompt();
		glcheck = getline(&string, &buf, stdin);

		a = checker(glcheck, string);
		if (a == 2)
			exit(0);
		if (a == 3)
			write(1, "\n", 1);
		if (a == 1)
			perror(av[0]);
		if (a == 4)
		{
			free(string);
			continue;
		}
		else
		{
			argv = tokenizer(string);
			exec(argv, string, av);
		}
	}
	if (cp == 0)
	{
		write(1, "\n", 1);
	}
	return (0);
}
