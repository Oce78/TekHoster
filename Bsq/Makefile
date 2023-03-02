##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile
##

SRC		= 	./sources/my_putstr.c\
			./sources/my_putchar.c\
			./show_square.c\
			./solver.c\
			./read_map.c\
			./bsq.c\
			./bsq_utils.c\

NAME    =	bsq

CFLAGS 	=	-Wall -Wextra -I include

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
