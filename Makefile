NAME = asm

FLAGS = -Wall -Wextra -Werror

SRC = byte_strings.c \
	  code_analyzer.c \
	  create_champ.c \
	  error_args.c \
	  error_exit.c \
	  fill_instr.c \
	  fill_labels.c \
	  free_all.c \
	  get_instr.c \
	  get_label.c \
	  gnl_spec.c \
	  main.c \
	  name_comment.c \
	  name_comment_helper.c \
	  op.c \
	  print_to_file.c \
	  replace_labels.c \
	  set_argument.c \
	  set_byte_values.c \
	  utils.c \
	  validate_file.c

%.o: %.c
	gcc $(FLAGS) -Ilibft -Llibft -lft -c $< -o $@

OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ) op.h errors.h asm.h
	@make -C libft re
	gcc $(FLAGS) $(OBJ) -Ilibft -Llibft -lft -o $(NAME)

clean:
	make -C libft clean
	/bin/rm -f *.o

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME) libft.a

re: fclean all
