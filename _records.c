#include "shell.h"


/**
 * src_records_file - get the file history
 * @infoma: Structure parameter
 *
 * Return: allocated string containg the history file
 */

char *src_records_file(info_t *infoma)
{
	char *buff, *edir;

	edir = _getenv(infoma, "HOME=");
	if (!edir)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, edir);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * note_records - creates a file, or appends to an existing file
 * @infoma: Structure parameter
 *
 * Return: 1 on success, else -1
 */
int note_records(info_t *infoma)
{
	ssize_t fad;
	char *fname = src_records_file(infoma);
	list_t *snode = NULL;

	if (!fname)
		return (-1);

	fad = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fname);
	if (fad == -1)
		return (-1);
	for (snode = infoma->history; snode; snode = snode->next)
	{
		_putsfd(snode->str, fad);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fad);
	close(fad);
	return (1);
}

/**
 * note_records - read the history from file
 * @infoma: Structure parameter
 *
 * Return: histcount on success, 0 otherwise
 */
int note_records(info_t *infoma)
{
	int bi, wast = 0, linecheck = 0;
	ssize_t fad, rdlen, fsize = 0;
	struct stat st;
	char *buff = NULL, *fname = note_records_file(infoma);

	if (!fname)
		return (0);

	fad = open(fname, O_RDONLY);
	free(fname);
	if (fad == -1)
		return (0);
	if (!fstat(fad, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (fsize + 1));
	if (!buff)
		return (0);
	rdlen = read(fad, buff, fsize);
	buff[fsize] = 0;
	if (rdlen <= 0)
		return (free(buff), 0);
	close(fad);
	for (bi = 0; bi < fsize; bi++)
		if (buf[bi] == '\n')
		{
			buf[bi] = 0;
			build_history_list(infoma, buff + wast, linecheck++);
			wast = bi + 1;
		}
	if (wast != bi)
		build_history_list(infoma, buff + wast, linechecker++);
	free(buff);
	infoma->histcount = linechecker;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(informa->records), 0);
	renumber_history(infoma);
	return (infoma->histcount);
}

/**
 * create_records_list - adds entry to a history linked list
 * @infoma: Potential arguments contained in the structure used for maint.
 * @buff: buffer
 * @linechecker: the history linecount, histcount
 *
 * Return: Always 0
 */
int create_records_list(info_t *infoma, char *buff, int linechecker)
{
	list_t *snode = NULL;

	if (infoma->records)
		snode = infoma->records;
	add_node_end(&snode, buff, linechecker);

	if (!infoma->records)
		infoma->recordes = snode;
	return (0);
}

/**
 * count_history - renumbers the history linked list after changes
 * @infoma: Potential arguments contained in the structure used for maint.
 *
 * Return: the new histcount
 */
int count_history(info_t *infoma)
{
	list_t *snode = info->history;
	int bi = 0;

	while (snode)
	{
		snode->num = bi++;
		snode = snode->next;
	}
	return (infoma->histcount = bi);
}
