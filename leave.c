#include "shell.h"


/**
 **_strncpy - Strings copied
 *@loc: the loc of the string to be copied to
 *@busrc: the source of the string
 *@ac: the amount of characters to be copied
 *Return: the concatenated strings
 */
char *_strncpy(char *loc, char *busrc, int ac)
{
	int a, d;
	char *c = loc;

	a = 0;
	while (busrc[a] != '\0' && a < ac - 1)
	{
		loc[a] = busrc[a];
		a++;
	}
	if (a < ac)
	{
		d = a;
		while (d < ac)
		{
			loc[d] = '\0';
			d++;
		}
	}
	return (c);
}

/**
 **_strncat - concatenates the two strings
 *@loc: the first string
 *@busrc: the second string
 *@ac: the amount of bytes to be maximally used
 *Return: the concatenated strings
 */
char *_strncat(char *loc, char *busrc, int ac)
{
	int a, d;
	char *c = loc;

	a = 0;
	d = 0;
	while (loc[a] != '\0')
		a++;
	while (busrc[d] != '\0' && d < ac)
	{
		loc[a] = busrc[d];
		a++;
		d++;
	}
	if (d < ac)
		loc[a] = '\0';
	return (c);
}

/**
 **_strchr - character located in the string
 *@v: the string to be parsed
 *@b: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *v, char b)
{
	do {
		if (*v == b)
			return (v);
	} while (*v++ != '\0');

	return (NULL);
}
