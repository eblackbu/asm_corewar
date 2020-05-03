/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:59:22 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/03 13:59:26 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			set_argtype(int argtype, t_instr **new_instr, \
		int num_arg, char *line)
{
	int		i;
	int		tmp_type;

	i = 0;
	tmp_type = argtype == 3 ? argtype + 1 : argtype;
	if (!(tmp_type & (*new_instr)->type.bit_args[num_arg]))
		error_args(ERR_INV_TYPE, num_arg + 1);
	(*new_instr)->args[num_arg].type = argtype;
	if (!((*new_instr)->type.count_args == 1 && \
				ft_strcmp((*new_instr)->type.name, "aff")))
		(*new_instr)->instr_byte |= (argtype << (8 - (num_arg + 1) * 2));
	if (argtype == REG_CODE || argtype == DIR_CODE)
		set_argument(new_instr, &line[1], num_arg);
	else
		set_argument(new_instr, line, num_arg);
	while (line[i] && line[i] != SEPARATOR_CHAR && line[i] \
			!= COMMENT_CHAR && line[i] != ALT_COMMENT_CHAR)
		i++;
	return (i);
}

void		get_args_type(char *line, t_instr **new_instr)
{
	int		i;
	int		num_arg;

	i = ft_strlen((*new_instr)->type.name);
	num_arg = 0;
	while (num_arg < (*new_instr)->type.count_args)
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] == 'r')
			i += set_argtype(REG_CODE, new_instr, num_arg, &line[i]);
		else if (line[i] == DIRECT_CHAR)
			i += set_argtype(DIR_CODE, new_instr, num_arg, &line[i]);
		else if (line[i] == LABEL_CHAR || ft_atoi(&line[i]) || line[i] == '0')
			i += set_argtype(IND_CODE, new_instr, num_arg, &line[i]);
		else
			error_args(ERR_INV_TYPE, num_arg + 1);
		num_arg++;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i++] == SEPARATOR_CHAR && \
				num_arg == (*new_instr)->type.count_args)
			error_args(ERR_COUNT_ARGS, num_arg);
	}
}

t_instr		*fill_instr(t_champion **champ, t_instr *new_instr, char *line)
{
	new_instr->type = g_type_tab[compare_instr(line)];
	if (!(new_instr->args = (t_arg*)malloc(sizeof(t_arg) \
					* new_instr->type.count_args)))
		exit(-1);
	new_instr->instr_byte = 0;
	get_args_type(line, &new_instr);
	new_instr->first_byte = get_first_byte(champ);
	new_instr->full_size = get_full_size(new_instr);
	return (new_instr);
}
