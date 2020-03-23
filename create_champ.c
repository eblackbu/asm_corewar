#include "asm.h"

int				get_code_size(t_champion *champ)
{
	t_instr		*tmp;
	int 		code_size;

	code_size = 0;
	tmp = champ->code;
	while (tmp)
	{
		code_size += tmp->full_size;
		tmp = tmp->next;
	}
	return (code_size);
}

t_champion		*create_champ(int fd)
{
	t_champion	*champ;

	if (!(champ = (t_champion*)malloc(sizeof(t_champion))))
		exit(-1);
	champ->fd = fd;
	get_name_comment(&champ);
	champ->code = NULL;
	champ->labels = NULL;
	get_code(&champ);
	champ->code_size = get_code_size(champ);
	return (champ);
}