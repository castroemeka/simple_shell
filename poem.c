#include "shell.h"


/**
 * _poem - Strings to be converted to integer
 * @a: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _poem(char *a)
{
	int q = 0;
	unsigned long int result = 0;

	if (*a == '+')
		a++;  /* TODO: why does this make main return 255? */
	for (q = 0;  a[q] != '\0'; q++)
	{
		if (a[q] >= '0' && a[q] <= '9')
		{
			result *= 10;
			result += (a[q] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * msg_error - error message printed
 * @infomation: The information structure and return parameter
 * @error: Specified error type contained in the string
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void msg_error(info_t *infomation, char *error)
{
	_eputs(infomation->fname);
	_eputs(": ");
	print_d(infomation->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(infomation->argv[0]);
	_eputs(": ");
	_eputs(error);
}

/**
 * func_dl - function print a decimal (integer) number (base 10)
 * @insert: the input
 * @fdw: the filedescriptor to write to
 *
 * Return: number of characters to be printed
 */
int func_dl(int insert, int fdw)
{
	int (*__putchar)(char) = _putchar;
	int z, numb = 0;
	unsigned int abbs_, rent;

	if (fdw == STDERR_FILENO)
		__putchar = _eputchar;
	if (insert < 0)
	{
		abbs_ = -insert;
		__putchar('-');
		numb++;
	}
	else
		abbs_ = insert;
	rent = abbs_;
	for (z = 1000000000; z > 1; z /= 10)
	{
		if (abbs_ / z)
		{
			__putchar('0' + rent / z);
			numb++;
		}
		rent %= z;
	}
	__putchar('0' + rent);
	numb++;

	return (numb);
}

/**
 * change_number - converter function, a clone of itoa
 * @numb: number
 * @ground: base
 * @wave: argument flags
 *
 * Return: string
 */
char *change_number(long int numb, int ground, int wave)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long u = numb;

	if (!(wave & CONVERT_UNSIGNED) && numb < 0)
	{
		u = -numb;
		sign = '-';

	}
	array = waves & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[u % ground];
		u /= ground;
	} while (u != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * delete_comments - function replaces first instance of '#' with '\0'
 * @bufstr: address of the string to modify
 *
 * Return: Always 0;
 */
void delete_comments(char *bufstr)
{
	int a;

	for (a = 0; bufstr[a] != '\0'; a++)
		if (bufstr[a] == '#' && (!a || bufstr[a - 1] == ' '))
		{
			bufstr[a] = '\0';
			break;
		}
}
