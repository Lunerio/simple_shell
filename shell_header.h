#ifndef PROTECT
#define PROTECT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>


int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
void _printenv(void);
char *_getenv(char *name);
char *_strdup(char *str);
char **tokenizer(char *string);
char *get_newline(char *string);
int p_prompt(void);
char *_strcpy(char *dest, char *src);
void exec(char **argv, char *string);
void fargv(char **argv);
int checker(int glcheck, char *string);

#endif
