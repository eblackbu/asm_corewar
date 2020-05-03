#include "asm.h"

int		main(int ac, char **av)
{
	t_champion	*champ;
	int			fd;

	fd = validate_file(ac, av);
	champ = create_champ(fd, av[1]);
	close(fd);
	make_byte_strings(&champ);
	print_to_file(&champ);
	free_all(champ);
	return (0);
}
