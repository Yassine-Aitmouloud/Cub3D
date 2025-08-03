CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
SRC = cub3d.c parse_file.c gc.c validate_texturs.c validate_colors.c validate_map.c

OBJ = $(SRC:.c=.o)
NAME = cub3D
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a



all: $(LIBFT) $(MLX) $(NAME) 

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C minilibx-linux

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -lm -lz -o $(NAME) 

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re: fclean all