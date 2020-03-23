#include "asm.h"
#include <stdio.h>

void	print_args(t_instr *code)
{
	int		i;
	t_instr	*tmp;

	tmp = code;
	while (tmp)
	{
		i = 0;
		printf("%s ", tmp->type.name);
		while (i < tmp->type.count_args)
		{
			if (tmp->args[i].label_name)
				printf(":%s, ", tmp->args[i].label_name);
			else
				printf("%d, ", tmp->args[i].value);
			i++;
		}
		printf("\n");
		tmp = tmp->next;
	}
}

int 	main(int ac, char **av)
{
	t_champion	*champ;
	int			fd;

	fd = validate_file(ac, av);
	champ = create_champ(fd);
	ft_putendl(champ->name);
	ft_putendl(champ->comment);
	print_args(champ->code);
	//print_to_file(champ);
	return (0);
}