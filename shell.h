#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>


#define DELIM " \t\n"
extern char **environ;

char *read_line(void);
char **tokenizer(char *line);
int main(int argc, char **argv);

char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);

int starts_with(const char *str, const char *prefix);
void _puts(const char *str);
int _putchar(char c);

#endif
