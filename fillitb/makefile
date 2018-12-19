NAME = fillit

//CFLAGS = -Wall -Wextra -Werror

SRC = get_next.c input.c ft_strcat2.c	\

HEADER = header.h

LIBFT = libft/libft.a

OBJ = get_next.o input.o ft_strcat2.o	\

all: $(NAME)

$(NAME):
	gcc -c $(SRC)  $(LIBFT)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
