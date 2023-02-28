/*
** EPITECH PROJECT, 2021
** my_runner.h
** File description:
** structure
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdbool.h>

#ifndef MY_RPG_H_INCLUDED
    #define MY_RPG_H_INCLUDED

typedef struct trucs {
    int x;
    int y;
    int size_x;
    int size_y;
    sfTexture *texture;
    sfSprite *sprite;
} trucs;

typedef struct s_object {
    sfSprite *sprt;
    sfTexture *texture;
    sfIntRect rect_anim;
    int anim_size;
    int anim_width;
    sfIntRect rect;
    sfVector2f speed;
    sfVector2f pos;
} t_object;

typedef struct s_game {
    sfMusic *music;
    sfEvent event;
    sfVideoMode mode;
    sfClock *clock;
    int frame_rate;
    int num_player;
} t_game;

typedef struct btn_s {
    int x;
    int y;
    int size_x;
    int size_y;
    sfTexture *texture;
    sfSprite *sprite;
} btn_t;

typedef struct s_gbl {
    trucs backg;
    btn_t play;
    btn_t set_tings;
    btn_t volumed;
    btn_t volumeu;
    btn_t quit;
    t_game game;
    t_object player;
} t_gbl;

typedef struct charachter
{
    sfSprite *sprite;
    sfSprite *sprite_fight;
    sfTexture *texture_fight;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f position;
    sfVector2f recup;
    int counter;
    int health;
    int pv;
    int x;
    int size_x;
    int size_y;
    bool death;
} struct_charachter;

typedef struct clock
{
    sfTime time;
    sfClock *clock;
    float seconds;
} struct_clock;

typedef struct background
{
    sfSprite *background;
    sfTexture *background_text;
    sfIntRect back;
    sfVector2f pos;
} struct_background;

typedef struct window
{
    sfVideoMode mode;
    sfRenderWindow *window;
} struct_window;

typedef struct music
{
    sfMusic *music;
} struct_music;

typedef struct event
{
    sfEvent event;
} struct_event;

typedef struct text
{
    sfText *text_invent;
    sfFont *font_text_invent;
} struct_text;

typedef struct baguette {
    sfSprite *baguette_s;
    sfTexture *baguette_t;
    sfIntRect baguette_r;
    sfVector2f pos_baguette;
} struct_baguette;

typedef struct inventory {
    sfSprite *inv_s;
    sfTexture *inv_t;
    sfIntRect inv_r;
    sfVector2f pos;
    struct_baguette *baguette;
    bool used;
} struct_inventory;

typedef struct stats_s {
    int strenght;
    int health;
    int wisdom;
    int dext;
    int luck;
    int used;
    int nmbr_class;
    int lvl;
    int exp;
    int pv;
    sfSprite *stat_s;
    sfTexture *stat_t;
    sfIntRect stat_r;
    int nbr_of_point;
    sfVector2f pos;
}stats_t;

typedef struct class_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
}class_t;

typedef struct dialogue_s {
    struct_text text_hero;
    struct_text text_wife;
    struct_text text_balk_anny;
    struct_clock clock;
    bool can_print;
}dialogue_t;

typedef struct battle_s {
    struct_text **text_battle;
    struct_background battle_back;
    struct_charachter foe;
    int health_enemy;
    int health_hero;
    int damage_attack1;
    int damage_attack2;
    int damage_attack3;
    bool battle_beg;
    bool can_attack;
}battle_t;

typedef struct object
{
    struct_text text_class;
    struct_charachter hero;
    dialogue_t dialogue_wife;
    dialogue_t dialogue_balk_anny;
    struct_charachter balk_anny;
    struct_charachter current_ennemy;
    struct_charachter **blob;
    struct_charachter wife;
    struct_charachter bag;
    struct_clock clock;
    struct_clock clock_attack;
    struct_clock clock_battle;
    struct_window window;
    struct_background background;
    struct_background game_over;
    struct_music music;
    struct_music music_battle;
    struct_music music_over;
    struct_event event;
    btn_t but_continue;
    btn_t but_exit;
    btn_t but_over;
    btn_t return_settings;
    struct_text text_invetory;
    struct_text text_stat;
    struct_text text_pause;
    struct_inventory **inventory;
    struct_text **text_number_stat;
    stats_t *stat;
    battle_t battle;
    class_t **class;
    int play;
    int settings;
    bool create;
    bool print_inventory;
    bool print_stat;
    bool print_pause;
    bool bag_in_invent;
    bool over;
} struct_object;

void background(t_gbl *opti);
void title_menu(t_gbl *opti);

void play(t_gbl *opti);
void button_settings(t_gbl *opti);
void button_quit(t_gbl *opti);

void create_button(struct_object *object);

void pos_play(sfRenderWindow* window, struct_object *object);
void pos_settings(sfRenderWindow* window, struct_object *object);
void pos_quit(sfRenderWindow* window, struct_object *object);
void click_voldown(sfRenderWindow *window, struct_object *obj, float volume);
void click_volup(sfRenderWindow *window, struct_object *obj, float volume);

void click_but(sfRenderWindow *window, sfEvent event, struct_object *object);

int menu_defender(struct_object *object);
int init_music(t_gbl *gbl);
void move_rect(sfIntRect *rect, int offset, int max_value);

void init_player_struct(t_gbl *gbl);
void anim_player(t_gbl *gbl);
void new_player(t_gbl *gbl);
int init_game_struct (t_gbl *gbl);
int init_sprites(t_gbl *gbl);

void close_graphics (t_gbl *gbl);
int window_settings(t_gbl *gbl, sfRenderWindow *window, struct_object *obj,
float volume);

#endif
