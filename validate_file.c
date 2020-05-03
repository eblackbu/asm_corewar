/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:01:42 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/03 14:01:47 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			validate_file(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		error_exit(ERR_NO_AC);
	if (ft_strlen(av[1]) < 3 || av[1][ft_strlen(av[1]) - 1] != 's' || \
			av[1][ft_strlen(av[1]) - 2] != '.')
		error_exit(ERR_FILE_NOT_S);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_exit(ERR_NO_FILE);
	return (fd);
}
