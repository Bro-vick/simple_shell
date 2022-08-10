#include "main.h"
/**
 * main - main function
 * @argc: integer numb of argument
 * @argv: list of argument
 * @envp: environment variable
 * Return: success or failure
 */
int main(int argc, char *argv[], char *envp[])
{
	char *line;
	char **tokens;

	line = _getline();	/* returns the read lines */
	if (getline == NULL)
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
	
	return (EXIT_SUCCESS);
}
