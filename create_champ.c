#include "asm.h"

t_champion		*create_champ(int fd)
{
	t_champion	*champ;

	if (!(champ = (t_champion*)malloc(sizeof(t_champion))))
		exit(-1);
	champ->fd = fd;
	get_name_comment(&champ);
	return (champ);
}