/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:59:57 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/03 13:59:59 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_new_label(t_champion **champ, char *line, int len)
{
	t_label	*tmp;
	t_label	*tmp_prev;
	char	*new_line;

	tmp = (*champ)->labels;
	tmp_prev = NULL;
	while (tmp)
	{
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	if (!(tmp = (t_label*)malloc(sizeof(t_label))))
		exit(-1);
	tmp->name = ft_strnew(len);
	tmp->name = ft_strncpy(tmp->name, line, len);
	tmp->next = NULL;
	if (tmp_prev)
		tmp_prev->next = tmp;
	else
		(*champ)->labels = tmp;
	new_line = ft_strdup(ft_strchr(line, LABEL_CHAR) + 1);
	ft_strdel(&line);
	tmp->instr = find_instr_line(champ, &new_line);
}

t_instr		*find_instr_line(t_champion **champ, char **line)
{
	while (*line)
	{
		if (is_space_line(*line))
		{
			ft_strdel(line);
			gnl_spec((*champ)->fd, line);
			g_current_string++;
			continue ;
		}
		else if (is_instr(*line))
			return (get_instr(champ, *line));
		else if (is_label(*line))
		{
			get_label(champ, *line);
			return (NULL);
		}
		else
			error_exit(ERR_UNEXP_SYM);
	}
	ft_strdel(line);
	return (NULL);
}

void		get_label(t_champion **champ, char *line)
{
	int		start;
	int		len;
	char	*new_line;

	start = 0;
	len = 0;
	while (line[start] == ' ' || line[start] == '\t')
		start++;
	while (line[len + start] != LABEL_CHAR)
		len++;
	if (len == 0)
		error_exit(ERR_EMPTY_LABEL);
	new_line = ft_strdup(&line[start]);
	ft_strdel(&line);
	add_new_label(champ, new_line, len);
}
