#include "shell.h"


/**
 * adrf - free the pointer & NULLs the address
 * @aoptr: free address of the pointer
 *
 * Return: 1 if freed, otherwise 0.
 */
int adrf(void **aoptr)
{
	if (aoptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
