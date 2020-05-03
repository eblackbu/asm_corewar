/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_byte_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:01:30 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/03 14:01:31 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				get_first_byte(t_champion **champ)
{
	int			first_byte;
	t_instr		*tmp;

	first_byte = 0;
	tmp = (*champ)->code;
	while (tmp)
	{
		first_byte += tmp->full_size;
		tmp = tmp->next;
	}
	return (first_byte);
}

int				get_full_size(t_instr *new_instr)
{
	int			i;
	int			full_size;

	full_size = 1;
	if (new_instr->type.count_args != 1 || new_instr->type.number == 16)
		full_size++;
	i = 0;
	while (i < new_instr->type.count_args)
	{
		if (new_instr->args[i].type == REG_CODE)
			full_size += REG_BYTE;
		else if (new_instr->args[i].type == IND_CODE)
			full_size += IND_BYTE;
		else
		{
			if (new_instr->type.number > 8 && new_instr->type.number != 13)
				full_size += IND_BYTE;
			else
				full_size += DIR_BYTE;
		}
		i++;
	}
	return (full_size);
}
