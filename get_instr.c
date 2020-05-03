#include "asm.h"

t_instr		*add_new_instr(t_champion **champ, char *line)
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
	return (tmp);
}

t_instr		*get_instr(t_champion **champ, char *line)
{
	t_instr	*tmp;
	int		start;

	start = 0;
	while (line[start] == ' ' || line[start] == '\t')
		start++;
	tmp = add_new_instr(champ, &line[start]);
	ft_strdel(&line);
	return (tmp);
}
