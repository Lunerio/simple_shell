#ifndef PROTECT
#define PROTECT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

int _strlen(char *s);
list_t *add_node_end(list_t **head, const char *str);
int _strcmp(char *s1, char *s2);
void _printenv(void);
char *_getenv(const char *name);
int _strncmp(char *s1, char *s2, size_t n);
char *_strdup(char *str);
char **tokenizer(char *string, char **argv);
char *get_newline(void);

#endif
