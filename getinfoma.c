#include "shell.h"


/**
 * rm_info - info_t structure initialze
 * @infoma: Address structure
 */
void rm_info(info_t *infoma)
{
	infoma->arg = NULL;
	infoma->argv = NULL;
	infoma->path = NULL;
	infoma->argc = 0;
}

/**
 * ready_info - info_t structure initialze
 * @infoma: Address structure
 * @aargv: arguement vector
 */
void ready_info(info_t *infoma, char **aargv)
{
	int ai = 0;

	infoma->fname = aargv[0];
	if (infoma->arg)
	{
		infoma->argv = strtow(infoma->arg, " \t");
		if (!infoma->argv)
		{
			infoma->argv = malloc(sizeof(char *) * 2);
			if (infoma->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (ai = 0; infoma->argv && infoma->argv[ai]; ai++)
			;
		infoma->argc = ai;

		replace_alias(infoma);
		replace_vars(infoma);
	}
}

/**
 * open_info - frees info_t struct fields
 * @infoma: Address structure
 * @allfr: true if freeing all fields
 */
void open_info(info_t *infoma, int allfr)
{
	ffree(infoma->argv);
	infoma->argv = NULL;
	infoma->path = NULL;
	if (allfr)
	{
		if (!infoma->cmd_buf)
			free(infoma->arg);
		if (infoma->env)
			free_list(&(infoma->env));
		if (infoma->history)
			free_list(&(infoma->history));
		if (infoma->alias)
			free_list(&(infoma->alias));
		ffree(infoma->environ);
			infoma->environ = NULL;
		bfree((void **)infoma->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
