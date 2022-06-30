/*
** EPITECH PROJECT, 2022
** set_all
** File description:
** defender
*/

#include "my.h"

void set_sound(all_t *all)
{
    all->game_info->tower_sound = sfSound_create();
    all->game_info->buffer_tower_sound =
        sfSoundBuffer_createFromFile("./assets/build.wav");
    sfSound_setBuffer(all->game_info->tower_sound,
        all->game_info->buffer_tower_sound);
    all->game_info->slap_sound = sfSound_create();
    all->game_info->buffer_slap_sound =
        sfSoundBuffer_createFromFile("./assets/slap.wav");
    sfSound_setBuffer(all->game_info->slap_sound,
        all->game_info->buffer_slap_sound);
    sfMusic_setVolume(all->game_info->game_music, 40);
    sfMusic_play(all->game_info->game_music);
    sfMusic_setLoop(all->game_info->game_music, sfTrue);
}

all_t *set_all(void)
{
    all_t *all = malloc(sizeof(all_t));

    all->init = NULL;
    all->manager = MENU;
    all->tower = set_tower();
    all->all_menu = set_menu();
    set_price_text(all->tower);
    all->all_tower = NULL;
    all->game_info = set_game();
    all->init = init_window(all->init);
    all->all_site = site();
    all->button = set_button();
    all->mobs = NULL;
    all->anim = malloc(sizeof(main_t));
    all->anim->clock = sfClock_create();
    all->anim->move = sfClock_create();
    all->tower_menu = menu_tower();
    set_sound(all);
    return (all);
}
