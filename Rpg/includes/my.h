/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** for functions
*/

#include "my_rpg.h"

#ifndef MY_H_
    #define MY_H_

    void clock_attack(struct_object *object);
    void create_clock_attack(struct_object *object);
    void create_warrior(struct_object *object);
    void create_ranger(struct_object *object);
    void create_spellcaster(struct_object *object);
    void create_balk_anny(struct_object *obj);
    void create_blob(struct_object *obj);
    sfRenderWindow *create_window(struct_object *object);
    void create_background(struct_object *object);
    void clock(struct_object *object, sfRenderWindow *window);
    void create_clock(struct_object *object);
    float create_music(struct_object *object);
    void render_window(struct_object *object, sfRenderWindow *window);
    void move_warrior(struct_object *object, sfRenderWindow *window);
    void mouvement_x(struct_object *object, sfRenderWindow *window);
    void mouvement_x_back(struct_object *object, sfRenderWindow *window);
    void mouvement_y_up(struct_object *object, sfRenderWindow *window);
    void mouvement_y_down(struct_object *object, sfRenderWindow *window);
    void mouvement_spellback(struct_object *obj);
    void mouvement_spellfor(struct_object *object);
    void mouvement_spellup(struct_object *object);
    void mouvement_spelldown(struct_object *object);
    void mouvement_rangerback(struct_object *obj);
    void mouvement_rangerfor(struct_object *object);
    void mouvement_rangerup(struct_object *object);
    void mouvement_rangerdown(struct_object *object);
    void move_idle_balk(struct_object *obj);
    void move_blob(struct_object *obj);
    void destroy(struct_object *object, sfRenderWindow *window);
    void create_object(struct_object *object);
    void move_object(struct_object *object, sfRenderWindow *window);
    void create_inventory(struct_object *object);
    void put_inventory(struct_inventory **inventory,
    struct_baguette *baguette);
    void print_inventory(struct_object *object, sfRenderWindow *window);
    void create_text_inventory(struct_object *object);
    int second_window(struct_object *object, sfRenderWindow *window);
    void create_stat(struct_object *object);
    void give_stat(stats_t *stat);
    void print_stat(struct_object *object, sfRenderWindow *window);
    void create_number_text_stat(struct_object *object);
    char *itoa(int i);
    void choose_class(struct_object *object, sfRenderWindow *window);
    void create_class_text(struct_object *obj);
    char *my_strcat(char *str1, char const *str2);
    void print_battle(struct_object *obj, struct_charachter foe);
    void create_text_battle(struct_object *object, struct_charachter foe);
    struct_charachter init_battle(struct_object *object,
    struct_charachter foe);
    struct_charachter create_button_battle(struct_object *obj,
    struct_charachter foe);
    void move_battle(struct_object *object, struct_charachter foe);
    void start_battle(struct_object *obj, struct_charachter foe);
    void create_over(struct_object *obj);
    void pos_over(sfRenderWindow *window, sfEvent *event, struct_object *obj);
    void create_hero_battle(struct_object *obj);
    void create_button_stat(struct_object *obj);
    void move_ranger_batt(struct_object *obj);
    void put_numbers_in_text(struct_object *object);
    void verif_if_contact(struct_object *object);
    void create_wife(struct_object *object);
    void move_wife(struct_object *object);
    void create_dialogue(struct_object *object);
    void print_dialogue_balk_anny(struct_object *object);
    void print_dialogue_wife(struct_object *object);
    void verif_proxi_balk_anny(struct_object *obj);
    void clock_dialogue_wife(struct_object *obj);
    void clock_dialogue_balk_anny(struct_object *obj);
    void create_clock_dialogue(struct_object *obj);
    void create_bag(struct_object *object);
    void verif_proxi_wife(struct_object *obj);
    void create_new_text_dialogue(struct_object *obj);
    void destroy_battle(struct_object *object);
    void destroy_stat(struct_object *object);
    void destroy_object(struct_object *object, sfRenderWindow *window);
    void destroy_inventory(struct_object *object);
    void destroy_class_text(struct_object *obj);
    void create_dialogue_balk_anny(struct_object *object);
    void create_return_menu(struct_object *obj);
    void click_return(sfRenderWindow *window, struct_object *object);
    void boucle_inf(struct_object *object, sfRenderWindow *window, t_gbl opti,
    float volume);
    void menu(struct_object *object, sfRenderWindow *window, t_gbl opti);

#endif /* !MY_H_ */
