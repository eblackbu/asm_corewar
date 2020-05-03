/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:00:13 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/03 14:00:14 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	t_champion	*champ;
	int			fd;

	fd = validate_file(ac, av);
	champ = create_champ(fd, av[1]);
	close(fd);
	make_byte_strings(&champ);
	print_to_file(&champ);
	free_all(champ);
	ft_putstr("All is ok, this champion is valid!\n");
	return (0);
}
