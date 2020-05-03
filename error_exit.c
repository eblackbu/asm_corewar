#include "asm.h"

void	ft_printf_error(char *line)
{
	ft_putstr("Error in line ");
	ft_putnbr(g_current_string);
	ft_putstr(": ");
	ft_putstr(line);
}

void	error_file(int code)
{
	if (code == ERR_NO_AC)
		ft_putstr("Usage: ./asm <champ.s>\n");
	else if (code == ERR_FILE_NOT_S)
		ft_putstr("Error: champion's file should be with .s extension\n");
	else if (code == ERR_NO_FILE)
		ft_putstr("Error: champion's file not exists\n");
	else if (code == ERR_FILE_NOT_CREATED)
		ft_putstr("Error: file .cor can't be created\n");
	else if (code == ERR_NO_NEW_LINE)
		ft_putstr("Error: champion's file not ends with \\n\n");
}

void	error_format(int code)
{
	if (code == ERR_UNEXP_SYM)
		ft_printf_error("unexpected symbols\n");
	else if (code == ERR_UNEXP_EOF)
		ft_printf_error("unexpected EOF\n");
	else if (code == ERR_DOUBLE_NAME)
		ft_printf_error("champion's name was defined earlier\n");
	else if (code == ERR_DOUBLE_COMMENT)
		ft_printf_error("champion's comment was defined earlier\n");
	else if (code == ERR_NAME_LENGTH)
		ft_putstr("Error: champion's name is too long\n");
	else if (code == ERR_COMMENT_LENGTH)
		ft_putstr("Error: champion's comment is too long\n");
	else if (code == ERR_NULL_HEADER)
		ft_putstr("Error: there is no name or comment\n");
	else if (code == ERR_NO_CODE)
		ft_putstr("Error: there is no exec code champion\n");
}

void	error_asm(int code)
{
	if (code == ERR_LABEL_CHARS)
		ft_printf_error("forbidden symbols are used in label\n");
	else if (code == ERR_EMPTY_LABEL)
		ft_printf_error("label can't be empty\n");
}

void	error_exit(int code)
{
	if (code < 10)
		error_file(code);
	else if (code < 20)
		error_format(code);
	else if (code < 30)
		error_asm(code);
	exit(-1);
}
