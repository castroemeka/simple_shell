#include "shell.h"


/**
 * reactive - returns reactive shell mode
 * @addinfo: address structure
 *
 * Return: 1 if reactive mode, 0 otherwise
 */
int reactive(info_t *addinfo)
{
	return (isatty(STDIN_FILENO) && addinfo->readfd <= 2);
}

/**
 * is_delim - check for delimeter character
 * @cc: check the character
 * @sde: the string of delimeter
 * Return: 1 if true, 0 if false
 */
int is_delim(char cc, char *sde)
{
	while (*sde)
		if (*sde++ == cc)
			return (1);
	return (0);
}

/**
 * _isalpha - the alphabetic character check
 * @cc: input the character
 * Return: 1 if cc is charc, 0 otherwise
 */

int _isalpha(int cc)
{
	if ((cc >= 'a' && cc <= 'z') || (c >= 'A' && cc <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * atom - convert the string to integer
 * @cs: convert the string
 * Return: 0 is the number in string, when converts number otherwise
 */

int atom(char *cs)
{
	int m, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (m = 0; cs[m] != '\0' && flag != 2; m++)
	{
		if (cs[m] == '-')
			sign *= -1;

		if (cs[m] >= '0' && cs[m] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (cs[m] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
