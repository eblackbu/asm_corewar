/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_analyzer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:56:54 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/03 13:56:59 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_space_line(const char *line)
{
	int		i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == COMMENT_CHAR || \
			line[i] == ALT_COMMENT_CHAR)
		return (1);
	return (0);
}

int			is_label(char *line)
{
	int		i;

	i = 0;
	if (!ft_strchr(line, LABEL_CHAR))
		return (0);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (ft_strchr(LABEL_CHARS, line[i]))
		i++;
	if (line[i] == LABEL_CHAR)
		return (1);
	error_exit(ERR_LABEL_CHARS);
}

int			ft_strcmp_spec(const char *s1, const char *s2)
{
	while ((unsigned char)*s1 && (unsigned char)*s2 \
			&& (unsigned char)*s1 == (unsigned char)*s2)
	{
		s1++;
		s2++;
	}
	if (*s2 == '\0' && (*s1 == ' ' || *s1 == '\t' || \
			*s1 == DIRECT_CHAR || *s1 == '-'))
		return (1);
	else
		return (0);
}

int			compare_instr(char *line)
{
	int	flag;
	int	i;

	flag = -1;
	i = 0;
	while (i < 16)
	{
		if (ft_strcmp_spec(line, g_type_tab[i].name))
			flag = i;
		i++;
	}
	return (flag);
}

int			is_instr(char *line)
{
	int		i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (compare_instr(&line[i]) > -1)
		return (1);
	return (0);
}
