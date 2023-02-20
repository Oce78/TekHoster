##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile
##

SRC		=	./my_sokoban.c\
			./my_lib.c\
			./map.c\
			./game.c\
			./check.c\
			./my_str_to_word_array.c\
			./init_player.c\
			./move_player.c\

NAME    =	my_sokoban

CFLAGS 	=	-g -Wall -Wextra -I includes

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses
	rm -f $(OBJ)

clean:
	rm -f *~
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
