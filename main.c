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
	int glcheck = 0, a = 0, cp = 0;
	size_t buf = 0;

	(void)ac;
	while (1)
	{
		string = NULL;
		cp = p_prompt();
		glcheck = getline(&string, &buf, stdin);
		a = checker(glcheck, string);
		if (a == 2)
			break;
		if (a == 3)
			continue;
		if (a == 1)
			perror(av[0]);
		if (a == 4)
			continue;
		if (a == 5)
			exit(0);
		else
		{
			argv = tokenizer(string);
			exec(argv, string, av);
		}
	}
	if (cp == 0)
		write(1, "\n", 1);
	return (0);
}
