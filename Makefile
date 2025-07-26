NAME = Cub3d
CFLAGS = -g3 -Wall -Wextra -Werror -Werror
CC = cc

Cubfiles = src/main.c src/utils.c

libftfiles =  includes/libft/ft_atoi.c     includes/libft/ft_isalpha.c  includes/libft/ft_itoa.c  \
			  	includes/libft/ft_lstnew_bonus.c includes/libft/ft_memcpy.c includes/libft/ft_putendl_fd.c \
			  	includes/libft/ft_strchr.c includes/libft/ft_strlcat.c includes/libft/ft_strncmp.c  includes/libft/ft_substr.c \
				includes/libft/ft_bzero.c includes/libft/ft_isascii.c includes/libft/ft_lstadd_back_bonus.c includes/libft/ft_lstsize_bonus.c \
				includes/libft/ft_memmove.c includes/libft/ft_putnbr_fd.c includes/libft/ft_strdup.c includes/libft/ft_strlcpy.c \
				includes/libft/ft_strnstr.c  includes/libft/ft_tolower.c includes/libft/ft_calloc.c includes/libft/ft_isdigit.c \
				includes/libft/ft_lstadd_front_bonus.c  includes/libft/ft_memchr.c includes/libft/ft_memset.c includes/libft/ft_putstr_fd.c \
				includes/libft/ft_striteri.c  includes/libft/ft_strlen.c includes/libft/ft_strrchr.c includes/libft/ft_toupper.c \
				includes/libft/ft_isalnum.c  includes/libft/ft_isprint.c includes/libft/ft_lstlast_bonus.c includes/libft/ft_memcmp.c \
				includes/libft/ft_putchar_fd.c  includes/libft/ft_split.c includes/libft/ft_strjoin.c includes/libft/ft_strmapi.c \
				includes/libft/ft_strtrim.c \

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

OBJ_cub = $(Cubfiles:.c=.o)

OBJ_libft = $(libftfiles:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ_cub) $(OBJ_libft)
	$(CC) $(OBJ_cub) $(OBJ_libft) -lmlx -Lmlx -lXext -lX11 -o $(NAME)


clean:
	rm -f $(OBJ_cub) $(OBJ_libft) 

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
.SECONDARY: $(OBJ_cub) $(OBJ_libft)