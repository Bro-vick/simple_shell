#include "main.h"
/*
 * loop - processing
 * Return: void
 */
void shell_loop(void)
{
	char *line;
	struct stat st;
	char **tokens;
	int p, status;
	bool isWildca, isPiped;
	char *command;
	int (*func)(char **);

	do {
		printf("$ ");
		line = _getline();	/* returns the read lines */
		if (line == NULL)
			errormessage("getline returned Null");
		tokens = _strtok(line);	/* tokenize lines and save in memory*/
		if (tokens == NULL)
			errormessage("tokens returned Null");
		status = shell_execute(tokens);
		isWildca = isWildcard(tokens);	/* check for wildcard char */
		if (isWildca)
		{
			/* pass in the wildcard globbing*/
		}
		command = tokens[0];
		for (p = 0; tokens[p] != NULL; p++)	/* get length of tokens */
			;
		--p;
		func = get_op_func(command); /* builtins functions returned */
		if (func)
		{
			isPiped = isPipe_redir(tokens); /* please handle if piped */
			if (isPiped)
			{
				/* pass in the piped function */
			}
			func(tokens);
		}
		else if (stat(command, &st) == 0 && st.st_mode & S_IXUSR)
		{
			isPiped = isPipe_redir(tokens); /* please handle if piped */
			execute(p, tokens, envp); /*condition above check exec file*/
		}
		else
			printf("command doesn't exist %s \n", command);
		free(line);
		free(tokens);
	} while (status);
}
/*
 * errormessage - prints the error
 * @s: the string message
 * Return: void
 */
void errormessage(char *s)
{
	printf("! %s \n", s);
	exit(EXIT_FAILURE);
}
