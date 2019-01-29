NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRC = main.c get_next.c checknb.c\

HEADER = fillit.h

LIBFT = libft/libft.a

OBJ = main.o get_next.o checknb.o\

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
