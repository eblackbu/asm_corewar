#include "asm.h"

int 	main(int ac, char **av)
{
	t_champion	*champ;
	int			fd;

	fd = validate_file(ac, av);
	champ = create_champ(fd);
	ft_putendl(champ->name);
	ft_putendl(champ->comment);
	//print_to_file(champ);
	return (0);
}