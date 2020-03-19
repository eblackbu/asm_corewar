#ifndef ASM_H
# define ASM_H

#include "op.h"
#include "libft.h"
#include "errors.h"
#include <fcntl.h>
#include <stdlib.h>

int 				current_string;

typedef struct		s_arg
{
	short			type;
	int				value;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_instr
{
	char 			*bytestr;
	//char 			operation;
	//char			types;
	int 			size;
	int				first_byte;
	t_arg			*args;
	int 			is_ready;
	struct s_instr	*next;
}					t_instr;

typedef struct		s_label
{
	t_instr			*instr;
	int				first_byte;
	struct s_label	*next;
}					t_label;

typedef struct	s_champlion
{
	t_instr		*code;
	t_label		*labels;
	int 		code_size;
	char 		*name;
	char 		*comment;
}				t_champion;

//error_exit.c
void		error_exit(int code);

//validate_file.c
int			validate_file(int ac, char **av);

#endif
