##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile my_runner
##

ECHO = /bin/echo -e
DEFAULT = "\033[00m"
BOLD = "\e[1m"
RED = "\e[31m"
GREEN = "\e[32m"
LIGHT_BLUE = "\e[94m"
WHITE = "\e[1;37m"

SRC	=	lib/my_putchar.c	\
		lib/my_putstr.c	\
		src/create_object/create_object.c	\
		src/renderwindow.c	\
		src/create_object/create_object2.c	\
		src/create_object/create_mob.c	\
		src/create_object/create_wife.c	\
		src/create_object/create_bag.c	\
		src/move/move_object.c	\
		src/move/move_object2.c	\
		src/move/move_spell.c	\
		src/move/move_ranger.c	\
		src/move/move_wife.c	\
		src/inventory/create_inventory.c	\
		src/inventory/print_inventory.c	\
		src/inventory/put_inventory.c	\
		src/menu/background_menu.c	\
		src/menu/button_menu.c	\
		src/menu/click_button.c	\
		src/menu/main_menu.c	\
		src/menu/settings_menu.c	\
		src/menu/create_butt_return.c	\
		src/menu/click_butt_return.c	\
		src/my_gameplay.c	\
		src/my_rpg.c	\
		src/stat/create_stat.c	\
		src/stat/give_stats.c	\
		src/stat/upgrade_stat.c	\
		src/pause/create_button_text.c	\
		src/pause/click_but_pause.c	\
		src/stat/create_text_stat.c	\
		lib/my_revstr.c	\
		lib/my_strlen.c	\
		lib/itoa.c	\
		lib/my_strcat.c	\
		src/class/chose_class.c	\
		src/class/class_text.c	\
		src/battle/create_battle_text.c	\
		src/battle/create_battle.c	\
		src/battle/print_battle.c	\
		src/battle/move_battle.c	\
		src/battle/move_battle2.c	\
		src/battle/button_battle.c	\
		src/battle/start_battle.c	\
		src/battle/create_battle2.c	\
		src/game_over/create_gameover.c	\
		src/game_over/interaction_but.c	\
		src/battle/clock_battle.c	\
		src/battle/contact_ennemy.c	\
		src/dialogue/create_texte_dialogue.c	\
		src/dialogue/print_dialogue.c	\
		src/dialogue/verif_proxi.c	\
		src/dialogue/clock_dialogue.c	\
		src/create_object/destroy_object.c	\
		src/battle/destroy_battle.c	\
		src/dialogue/create_dialogue_balk_anny.c	\
		src/boucle_inf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-Wall -Wextra  -I includes/ -lcsfml-graphics -lcsfml-window
all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -lcsfml-audio -lm -lcsfml-system

	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

debug:	CFLAGS += -g
debug:	re

re:	fclean all

tests_run:
		gcc -o unit_test $(SRC) -L . -lmy -lcriterion --coverage
		./unit_test

%.o:	%.c
	@$(CC) -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)" [OK] " \
	$(WHITE) || $(ECHO) -n $(BOLD) $(RED)" [KO] "$(WHITE) && $(ECHO) \
	$(BOLD) $< | rev | cut -d/ -f 1 | rev && $(ECHO) -n $(DEFAULT)
