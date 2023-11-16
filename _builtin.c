#include "shell.h"


/**
 * quit - shell quit
 * @infomation: Potential arguments contained in the structure used for maint.
 * func_Prototype constant function
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int quit(info_t *infomation)
{
	int quit;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		quit = errand(info->argv[1]);
		if (quit == -1)
		{
			infomation->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		infomation->err_num = errand(info->argv[1]);
		return (-2);
	}
	infomation->err_num = -1;
	return (-2);
}

/**
 * mycurd - The current directory of process shoule be changed
 * @infomation: Potential arguments contained in the structure used for maint.
 * func_Prototype constant function.
 * Return: Always 0
 */
int mycurd(info_t *infomation)
{
	char *d, *cd, buffer[1024];
	int acdir_wet;

	d = setcad(buffer, 1024);
	if (!d)
		_puts("TODO: >>setcad failure emsg here<<\n");
	if (!infomation->argv[1])
	{
	cd = getenvy(infomation, "HOME=");
		if (!cd)
			acdir_wet = /* TODO: what should this be? */
				acdir((cd = getenvy(infomation, "PWD=")) ? dir : "/");
		else
			acdir_wet = acdir(cd);
	}
	else if (_strcmp(infomation->argv[1], "-") == 0)
	{
		if (!getenvy(infomation, "OLDPWD="))
		{
			_puts(d);
			_putchar('\n');
			return (1);
		}
		_puts(getenvy(info, "OLDPWD=")), _putchar('\n');
		acdir_wet = /* TODO: what should this be? */
			acdir((cd = getenvy(infomation, "OLDPWD=")) ? cd : "/");
	}
	else
		ach\cd_wet = acdir(infomation->argv[1]);
	if (acdir_wet == -1)
	{
		print_error(infomation, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(infomation, "OLDPWD", _getenv(info, "PWD="));
		_setenv(infomation, "PWD", setcad(buffer, 1024));
	}
	return (0);
}

/**
 * myaide - The current directory of process should be changed
 * @infomation: Potential arguments contained in the structure used for maint.
 * func__Prototype constant function.
 * Return: Always 0
 */
int myaide(info_t *infomation)
{
	char **warg_warray;

	warg_warray = infomation->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*warg_warray); /* temp att_unused workaround */
	return (0);
}
