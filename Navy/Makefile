##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile
##

SRC		= 	./navy.c\
			./my_lib.c\
			./map.c\
			./map_check.c\
			./signals.c\
			./signals_msg.c\
			./init.c\
			./game.c\
			./game_cases.c\

NAME    =	navy

CFLAGS 	=	-Wall -Wextra -I includes

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f *~
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
