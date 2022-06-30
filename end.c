/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** end
*/
#include "my.h"

void end(all_t *all)
{
    const int status[8] = {0, 0, 0, 0, 0, 0, 0, 1};

    if (all->manager == GAME_OVER) {
        set_button_status(all->button, status);
        sfMusic_stop(all->game_info->game_music);
        sfRenderWindow_drawSprite(all->init->window,
            all->game_info->game_over, NULL);
    }
}
