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
		ft_printf_error("there is more or less arguments in instruction than should be\n");
	if (code == ERR_INV_ARG)
	{
		ft_printf_error("invalid argument ");
		ft_putnbr(num_arg);
		ft_putchar('\n');
	}
	exit(-1);
}

