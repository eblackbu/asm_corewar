#include "asm.h"
#include <stdio.h>

void	print_args(t_instr *code)
{
	int		i;
	t_instr	*tmp;

	tmp = code;
	printf("\nCode: \n");
	while (tmp)
	{
		i = 0;
		printf("%s ", tmp->type.name);
		while (i < tmp->type.count_args)
		{
			//if (tmp->args[i].label_name)
				//printf(":%s, ", tmp->args[i].label_name);
			//else
				printf("%d, ", tmp->args[i].value);
			i++;
		}
		printf("\n");
		tmp = tmp->next;
	}
	printf("\n");
}

void	print_labels(t_label *labels)
{
	int 	i;
	t_label	*tmp;

	tmp = labels;
	printf("\nLabels: \n");
	while (tmp)
	{
		printf("%s: ", tmp->name);
		i = 0;
		if (tmp->instr)
		{
			while (i < tmp->instr->type.count_args)
			{
				if (tmp->instr->args[i].label_name)
					printf(":%s, ", tmp->instr->args[i].label_name);
				else
					printf("%d, ", tmp->instr->args[i].value);
				i++;
			}
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
	champ = create_champ(fd, av[1]);
	close(fd);
	//ft_putendl(champ->file_name);
	//ft_putendl(champ->name);
	//ft_putendl(champ->comment);
	//print_labels(champ->labels);
	//print_args(champ->code);
	make_byte_strings(&champ);
	print_to_file(&champ);
	free_all(champ);
	return (0);
}