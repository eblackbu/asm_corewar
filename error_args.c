#include "asm.h"

void	error_args(int code, int num_arg)
{
	if (code == ERR_INV_TYPE)
	{
		ft_printf_error("invalid type of argument ");
		ft_putnbr(num_arg);
		ft_putchar('\n');
	}
	if (code == ERR_COUNT_ARGS)
		ft_printf_error("invalid count of arguments\n");
	if (code == ERR_INV_ARG)
	{
		ft_printf_error("invalid argument ");
		ft_putnbr(num_arg);
		ft_putchar('\n');
	}
	if (code == ERR_UNKNOWN_LABEL)
	{
		ft_printf_error("unknown label in argument ");
		ft_putnbr(num_arg);
		ft_putchar('\n');
	}
	if (code == ERR_INV_REG)
    {
	    ft_printf_error("invalid number of registry, argument ");
	    ft_putnbr(num_arg);
	    ft_putchar('\n');
    }
	exit(-1);
}

