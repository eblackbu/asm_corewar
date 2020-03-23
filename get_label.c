#include "asm.h"

void		add_new_label(t_champion **champ, char *line, int start, int len)
{
	t_label	*tmp;
	t_label	*tmp_prev;

	tmp = (*champ)->labels;
	tmp_prev = NULL;
	while (tmp)
	{
		tmp_prev  = tmp;
		tmp = tmp->next;
	}
	if (!(tmp = (t_label*)malloc(sizeof(t_label))))
		exit(-1);
	tmp->name = ft_strnew(len);
	tmp->name = ft_strncpy(tmp->name, &line[start], len);
	tmp->next = NULL;
	if (tmp_prev)
		tmp_prev->next = tmp;
	else
		(*champ)->labels = tmp;
	//find_instr_line(champ, line); //TODO инструкция в любом случае буде записана в последнюю метку, либо будет добавлена новая метка
}

void		get_label(t_champion **champ, char *line)
{
	int 	start;
	int 	len;

	start = 0;
	len = 0;
	while (line[start] == ' ' || line[start] == '\t')
		start++;
	while (line[len + start] != LABEL_CHAR)
		len++;
	if (len == 0)
		error_exit(ERR_EMPTY_LABEL);
	add_new_label(champ, line, start, len);
}

