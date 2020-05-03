/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:58:51 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/03 13:58:53 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_error_with_arg(char *str, int num_arg)
{
	ft_printf_error(str);
	ft_putnbr(num_arg);
	ft_putchar('\n');
}

void	error_args(int code, int num_arg)
{
	if (code == ERR_INV_TYPE)
		print_error_with_arg("invalid type of argument ", num_arg);
	if (code == ERR_COUNT_ARGS)
		ft_printf_error("invalid count of arguments\n");
	if (code == ERR_INV_ARG)
		print_error_with_arg("invalid argument ", num_arg);
	if (code == ERR_UNKNOWN_LABEL)
		print_error_with_arg("unknown label in argument ", num_arg);
	if (code == ERR_INV_REG)
		print_error_with_arg("invalid number of registry, argument ", num_arg);
	exit(-1);
}
