#include <sys/stat.h>
#include "asm.h"

void		print_int_hex(int fd, int value)
{
	char	*tmp;

	tmp = ft_strnew(3);
	tmp = ft_memcpy(tmp, &value, 4);
	tmp = reverse_string(tmp, 3);
	write(fd, tmp, 4);
	ft_strdel(&tmp);
}

void		print_str_hex(int fd, char *str, int len)
{
	int		i;

	i = ft_strlen(str);
	if (i >= len)
		write(fd, str, len);
	else
	{
		write(fd, str, i);
		while (i < len)
		{
			write(fd, "\0", 1);
			i++;
		}
	}
}

void		print_exec_code(int fd, t_champion **champ)
{
	t_instr	*tmp;

	tmp = (*champ)->code;
	while (tmp)
	{
		write(fd, tmp->bytestr, tmp->full_size);
		tmp = tmp->next;
	}
}

void		print_to_file(t_champion **champ)
{
	int		fd;

	fd = open((*champ)->file_name, \
	O_WRONLY | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	if (fd < 0)
		error_exit(ERR_FILE_NOT_CREATED);
	print_int_hex(fd, COREWAR_EXEC_MAGIC);
	print_str_hex(fd, (*champ)->name, PROG_NAME_LENGTH);
	write(fd, "\0\0\0\0", 4);
	print_int_hex(fd, (*champ)->code_size);
	print_str_hex(fd, (*champ)->comment, COMMENT_LENGTH);
	write(fd, "\0\0\0\0", 4);
	print_exec_code(fd, champ);
	close(fd);
}
