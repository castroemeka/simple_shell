#include "shell.h"


/**
 * _envy - the strings of array in the env should be returned
 * @infoma: Potential arguments contained in the structure used for maint.
 *          constant function prototype.
 * Return: Always 0
 */
char **_envy(info_t *infoma)
{
	if (!info->envy || infoma->env_changed)
	{
		info->envy = list_to_strings(infoma->env);
		info->env_changed = 0;
	}

	return (infoma->envy);
}

/**
 * _unreadyenv - Remove the env variable
 * @infoma: Potential arguments contained in the structure used for maint.
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @vary: the string env var property
 */
int _unreadyenv(info_t *infoma, char *vary)
{
	list_t *snode = infoma->env;
	size_t bi = 0;
	char *pi;

	if (!snode || !vary)
		return (0);

	while (snode)
	{
		pi = starts_with(snode->str, vary);
		if (pi && *pi == '=')
		{
			infoma->env_changed = delete_node_at_index(&(infoma->env), bi);
			bi = 0;
			snode = infoma->env;
			continue;
		}
		snode = snode->next;
		bi++;
	}
	return (infoma->env_changed);
}

/**
 * readyenv - Initialize the  new env variable,
 *             or modify an existing one
 * @infoma: Potential arguments contained in the structure used for maint.
 *        constant function prototype.
 * @vary: the string env var property
 * @varvalue: the string env var value
 *  Return: Always 0
 */
int readyenv(info_t *infoma, char *vary, char *varvalue)
{
	char *buff = NULL;
	list_t *snode;
	char *pi;

	if (!vary || !varvalue)
		return (0);

	buff = malloc(_strlen(vary) + _strlen(varvalue) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, vary);
	_strcat(buff, "=");
	_strcat(buff, varvalue);
	snode = infoma->env;
	while (snode)
	{
		pi = starts_with(snode->str, vary);
		if (pi && *pi == '=')
		{
			free(snode->str);
			snode->str = buff;
			infoma->env_changed = 1;
			return (0);
		}
		snode = snode->next;
	}
	add_node_end(&(infoma->env), buff, 0);
	free(buff);
	infoma->env_changed = 1;
	return (0);
}
