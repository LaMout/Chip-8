CC	=	gcc

RM	=	rm -rf

SRC	=	src/main.c 			\
		src/cpu.c 			\
		src/chip8.c			\
		src/memory_dump.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-I ./inc

CFLAGS	=	-W -Wall -Wextra

LDFLAGS	=	-lcsfml-window -lcsfml-graphics -lcsfml-system

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
