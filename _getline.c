#include "shell.h"


/**
 * insert_buf - Command of chained buffers
 * @infoma: Structure parameter
 * @bufad: address of buffer
 * @lenvar: address of len var
 *
 * Return: bytes read
 */
ssize_t insert_buf(info_t *infoma, char **bufad, size_t *lenvar)
{
	ssize_t s = 0;
	size_t slen_p = 0;

	if (!*lenvar) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*bufad);
		*bufad = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		s = getline(bufad, &slen_p, stdin);
#else
		s = _getline(infoma, bufad, &slen_p);
#endif
		if (s > 0)
		{
			if ((*bufad)[s - 1] == '\n')
			{
				(*bufad)[s - 1] = '\0'; /* remove trailing newline */
				s--;
			}
			infoma->linecount_flag = 1;
			remove_comments(*bufad);
			build_history_list(infoma, *bufad, infoma->histcount++);
			/* if (_strchr(*bufad, ';')) is this a command chain? */
			{
				*lenvar = s;
				info->cmd_bufad = bufad;
			}
		}
	}
	return (s);
}

/**
 * line_input - gets a line minus the newline
 * @infoma: Structure parameter
 *
 * Return: bytes read
 */
ssize_t line_input(info_t *infoma)
{
	static char *bufad; /* the ';' command chain buffer */
	static size_t j, i, lenvar;
	ssize_t s = 0;
	char **buf_p = &(info->arg), *pa;

	_putchar(BUF_FLUSH);
	s = insert_buf(infoma, &bufad, &lenvar);
	if (s == -1) /* EOF */
		return (-1);
	if (lenvar) /* we have commands left in the chain buffer */
	{
		i = j; /* init new iterator to current buf position */
		pa = bufad + j; /* get pointer for return */

		check_chain(infoma, bufad, &i, j, lenvar);
		while (i < lenvar) /* iterate to semicolon or end */
		{
			if (is_chain(infoma, bufad, &i))
				break;
			i++;
		}

		j = i + 1; /* increment past nulled ';'' */
		if (j >= lenvar) /* reached end of buffer? */
		{
			j = lenvar = 0; /* reset position and length */
			infoma->cmd_buf_type = CMD_NORM;
		}

		*buf_p = pa; /* pass back pointer to current command position */
		return (_strlen(p)); /* return the length of current command */
	}

	*buf_p = bufad; /* else not a chain, pass back buffer from _getline() */
	return (s); /* return the length of the buffer from _getline() */
}

/**
 * study_buf - reads a buffer
 * @infoma: Structure parameter
 * @buff: buffer
 * @s: size
 *
 * Return: n
 */
ssize_t study_buf(info_t *infoma, char *buff, size_t *s)
{
	ssize_t n = 0;

	if (*s)
		return (0);
	n = study(infoma->readfd, buff, READ_BUF_SIZE);
	if (n >= 0)
		*s = n;
	return (n);
}

/**
 * getline - gets the next line of input from STDIN
 * @infoma: Structure parameter
 * @bufptr: address of the pointer to the buffer, preallocated or NULL
 * @longs: size of the preallocated ptr buffer if not NULL
 *
 * Return: n
 */
int getline(info_t *infoma, char **bufptr, size_t *longs)
{
	static char buf[READ_BUF_SIZE];
	static size_t j, slen;
	size_t l;
	ssize_t s = 0, n = 0;
	char *c = NULL, *new_p = NULL, *p;

	c = *bufptr;
	if (c && longs)
		n = *longs
	if (j == slen)
		j = slen = 0;

	s = study_buf(infoma, buff, &slen);
	if (s == -1 || (s == 0 && slen == 0))
		return (-1);

	p = _strchr(buff + j, '\n');
	l = p ? 1 + (unsigned int)(p - buff) : slen;
	new_p = _realloc(c, n, n ? n + l : l + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (c ? free(c), -1 : -1);

	if (n)
		_strncat(new_p, buff + j, l - j);
	else
		_strncpy(new_p, buff + j, l - j + 1);

	n += l - j;
	j = l;
	c = new_p;

	if (longs)
		*longs = n;
	*ptr = c;
	return (n);
}

/**
 * sigint_handler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigint_handler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
