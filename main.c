#include "main.h"
/**
 * main - main function
 * @argc: integer numb of argument
 * @argv: list of argument
 * @envp: environment variable
 * Return: success or failure
 */
int main(int __attribute__ ((unused)) argc, char __attribute__ ((unused)) *argv[], char *envp[])
{
	char *line;
	struct stat st;
	char **tokens;
	int p;
	bool isWildca, isPiped;
	char *command;
	int (*func)(char **);

	line = _getline();	/* returns the read lines */
	if (line == NULL)
	{
		printf("getline returned NULL");
		exit(EXIT_FAILURE);
	}
	tokens = _strtok(line);	/* tokenize lines and save in memory*/
	if (tokens == NULL)
	{
		printf("_strtok returned NULL");
		exit(EXIT_FAILURE);
	}
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
	{
		printf("command doesn't exist %s \n", command);
		exit(EXIT_FAILURE);
	}
	main(p, tokens, envp);
	return (EXIT_SUCCESS);
}
