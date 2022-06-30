/*
** EPITECH PROJECT, 2022
** pause_game
** File description:
** defender
*/

#include "my.h"

void time_game(game_t *game_info)
{
    correct_malloc(game_info->buffer_gold, game_info->gold_nb);
    int_to_str(game_info->gold_nb, game_info->buffer_gold);
    if (game_info->seconde >= 59) {
        game_info->minute += 1;
        game_info->seconde = 0;
        correct_malloc(game_info->buffer_seconde, 3);
    }
    game_info->buffer_minute[1] = ' ';
    int_to_str(game_info->minute, game_info->buffer_minute);
    game_info->buffer_minute[2] = ':';
    sfText_setString(game_info->text_minute, game_info->buffer_minute);
    if (time_as_sc(game_info->time) > 1.0) {
        game_info->seconde += 1;
        int_to_str(game_info->seconde, game_info->buffer_seconde);
        sfText_setString(game_info->text_seconde, game_info->buffer_seconde);
        sfClock_restart(game_info->time);
    }
}

void escape_to_pause(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        all->game_info->status_pause = 1;
    if (!sfKeyboard_isKeyPressed(sfKeyEscape) &&
        all->game_info->status_pause == 1) {
        all->game_info->status_pause = 0;
        all->manager = PAUSE;
    }
}

void pause_game(all_t *all)
{
    const int status[8] = {0, 1, 1, 0, 1, 0, 0, 0};

    if (all->manager == PAUSE) {
        set_button_status(all->button, status);
        sfSprite_setPosition(all->game_info->menu_pause,
            (sfVector2f){550, 100});
        draw_game(all->init, all->game_info);
        draw_mobs(all->init, all->anim, &all->mobs);
        draw_set_towers(all->init, &all->all_tower);
        sfRenderWindow_drawSprite(all->init->window,
            all->game_info->menu_pause, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            all->game_info->status_pause = 1;
        }
        if (!sfKeyboard_isKeyPressed(sfKeyEscape) &&
            all->game_info->status_pause == 1) {
            all->game_info->status_pause = 0;
            all->manager = GAME;
        }
    }
}
