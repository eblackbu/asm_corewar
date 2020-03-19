#include "asm.h"

void	error_exit(int code)
{
	if (code == ERR_NO_AC)
		ft_putstr("Usage: ./asm <champ.s>\n");
	else if (code == ERR_FILE_NOT_S)
		ft_putstr("Error: champion's file should be with .s extension\n");
	else if (code == ERR_NO_FILE)
		ft_putstr("Error: champion's file not exists\n");
	exit(-1);
}