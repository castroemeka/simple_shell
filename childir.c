#include "shell.h"


/**
 * _therecords - the history list displayed, command line and preceded
 *              with line numbers, starting at 0.
 * @infomation: Potential arguments contained in the structure used for maint.
 *        Prototype constant function
 *  Return: Always 0
 */
int _therecords(info_t *infomation)
{
	print_list(infomation->records);
	return (0);
}

/**
 * unready_alias - sets alias to string
 * @infomation: Structure parameter
 * @aliasstr: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unready_alias(info_t *infomation, char *aliasstr)
{
	char *c, p;
	int wet;

	c = _strchr(aliasstr, '=');
	if (!c)
		return (1);
	p = *c;
	*c = 0;
	wet = delete_node_at_index(&(infomation->alias),
	get_node_index(infomation->alias, node_starts_with(infomation->alias, aliasstr, -1)));
	*c = p;
	return (wet);
}

/**
 * ready_alias - sets alias to string
 * @infomation: Structure parameter
 * @aliasstr: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int ready_alias(info_t *infomation, char *aliasstr)
{
	char *c;

	c = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++c)
		return (unready_alias(infomation, aliasstr));

	unready_alias(infomation, aliasstr);
	return (add_node_end(&(infomation->alias), aliasstr, 0) == NULL);
}

/**
 * printstr_alias - prints an alias string
 * @snode: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int printstr_alias(list_t *snode)
{
	char *a = NULL, *p = NULL;

	if (snode)
	{
		a = _strchr(snode->str, '=');
		for (p = snode->str; p <= a; p++)
		_putchar(*p);
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * ouralias - mimics the alias builtin (man alias)
 * @infomation: Potential arguments contained in the structure used for maint.
 *          constant function prototype.
 *  Return: Always 0
 */
int ouralias(info_t *infomation)
{
	int j = 0;
	char *c = NULL;
	list_t *snode = NULL;

	if (info->argc == 1)
	{
		snode = infomation->alias;
		while (snode)
		{
			printstr_alias(snode);
			snode = snode->next;
		}
		return (0);
	}
	for (j = 1; infomation->argv[j]; j++)
	{
		c = _strchr(infomation->argv[j], '=');
		if (c)
			ready_alias(infomation, info->argv[j]);
		else
			printstr_alias(snode_starts_with(info->alias, infomation->argv[j], '='));
	}

	return (0);
}
