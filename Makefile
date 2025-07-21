CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = main.c conf_file_pars.c

OBJ = $(SRC:.c=.o)
NAME = cub
LIBFT = libft/libft.a


all: $(LIBFT) $(NAME) 

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -lreadline -lhistory -o $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re: fclean all