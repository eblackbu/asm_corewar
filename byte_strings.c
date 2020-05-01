#include "asm.h"

void			value_to_bytes(char **arg, int value, int len)
{
	if (len == 1)
		value = (char)value;
	else if (len == 2)
		value = (short)value;
	*arg = ft_memcpy(*arg, &value, len);
}

int				get_arg_len(t_instr **instr, t_arg arg)
{
	if (arg.type == REG_CODE)
		return (REG_BYTE);
	if (arg.type == IND_CODE)
		return (IND_BYTE);
	if (arg.type == DIR_CODE && (*instr)->type.number > 8 && (*instr)->type.number != 13)
		return (IND_BYTE);
	return (DIR_BYTE);
}

void			set_arg_to_string(t_instr **instr, t_arg arg, int *i)
{
	char 		*tmp_arg;
	int 		len;
	int			j;

	len = get_arg_len(instr, arg);
	if (!(tmp_arg = (char*)malloc(sizeof(char) * len)))
		exit(-1);
	value_to_bytes(&tmp_arg, arg.value, len);
	j = len - 1;
	while (j > -1)
		(*instr)->bytestr[(*i)++] = tmp_arg[j--];
	ft_strdel(&tmp_arg);
}

void			make_one_string(t_instr **instr)
{
	int			i;
	int 		num_arg;

	i = 0;
	num_arg = 0;
	if (!(((*instr)->bytestr = (char*)malloc(sizeof(char) * (*instr)->full_size))))
		exit(-1);
	(*instr)->bytestr[i++] = (*instr)->type.number;
	if ((*instr)->instr_byte)
		(*instr)->bytestr[i++] = (*instr)->instr_byte;
	while (num_arg < (*instr)->type.count_args)
	{
		set_arg_to_string(instr, (*instr)->args[num_arg], &i);
		num_arg++;
	}
}

void			make_byte_strings(t_champion **champ)
{
	t_instr		*tmp;

	tmp = (*champ)->code;
	if (!tmp)
		exit(-1); //TODO error
	while (tmp)
	{
		make_one_string(&tmp);
		tmp = tmp->next;
	}
}