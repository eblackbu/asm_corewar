#include "asm.h"

int			count_digits(int value, int n)
{
	int 	count;

	count = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		value /= n;
		count++;
	}
	return (count);
}

char 		*set_arglabel(char *line)
{
	char *label;
	int i;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != SEPARATOR_CHAR)
	{
		if (ft_strchr(LABEL_CHARS, line[i]))
			i++;
		else
			error_exit(ERR_LABEL_CHARS);
	}
	label = ft_strnew(i);
	label = ft_strncpy(label, line, i);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] && line[i] != SEPARATOR_CHAR)
		error_exit(ERR_LABEL_CHARS);
	return (label);
}

int			set_argvalue(char *line, int argtype, int num_arg)
{
	int		i;
	int 	value;

	value = ft_atoi(line);
	i = count_digits(value, 10);
	if (argtype == T_REG && (value <= 0 || value > REG_NUMBER))
		error_args(ERR_INV_REG, num_arg);
	if (line[i] != '\0' && line[i] != ' ' && line[i] != '\t' && line[i] != SEPARATOR_CHAR)
		error_args(ERR_INV_ARG, num_arg);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] && line[i] != SEPARATOR_CHAR)
		error_exit(ERR_LABEL_CHARS);
	return (value);
}

void 		set_argument(t_instr **new_instr, char *line, int num_arg)
{
	int		i;

	i = 0;
	if (line[i] == LABEL_CHAR && (*new_instr)->args[num_arg].type == T_REG)
		error_args(ERR_INV_ARG, num_arg);
	if (line[i] == LABEL_CHAR)
		(*new_instr)->args[num_arg].label_name = set_arglabel(&line[1]);
	else if (ft_isdigit(line[i]))
	{
		(*new_instr)->args[num_arg].label_name = NULL;
		(*new_instr)->args[num_arg].value = set_argvalue(line, (*new_instr)->args[num_arg].type, num_arg);
	}
	else
		error_args(ERR_INV_ARG, num_arg);
}