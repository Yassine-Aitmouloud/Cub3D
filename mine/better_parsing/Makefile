CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = cub3d.c parse_file.c gc.c validate_texturs.c validate_colors.c validate_map.c

OBJ = $(SRC:.c=.o)
NAME = cub3D
LIBFT = libft/libft.a


all: $(LIBFT) $(NAME) 

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re: fclean all