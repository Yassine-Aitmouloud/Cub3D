NAME = Cub3d
CFLAGS = -Wall -Wextra -Werror
CC = cc

CFILES = src/main.c 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(CFILES:.c=.o)


all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lmlx -lXext -lX11 -o $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)