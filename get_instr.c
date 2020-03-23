#include "asm.h"
/*
t_instr		*find_instr_line(t_champion **champ, char *line)
{
	int 	i;
	char 	*tmp_line;

	i = 0;
	tmp_line = ft_strchr(line, LABEL_CHAR) + 1;
	while (tmp_line)
	if (tmp_line[i] == '\0' || tmp_line[i] == COMMENT_CHAR || tmp_line[i] == ALT_COMMENT_CHAR)
	{
		ft_strdel(&line);
		current_string++;
		get_next_line((*champ)->fd, &line);

	}
	return (NULL);
}
*/
//TODO продумать как искать инструкцию для метки

void		add_new_instr(t_champion **champ, char *line)
{
	t_instr	*tmp;
	t_instr	*tmp_prev;

	tmp = (*champ)->code;
	tmp_prev = NULL;
	while (tmp)
	{
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	if (!(tmp = (t_instr*)malloc(sizeof(t_instr))))
		exit(-1);
	tmp = fill_instr(champ, tmp, line);
	tmp->next = NULL;
	if (tmp_prev)
		tmp_prev->next = tmp;
	else
		(*champ)->code = tmp;
}

void		get_instr(t_champion **champ, char *line)
{
	int 	start;

	start = 0;
	while (line[start] == ' ' || line[start] == '\t')
		start++;
	add_new_instr(champ, &line[start]);
	ft_strdel(&line);
}