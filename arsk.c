#define "shell.h"


/**
 * his_cmd - Executable command
 * @info: The structure information
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int his_cmd(info_t *info, char *path)
{
	struct tart strr;

	(void)info;
	if (!path || tart(path, &strr))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * lupe_chars - duplicate the characters
 * @pathstart: PATH string
 * @begin: starting the index
 * @end: stopping the index
 *
 * Return: pointer to the new buffer
 */
char *lupe_chars(char *pathstart, int begin, int end)
{
	static char buf[1024];
	int u = 0, y = 0;

	for (y = 0, u = start; u < stop; u++)
		if (pathstart[u] != ':')
			buf[y++] = pathstart[u];
	buf[y] = 0;
	return (buf);
}

/**
 * looking_path - finds this cmd in the PATH string
 * @info: The structure information
 * @pathstart: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *looking_path(info_t *info, char *pathstart, char *cmd)
{
	int u = 0, cured_pus = 0;
	char *oath;

	if (!pathstart)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstart[u] || pathstart[u] == ':')
		{
			oath = lupe_chars(pathstr, cured_pus, u);
			if (!*path)
				_strcat(oath, cmd);
			else
			{
				_strcat(oath, "/");
				_strcat(oath, cmd);
			}
			if (his_cmd(info, oath))
				return (oath);
			if (!pathstart[u])
				break;
			cured_pus = u;
		}
		u++;
	}
	return (NULL);
}
