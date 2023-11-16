#include "Shell.h"


/**
 * _strlen - length of the string
 * @c: check length string
 *
 * Return: integer length of the string
 */
int _strlen(char *c)
{
	int z = 0;

	if (!z)
		return (0);

	while (*c++)
		z++;
	return (z);
}

/**
 * _strcmp - lexicographic comparison for two strangs.
 * @fs: the first strang
 * @ss: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *fs, char *ss)
{
	while (*fs && *ss)
	{
		if (*fs != *ss)
			return (*fs - *ss);
		fs++;
		ss++;
	}
	if (*fs == *ss)
		return (0);
	else
		return (*fs < *ss ? -1 : 1);
}

/**
 * starts_with - start the needle with haystack
 * @stack: search string
 * @swindle: the substring to find
 *
 * Return: address of the next char of stack or NULL
 */
char *starts_with(const char *stack, const char *swindle)
{
	while (*swindle)
		if (*swindle++ != *stack++)
			return (NULL);
	return ((char *)stack);
}

/**
 * _strcat - two strings concatenated
 * @loc: the buffer location
 * @busrc: the buffer source
 *
 * Return: buffer location pointer
 */
char *_strcat(char *loc, char *busrc)
{
	char *wet = loc;

	while (*loc)
		loc++;
	while (*busrc)
		*loc++ = *busrc++;
	*loc = *busrc;
	return (wet);
}
