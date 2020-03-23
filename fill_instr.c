#include "asm.h"

//extern t_type				type_tab[17];

int			set_argtype(int argtype, t_instr **new_instr, int num_arg, char *line)
{
	int 	i;

	i = 0;
	if (!(argtype & (*new_instr)->type.bit_args[num_arg]))
		error_args(ERR_INV_TYPE, num_arg);
	(*new_instr)->args[num_arg].type = argtype;
	if ((*new_instr)->type.count_args == 1 && ft_strcmp((*new_instr)->type.name, "aff"))
		(*new_instr)->instr_byte |= (unsigned char)argtype << (8 - (num_arg + 1) * 2);
	if (argtype == T_REG || argtype == T_DIR)
		set_argument(new_instr, &line[1], num_arg);
	else
		set_argument(new_instr, line, num_arg);
	while (line[i] && line[i] != SEPARATOR_CHAR)
		i++;
	return (i);
}

void		get_args_type(char *line, t_instr **new_instr)
{
	int 	i;
	int 	num_arg;

	i = ft_strlen((*new_instr)->type.name);
	num_arg = 0;
	while (num_arg < (*new_instr)->type.count_args)
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] == 'r')
			i += set_argtype(T_REG, new_instr, num_arg, &line[i]);
		else if (line[i] == DIRECT_CHAR)
			i += set_argtype(T_DIR, new_instr, num_arg, &line[i]);
		else if (line[i] == LABEL_CHAR || ft_isdigit(line[i]))
			i += set_argtype(T_IND, new_instr, num_arg, &line[i]);
		else
			error_args(ERR_INV_TYPE, num_arg);
		num_arg++;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i++] != SEPARATOR_CHAR && num_arg != (*new_instr)->type.count_args)
			error_args(ERR_COUNT_ARGS, num_arg);
	}
}

t_instr		*fill_instr(t_champion **champ, t_instr *new_instr, char *line)
{
	new_instr->type = type_tab[compare_instr(line)];
	if (!(new_instr->args = (t_arg*)malloc(sizeof(t_arg) * new_instr->type.count_args)))
		exit(-1);
	get_args_type(line, &new_instr);
	new_instr->first_byte = get_first_byte(champ);
	new_instr->full_size = get_full_size(new_instr);
	return (new_instr);
}


