SRCS = test.c

CFLAGS = -Wall -Wextra -Werror 
OBJS = $(SRCS:.c=.o)
MLX = -lmlx -lm -lXext -lX11 -lz
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	cc $(CFLAGS) $(OBJS) $(MLX) -lX11 -lXext -o $@

%.o: %.c
	cc $(CFLAGS) -c $<

$(MLX):
	make all -C mlx
clean:
	rm -f $(OBJS) $(BOBJS)
fclean: clean
	rm -f $(NAME)