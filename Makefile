NAME = Cub3d
CFLAGS = -g3 -Wall -Wextra -Werror
CC = cc

Cubfiles = src/main.c src/utils.c

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

OBJ_cub = $(Cubfiles:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ_cub)
	$(CC) $(OBJ_cub) -lm -lmlx -Lminilibx-linux -lXext -lX11 -o $(NAME)


clean:
	rm -f $(OBJ_cub)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
.SECONDARY: $(OBJ_cub)