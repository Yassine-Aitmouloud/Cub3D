CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
SRC = src/main.c check_file_content.c gc.c validate_texturs.c add_colors.c validate_map.c check_file_name_content.c check_colors.c add_map_line.c check_closed_map.c change_spaces_in_map.c map_helper.c src/utils.c

OBJ = $(SRC:.c=.o)
NAME = cub3D
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a



all: $(LIBFT) $(NAME) 

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C minilibx-linux

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -lm -lz -o $(NAME) 

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(LIBFT) $(MLX) $(OBJ)