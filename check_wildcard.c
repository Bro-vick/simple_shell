#include "main.h"
/**
 * isWildcard - wildcard function
 * @args: list of char pointers
 * Return: booleen
 */
bool isWildcard(char **args)
{
	int i = 1;
	char *token;
	char *wildca = "*$?.'\s''\d''\w'";

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
