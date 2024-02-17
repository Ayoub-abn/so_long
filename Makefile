NAME = so_long
NAME_1 = so_long_bonus

SRC = so_long.c ft_putstr.c ft_strcmp.c \
	ft_strlen.c get_next_line.c get_next_line_utlis.c\
	ft_strlen_2.c fun_map.c fun_player.c ft_itoa.c moves.c\
	draw.c fun_map_2.c ft_memset.c ft_strrchr.c 

BSRC = so_long_bonus.c moves_bonus.c image_con_bonus.c get_next_line.c \
	get_next_line_utlis.c fun_player_bonus.c fun_map.c fun_map_3_bonus.c \
	fun_map_2_bonus.c draw_bonus.c attack_bonus.c ft_putstr.c ft_strcmp.c \
	ft_strlen.c ft_itoa.c ft_strlen_2.c ft_memset.c ft_strrchr.c 

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

FLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FLAGS) -o $(NAME)

bonus: $(NAME_1)

$(NAME_1): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) $(FLAGS) -o $(NAME_1)

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME) $(NAME_1)

re: fclean all
