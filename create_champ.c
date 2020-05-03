#include "asm.h"

int				get_code_size(t_champion *champ)
{
	t_instr		*tmp;
	int			code_size;

	code_size = 0;
	tmp = champ->code;
	while (tmp)
	{
		code_size += tmp->full_size;
		tmp = tmp->next;
	}
	return (code_size);
}

char			*set_filename(char *filename)
{
	char		*str;
	int			len;
	int			i;

	len = ft_strlen(filename) - 2;
	str = ft_strnew(len + 4);
	i = 0;
	while (i < len)
	{
		str[i] = filename[i];
		i++;
	}
	ft_strcpy(&str[i], ".cor");
	return (str);
}

void			get_code(t_champion **champ)
{
	char		*line;

	while (gnl_spec((*champ)->fd, &line) > 0)
	{
		g_current_string++;
		if (is_space_line(line))
		{
			ft_strdel(&line);
			continue ;
		}
		else if (is_instr(line))
			get_instr(champ, line);
		else if (is_label(line))
			get_label(champ, line);
		else
			error_exit(ERR_UNEXP_SYM);
	}
	(*champ)->code_size = get_code_size(*champ);
	if ((*champ)->code_size == 0)
		error_exit(ERR_NO_CODE);
	fill_labels(champ);
}

t_champion		*create_champ(int fd, char *filename)
{
	t_champion	*champ;

	if (!(champ = (t_champion*)malloc(sizeof(t_champion))))
		exit(-1);
	champ->fd = fd;
	champ->file_name = set_filename(filename);
	get_name_comment(&champ);
	if (!champ->name || !champ->comment)
		error_exit(ERR_NULL_HEADER);
	champ->code = NULL;
	champ->labels = NULL;
	get_code(&champ);
	replace_labels(&champ);
	return (champ);
}
