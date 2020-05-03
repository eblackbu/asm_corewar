/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:59:44 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/03 13:59:46 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_args(t_arg *args, int count_args)
{
	int		i;

	i = 0;
	while (i < count_args)
	{
		ft_strdel(&args[i].label_name);
		i++;
	}
	free(args);
}

void		free_instr(t_instr *instr)
{
	t_instr	*tmp;

	tmp = instr;
	while (instr)
	{
		ft_strdel(&instr->bytestr);
		free_args(instr->args, instr->type.count_args);
		instr = instr->next;
		free(tmp);
		tmp = instr;
	}
}

void		free_labels(t_label *label)
{
	t_label	*tmp;

	tmp = label;
	while (label)
	{
		ft_strdel(&label->name);
		label = label->next;
		free(tmp);
		tmp = label;
	}
}

void		free_all(t_champion *champ)
{
	free_instr(champ->code);
	free_labels(champ->labels);
	ft_strdel(&champ->file_name);
	ft_strdel(&champ->name);
	ft_strdel(&champ->comment);
	free(champ);
}
