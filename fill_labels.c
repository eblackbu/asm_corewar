/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_labels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:59:37 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/03 13:59:39 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_instr			*find_instr_to_label(t_label *label_to_find)
{
	t_label		*tmp;

	tmp = label_to_find;
	while (tmp && !tmp->instr)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	else
		return (tmp->instr);
}

void			fill_labels(t_champion **champ)
{
	t_label		*tmp;

	tmp = (*champ)->labels;
	while (tmp)
	{
		if (!tmp->instr)
			tmp->instr = find_instr_to_label(tmp);
		if (tmp->instr)
			tmp->first_byte = tmp->instr->first_byte;
		else
			tmp->first_byte = (*champ)->code_size;
		tmp = tmp->next;
	}
}
