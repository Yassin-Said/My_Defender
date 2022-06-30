/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** button_h
*/

#ifndef BUTTON_H_
    #define BUTTON_H_
    #define MAX_ANIMATIONS (50)
    #define BUTTON_I (*all_buttons[i])->button
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdio.h>

typedef struct menu_tower_s {
    sfSprite **all_menu_asset;
    int incr;
    int status;
    int displayed[3];
} menu_tower_t;

typedef struct button_s {
    char *link;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *text;
    sfIntRect rect;
    char *pressed;
    sfBool status;
    sfBool sec_state;
    sfSprite *back;
}button_t;

typedef struct animable_sprite_s {
    sfSprite *sprite;
    sfTexture *tex;
    sfIntRect rects[MAX_ANIMATIONS];
    unsigned int rects_count;
    unsigned int current_animation;
    float last_animation_time;
    float animation_frame;
} animable_sprite_t;

typedef struct main_s {
    sfClock *clock;
    sfClock *move;
    animable_sprite_t *anim_all;
    animable_sprite_t knight;
    animable_sprite_t shadow;
    animable_sprite_t orc;
}main_t;

typedef struct tower_s {
    sfSprite *sprite;
    sfTexture *text;
    sfVector2f pos;
    sfIntRect size;
    sfText *draw_price;
    sfClock *time;
    int price;
    int lvl;
    int damage;
    int range;
    float reaload;
    sfCircleShape *circle;
    int dragged;
    sfBool slowing;
    sfBool tp;
    int speed_shoot;
    int memo_speed_shoot;
    struct tower_s *next;
} tower_t;

typedef struct mobs_s {
    sfSprite *sprite;
    sfTexture *text;
    int speed;
    int id;
    sfVector2f pos;
    int life;
    int mobs_life;
    sfBool tped;
    int where;
    struct mobs_s *next;
} mobs_t;

typedef struct game_s {
    sfSprite *back;
    sfSprite *gold;
    sfSprite *health;
    sfSprite *menu_pause;
    tower_t *all_towers;
    mobs_t *mobs;
    sfClock *time;
    sfText *text_seconde;
    sfText *text_minute;
    sfText *text_gold;
    sfFont *type_write;
    sfSprite *tuto;
    sfSprite *game_over;
    int pv;
    int status_pause;
    int gold_nb;
    int minute;
    int seconde;
    char buffer_gold[5];
    char buffer_seconde[3];
    char buffer_minute[5];
    sfMusic *game_music;
    sfSound *slap_sound;
    sfSoundBuffer *buffer_slap_sound;
    sfSound *tower_sound;
    sfSoundBuffer *buffer_tower_sound;
} game_t;

typedef struct menu_s {
    sfSprite *back;
    sfText *play_btn;
    int counting;
} menu_t;

typedef struct site_s {
    int pos;
    sfRectangleShape **all_site;
    int status[6];
} site_t;

typedef enum manager_s {
    GAME,
    GAME_OVER,
    PAUSE,
    MENU,
    MENU_LEVEL,
    TUTORIAL,
    WIN
} manager_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode video_mod;
    sfEvent event;
}window_t;

typedef struct event_button_s {
    int (*fonct)(button_t *, window_t *, manager_t *);
} event_button_t;

typedef struct all_s {
    button_t *button;
    window_t *init;
    manager_t manager;
    game_t *game_info;
    mobs_t *mobs;
    main_t *anim;
    site_t *all_site;
    menu_tower_t *tower_menu;
    tower_t *tower;
    tower_t *all_tower;
    menu_t *all_menu;
}all_t;

#endif
