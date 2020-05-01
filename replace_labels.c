#include "asm.h"

int 		get_indirent_value(t_champion **champ, t_instr *instr, int arg_num)
{
	t_label	*tmp;

	tmp = (*champ)->labels;
	while (tmp && !ft_strequ(tmp->name, instr->args[arg_num].label_name))
		tmp = tmp->next;
	if (!tmp)
		error_args(ERR_UNKNOWN_LABEL, arg_num);
	/*
	if (instr->args[arg_num].type != DIR_CODE)
		return (tmp->first_byte - instr->first_byte);
	else
		return (tmp->first_byte); *///TODO непонятно где нужно прямое а где непрямое значение
	return (tmp->first_byte - instr->first_byte);
}

t_instr 	*check_labels(t_champion **champ, t_instr *instr)
{
	int		i;

	i = 0;
	while (i < instr->type.count_args)
	{
		if (instr->args[i].label_name)
			instr->args[i].value = get_indirent_value(champ, instr, i);
		i++;
	}
	return (instr);
}

void		replace_labels(t_champion **champ)
{
	t_instr *tmp;

	current_string = 0;
	tmp = (*champ)->code;
	while (tmp)
	{
		tmp = check_labels(champ, tmp);
		tmp = tmp->next;
	}
}

