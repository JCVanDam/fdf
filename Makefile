NAME = fdf
SRC = srcs/main.c srcs/draw_line.c srcs/manage_display.c \
	srcs/check_get_map.c srcs/ft_convert_base.c srcs/event.c
FLAGS = -I includes -I libft -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: lib $(NAME)

lib:
	make -C libft/

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all
