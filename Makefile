CC	=	gcc

RM	=	rm -rf

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-I ./inc

CFLAGS	=	-W -Wall -Wextra

LDFLAGS	=

NAME	=	chip_8

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
