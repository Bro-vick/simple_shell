#include "main.h"
/**
 * get_op_func - a function for print character
 * specifier
 * @s: string pointer
 * Return: pointer to a funtion
 */
int (*get_op_func(const char *s))(char **)
{
	int i;
	op_t ops[] = {
		{"cd", lsh_cd},
		{"help", lsh_help},
		{"exit", lsh_exit},
		{NULL, NULL}
	};

	i = 0;
	while (ops[i].op != NULL)
	{
		if (s == ops[i].op)
			return (ops[i].func);
		i++;
	}
	return (NULL);
}
