CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
SRC = src/minimap.c src/prepare_data.c  src/moves.c src/main.c src/check_file_content.c \
src/gc.c src/validate_texturs.c src/add_colors.c src/validate_map.c src/check_file_name_content.c \
src/check_colors.c src/add_map_line.c src/check_closed_map.c src/change_spaces_in_map.c \
src/map_helper.c src/utils.c src/dda.c src/file2.c src/file3.c src/file4.c

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