/*
** EPITECH PROJECT, 2022
** my__defender
** File description:
** button
*/

#include <SFML/Graphics.h>

#ifndef BUTTON_H
    #define BUTTON_H

typedef struct button_s
{
    sfRectangleShape *rect;
    sfFloatRect placement;
} button_t;

typedef struct window_s
{
    sfVideoMode param;
    sfRenderWindow *window;
}window_t;

typedef struct sprite_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfIntRect rect;
    sfTime time;
    sfVector2f position;
}sprite_t;

typedef struct global_s {
    button_t **button;
    sprite_t **sprite_tower;
    sprite_t **sprite_foes;
} global_t;

sprite_t *def_sprite(sfIntRect rect, sfVector2f position);
global_t *init_sprite(sfVector2f position);
int up_left(global_t *global, sfVector2f position, sfVector2f size);
int up_right(global_t *global, sfVector2f position, sfVector2f size);
int down_right(global_t *global, sfVector2f position, sfVector2f size);
int down_left(global_t *global, sfVector2f position, sfVector2f size);
int pop_up(global_t *global, sfVector2f position, sfVector2f size);
void main_scene(window_t *window);
void main_screen(global_t *global);
global_t *init_button(sfVector2f position ,sfVector2f size );
sfRenderWindow *init_window(window_t *window);
bool button_is_clicked(sfVector2f size, sfVector2f but_pos, sfVector2i mouse);

#endif
