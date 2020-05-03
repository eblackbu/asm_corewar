/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:00:06 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/03 14:00:07 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char				*ft_strjoin_sp(char **str, char *buf, size_t len)
{
	char			*newstr;

	if (!(newstr = ft_strnew(len + ft_strlen(buf) + 1)))
		return (NULL);
	ft_strcpy(newstr, *str);
	ft_strcat(newstr, buf);
	ft_strdel(str);
	*str = ft_strdup(newstr);
	ft_strdel(&newstr);
	return (*str);
}

char				*write_in_line(char **line, char **fileline)
{
	size_t			i;
	char			*newstr;

	i = 0;
	while ((*fileline)[i] != '\n' && (*fileline)[i])
		i++;
	if ((*fileline)[i] == '\0' && !is_space_line(*fileline))
		error_exit(ERR_NO_NEW_LINE);
	*line = ft_strnew(i);
	ft_strncpy(*line, *fileline, i);
	if (*fileline && ft_strchr(*fileline, '\n'))
		newstr = ft_strdup(ft_strchr(*fileline, '\n') + 1);
	else
		newstr = NULL;
	(*line)[i] = '\0';
	ft_strdel(fileline);
	return (newstr);
}

int					gnl_spec(int fd, char **line)
{
	size_t			count_bytes;
	char			buf[BUFF_SIZE + 1];
	static char		*str;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	while ((count_bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[count_bytes] = '\0';
		if (!str)
			str = ft_strnew(0);
		str = ft_strjoin_sp(&str, buf, ft_strlen(str));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!str || !ft_strlen(str))
	{
		ft_strdel(&str);
		return (0);
	}
	str = write_in_line(line, &str);
	return (1);
}
