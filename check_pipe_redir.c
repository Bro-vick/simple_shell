#include "main.h"
/**
 * isPipe - Pipe or redirection function
 * @args: list of char pointers
 * Return: booleen
 */
bool isPipe_redir(char **args)
{
	int i = 1;
	char *token;
	char *wildca ="|><";

	if (args == NULL)
		exit(EXIT_FAILURE);
	while (args[i])
	{
		token = args[i];
		for (int k = 0; token[k] != '\0'; k++)
		{
			for (int p = 0; wildca[p] != '\0'; p++)
			{
				if (token[k] == wildca[p])
					return (true);
			}
		}
		i++;
	}
	return (false);
}
