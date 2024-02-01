NAME = so_long
SRC = so_long.c ft_putstr.c ft_strcmp.c ft_strlen.c get_next_line.c get_next_line_utlis.c ft_strlen_2.c fun_check.c fun_map.c fun_player.c
OBJ = $(SRC:.c=.o)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
