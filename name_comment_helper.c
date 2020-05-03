#include "asm.h"

static char			*ft_strjoin_sp(char **str, char *buf, size_t len)
{
	char		*newstr;

	if (!(newstr = ft_strnew(len + ft_strlen(buf) + 2)))
		exit(-1);
	ft_strcpy(newstr, *str);
	newstr[ft_strlen(*str)] = '\n';
	ft_strcat(newstr, buf);
	ft_strdel(str);
	*str = ft_strdup(newstr);
	ft_strdel(&newstr);
	ft_strdel(&buf);
	return (*str);
}

void				go_to_new_line(t_champion **champ, char **line)
{
	char			*tmp_line;

	if (gnl_spec((*champ)->fd, &tmp_line) < 1)
		error_exit(ERR_UNEXP_EOF);
	*line = ft_strjoin_sp(line, tmp_line, ft_strlen(*line));
	g_current_string++;
}

void				check_end_of_line(char *line, int i)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] != '\0' && line[i] != COMMENT_CHAR && line[i] \
			!= ALT_COMMENT_CHAR)
		error_exit(ERR_UNEXP_SYM);
}
