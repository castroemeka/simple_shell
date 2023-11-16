#include "Shell.h"


/**
 * _strcpy - string copied
 * @loc: location
 * @busrc: Source
 *
 * Return: The location pointer
 */
char *_strcpy(char *loc, char *busrc)
{
	int z = 0;

	if (loc == busrc || busrc == 0)
		return (loc);
	while (busrc[z])
	{
		loc[z] = busrc[z];
		z++;
	}
	loc[z] = 0;
	return (loc);
}

/**
 * _strdup - Strings duplicated
 * @strdupe: the string to be duplicate
 *
 * Return: duplicated string pointer
 */
char *_strdup(const char *strdupe)
{
	int len = 0;
	char *wet;

	if (strdupe == NULL)
		return (NULL);
	while (*strdupe++)
		len++;
	wet = malloc(sizeof(char) * (len + 1));
	if (!wet)
		return (NULL);
	for (len++; len--;)
		wet[len] = *--strdupe;
	return (wet);
}

/**
 * _putstr - prints an input string
 * @strp: String to be printed
 *
 * Return: Nothing
 */
void _putstr(char *strp)
{
	int z = 0;

	if (!strp)
		return;
	while (strp[z] != '\0')
	{
		_putchar(strp[z]);
		z++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @s: The character to print
 *
 * Return: On succed 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char s)
{
	static int z;
	static char buf[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || z >= WRITE_BUF_SIZE)
	{
		write(1, buf, z);
		z = 0;
	}
	if (s != BUF_FLUSH)
		buf[z++] = s;
	return (1);
}
