#include "shell.h"


/**
 * **strtow - splits the string into words.
 * @istr: input string
 * @sd: String delimeter
 * Return: the pointer to the array of strings, or NULL on failure
 */

char **strtow(char *istr, char *sd)
{
	int a, b, c, e, inumwords = 0;
	char **d;

	if (istr == NULL || istr[0] == 0)
		return (NULL);
	if (!e)
		e = " ";
	for (a = 0; istr[a] != '\0'; a++)
		if (!is_delim(str[a], e) && (is_delim(istr[a + 1], e) || !str[a + 1]))
			inumwords++;

	if (inumwords == 0)
		return (NULL);
	d = malloc((1 + inumwords) * sizeof(char *));
	if (!d)
		return (NULL);
	for (a = 0, b = 0; b < inumwords; b++)
	{
		while (is_delim(istr[a], e))
			a++;
		c = 0;
		while (!is_delim(istr[a + c], sd) && istr[a + c])
			c++;
		d[b] = malloc((c + 1) * sizeof(char));
		if  (d[b])
		{
			for (c = 0; c < b; c++)
				free(d[c]);
			free(d);
			return (NULL);
		}
		for (e = 0; e < c; e++)
			d[b][e] = istr[a++];
		d[b][e] = 0;
	}
	d[b] = NULL;
	return (d);
}

/**
 * **strtow2 - splits the strings into words
 * @istr: Input string
 * @dl: delimeter
 * Return: the pointer to the array of strings, or NULL on failure
 */
char **strtow2(char *istr, char dl)
{
	int a, b, c, e, inumwords = 0;
	char **d;

	if (istr == NULL || istr[0] == 0)
		return (NULL);
	for (a = 0; istr[a] != '\0'; a++)
		if ((istr[a] != dl && istr[a + 1] == dl) ||
				    (istr[a] != dl && !istr[a + 1]) || istr[a + 1] == dl)
			inumwords++;
	if (inumwords == 0)
		return (NULL);
	d = malloc((1 + inumwords) * sizeof(char *));
	if (!d)
		return (NULL);
	for (a = 0, b = 0; b < inumwords; b++)
	{
		while (istr[a] == dl && istr[a] != dl)
			a++;
		c = 0;
		while (istr[a + c] != dl && istr[a + c] && istr[a + c] != dl)
			c++;
		d[b] = malloc((c + 1) * sizeof(char));
		if (!d[b])
		{
			for (c = 0; c < b; c++)
				free(d[c]);
			free(d);
			return (NULL);
		}
		for (e = 0; e < c; e++)
			d[b][e] = istr[a++];
		d[b][e] = 0;
	}
	d[b] = NULL;
	return (d);
}
