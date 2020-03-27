#include "asm.h"

int				get_code_size(t_champion *champ)
{
	t_instr		*tmp;
	int 		code_size;

	code_size = 0;
	tmp = champ->code;
	while (tmp)
	{
		code_size += tmp->full_size;
		tmp = tmp->next;
	}
	return (code_size);
}

char 		*set_filename(char *filename)
{
	char	*str;
	int 	len;
	int		i;

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

t_champion 	*create_champ(int fd, char *filename)
{
	t_champion	*champ;

	if (!(champ = (t_champion*)malloc(sizeof(t_champion))))
		exit(-1);
	champ->fd = fd;
	champ->file_name = set_filename(filename);
	get_name_comment(&champ);
	champ->code = NULL;
	champ->labels = NULL;
	get_code(&champ);
	replace_labels(&champ);
	return (champ);
}