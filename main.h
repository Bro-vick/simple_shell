#ifndef shell
#define shell
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdbool.h>
bool isWildcard(char **args);
typedef struct ops
{
	char *op;
	int (*func)(char **ap);
} op_t;
char *_getline(void);
char **_strtok(char *line);
void findFile(char *filename);
int (*get_op_func(const char *s))(char **);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
#endif
