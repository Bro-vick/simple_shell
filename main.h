#ifndef shell
#define shell
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
typedef struct ops
{
	char *op;
	int (*func)(char **ap);
} op_t;
char *_getline(void);
char *_strtok(char *line);
void findFile(char *filename);
#endif
