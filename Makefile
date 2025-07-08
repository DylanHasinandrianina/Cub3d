CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -Ilibft/includes -Iminilibx-linux -g
SRCS = cub3d.c parsing.c
OBJS = $(SRCS:.c=.o)
NAME = cub3d
MLX = -Lminilibx-linux -lmlx -lX11 -lXext
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx-linux
	$(CC) $(OBJS) $(LIBFT) $(MLX) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./minilibx-linux clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re