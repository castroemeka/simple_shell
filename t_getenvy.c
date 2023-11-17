#include "shell.h"


/**
 * _ourenv - print the current env
 * @infoma: Potential arguments contained in the structure used for maint.
 *          Prototype constant function
 * Return: Always 0
 */
int _ourenv(info_t *infoma)
{
	print_list_str(infoma->env);
	return (0);
}

/**
 * _ourenv - get the values of the environment variables
 * @infoma: Potential arguments contained in the structure used for maint.
 * @same: env var name
 *
 * Return: the value
 */
char *_ourenv(info_t *infoma, const char *same)
{
	list_t *snode = infoma->env;
	char *pi;

	while (snode)
	{
		pi = starts_with(snode->str, same);
		if (pi && *pi)
			return (pi);
		snode = snode->next;
	}
	return (NULL);
}

/**
 * _ourreadyenv - Initialize a new env variable,
 *             or modify an existing one
 * @infoma: Potential arguments contained in the structure used for maint.
 *        constant function prototype.
 *  Return: Always 0
 */
int _ourreadyenv(info_t *infoma)
{
	if (infoma->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (readyenv(infoma, infoma->argv[1], infoma->argv[2]))
		return (0);
	return (1);
}

/**
 * _ourunreadyenv - Remove the env variable
 * @infoma: Potential arguments contained in the structure used for maint.
 *        constant function prototype.
 * Return: Always 0
 */
int _ourunreadyenv(info_t *infoma)
{
	int bi;

	if (infoma->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (bi = 1; bi <= infoma->argc; bi++)
		_ourunreadyenv(infoma, infoma->argv[bi]);

	return (0);
}

/**
 * _copulateEnvList - populate environment linked list
 * @infoma: Potential arguments contained in the structure used for maint.
 *          constant function prototype.
 * Return: Always 0
 */
int _copulateEnvList(info_t *infoma)
{
	list_t *snode = NULL;
	size_t bi;

	for (bi = 0; envy[bi]; bi++)
		add_node_end(&snode, envy[bi], 0);
	infoma->env = snode;
	return (0);
}
