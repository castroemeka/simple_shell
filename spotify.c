#include "shell.h"


/**
 * _efforts - print the input string
 * @strr: the string to be printed
 *
 * Return: Nothing
 */
void _efforts(char *strr)
{
	int q = 0;

	if (!strr)
		return;
	while (str[q] != '\0')
	{
		_eputchar(strr[q]);
		q++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @d: Print the character
 *
 * Return: On succed 1.
 * On mistakes, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char d)
{
	static int q;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || q >= WRITE_BUF_SIZE)
	{
		write(2, buf, q);
		q = 0;
	}
	if (d != BUF_FLUSH)
		buf[q++] = d;
	return (1);
}

/**
 * _putccd - writes the character d to given ccd
 * @d: Print the character
 * @filedes: The filedescriptor to write to
 *
 * Return: On succed 1.
 * On mistake, -1 is returned, and errno is set appropriately.
 */
int _putccd(char d, int ccd)
{
	static int q;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || q >= WRITE_BUF_SIZE)
	{
		write(ccd, buf, q);
		q = 0;
	}
	if (d != BUF_FLUSH)
		buf[q++] = d;
	return (1);
}

/**
 * _putscad - print the input string
 * @strprin: the string to be printed
 * @filedes: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putscad(char *sttr, int cad)
{
	int q = 0;

	if (!sttr)
		return (0);
	while (*sttr)
	{
		q += _putcad(*sttr++, cad);
	}
	return (q);
}
