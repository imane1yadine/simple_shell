#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

/* enami_strings.c */
int _strlen(char *);
char *_strcat(char *, char *);
void _puts(char *);
int _putchar(char);
char *_strcpy(char *, char *);

/* enami_strings2.c */
char *_strdup(const char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);

#endif
