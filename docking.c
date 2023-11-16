#include "shell.h"


/**
 * _memset - memory filled with the constant byte
 * @d: the memory areas
 * @z: the bytes to fill *s with
 * @nb: the amount of bytes
 * Return: (s) to the memory areas s
 */
char *_memset(char *d, char z, unsigned int nb)
{
	unsigned int a;

	for (a = 0; a < nb; a++)
		d[a] = z;
	return (d);
}

/**
 * ffree - free the string of strings
 * @sp: the string of strings
 */
void ffree(char **sp)
{
	char **w = sp;

	if (!sp)
		return;
	while (*sp)
		free(*sp++);
	free(w);
}

/**
 * _docking - changing the memory block
 * @ptr: pointer to the previous malloc'ated block
 * @before_size: byte size of the previous block
 * @now_size: byte size of the new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_docking(void *ptr, unsigned int before_size, unsigned int now_size)
{
	char *pt;

	if (!ptr)
		return (malloc(now_size));
	if (!now_size)
		return (free(ptr), NULL);
	if (now_size == before_size)
		return (ptr);

	pt = malloc(now_size);
	if (!pt)
		return (NULL);

	before_size = before_size < now_size ? before_size : now_size;
	while (before_size--)
		pt[before_size] = ((char *)ptr)[before_size];
	free(ptr);
	return (pt);
}
