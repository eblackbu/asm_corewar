/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:56:27 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/03 13:56:30 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"
# include "errors.h"
# include <fcntl.h>
# include <stdlib.h>

# define REG_BYTE 1
# define IND_BYTE 2
# define DIR_BYTE 4

typedef struct		s_arg
{
	int				type;
	int				value;
	char			*label_name;
}					t_arg;

typedef struct		s_type
{
	char			*name;
	int				count_args;
	t_arg_type		bit_args[3];
	int				number;
}					t_type;

typedef struct		s_instr
{
	t_type			type;
	int				first_byte;
	t_arg			*args;
	unsigned char	instr_byte;
	int				full_size;
	char			*bytestr;
	struct s_instr	*next;
}					t_instr;

typedef struct		s_label
{
	t_instr			*instr;
	char			*name;
	int				first_byte;
	struct s_label	*next;
}					t_label;

typedef struct		s_champlion
{
	t_instr			*code;
	t_label			*labels;
	int				code_size;
	int				fd;
	char			*name;
	char			*comment;
	char			*file_name;
}					t_champion;

extern int			g_current_string;
extern t_type		g_type_tab[17];

/*
** create_champ.c
*/
int					get_code_size(t_champion *champ);
char				*set_filename(char *filename);
void				get_code(t_champion **champ);
t_champion			*create_champ(int fd, char *filename);

/*
** code_analyzer.c
*/
int					is_space_line(const char *line);
int					is_label(char *line);
int					ft_strcmp_spec(const char *s1, const char *s2);
int					compare_instr(char *line);
int					is_instr(char *line);

/*
** ----------------
** NAME AND COMMENT
** ----------------
*/

/*
** validate_file.c
*/
int					validate_file(int ac, char **av);

/*
** name_comment.c
*/
char				*get_champ_string(t_champion **champ, char *line, int i);
char				*find_name(t_champion **champ, char *line);
char				*find_comment(t_champion **champ, char *line);
void				get_name_comment(t_champion **champ);

/*
** name_comment_helper.c
*/
void				go_to_new_line(t_champion **champ, char **line);
void				check_end_of_line(char *line, int i);

/*
** ------------
** INSTRUCTIONS
** ------------
*/

/*
** get_instr.c
*/
t_instr				*add_new_instr(t_champion **champ, char *line);
t_instr				*get_instr(t_champion **champ, char *line);

/*
** fill_instr.c
*/
int					set_argtype(int argtype, t_instr **new_instr, \
							int num_arg, char *line);
void				get_args_type(char *line, t_instr **new_instr);
t_instr				*fill_instr(t_champion **champ, t_instr *new_instr, \
							char *line);

/*
** set_argument.c
*/
char				*set_arglabel(char *line);
int					set_argvalue(char *line, int argtype, int num_arg);
void				set_argument(t_instr **new_instr, char *line, int num_arg);

/*
** set_byte_values.c
*/
int					get_first_byte(t_champion **champ);
int					get_full_size(t_instr *new_instr);

/*
** ------
** LABELS
** ------
*/

/*
** get_label.c
*/
void				add_new_label(t_champion **champ, char *line, int len);
t_instr				*find_instr_line(t_champion **champ, char **line);
void				get_label(t_champion **champ, char *line);

/*
** fill_labels.c
*/
t_instr				*find_instr_to_label(t_label *label_to_find);
void				fill_labels(t_champion **champ);

/*
** replace_labels.c
*/
int					get_indirent_value(t_champion **champ, t_instr *instr, \
							int arg_num);
t_instr				*check_labels(t_champion **champ, t_instr *instr);
void				replace_labels(t_champion **champ);

/*
** byte_strings.c
*/
void				value_to_bytes(char **arg, int value, int len);
int					get_arg_len(t_instr **instr, t_arg arg);
void				set_arg_to_string(t_instr **instr, int *i, t_arg arg);
void				make_one_string(t_instr **instr);
void				make_byte_strings(t_champion **champ);

/*
** -------------
** PRINT_TO_FILE
** -------------
*/

/*
** print_to_file.c
*/
void				print_int_hex(int fd, int value);
void				print_str_hex(int fd, char *str, int len);
void				print_exec_code(int fd, t_champion **champ);
void				print_to_file(t_champion **champ);

/*
** ------
** ERRORS
** ------
*/

/*
** error_exit.c
*/
void				ft_printf_error(char *line);
void				error_exit(int code);

/*
** error_args.c
*/
void				print_error_with_arg(char *str, int num_arg);
void				error_args(int code, int num_arg);

/*
** -----
** OTHER
** -----
*/

/*
** free_all.c
*/
void				free_instr(t_instr *instr);
void				free_labels(t_label *label);
void				free_all(t_champion *champ);

/*
** utils.c
*/
char				*reverse_string(char *str, int n);

/*
** gnl_spec.c
*/
int					gnl_spec(int fd, char **line);

#endif
