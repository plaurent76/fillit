NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRC = fillit2.c get_next.c checknb.c

HEADER = fillit.h

LIBFT = libft/libft.a

OBJ = fillit2.o get_next.o checknb.o

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME)  $(CFLAGS) $(OBJ) $(LIBFT) -I $(HEADER)

clean:
	/bin/rm -f $(OBJ) *.a
.PHONY: clean
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
