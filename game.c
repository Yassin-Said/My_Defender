/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** game
*/

#include <stdio.h>
#include "my.h"

int which_index(int where)
{
    int position[] = {450, 600, 900, 1050, 1380, 1750, 2070, 2430, 2750, 2920,
        3240, 3400};
    int index = 0;

    for (; index <= 11; index++) {
        if (where < position[index])
            return index;
    }
    return (index);
}

void loop_move(all_t *all)
{
    mobs_t *cpy_mobs = all->mobs;
    sfVector2f pos[13] = {{1, 0}, {0, 1}, {1, 0}, {0, -1}, {1, 0}, {0, 1},
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}, {1, 0}, {0, 1}, {1, 0}};

    if (time_as_sc(all->anim->move) > 0.01) {
        cpy_mobs = all->mobs;
        while (cpy_mobs != NULL) {
            sfSprite_setPosition(all->anim->anim_all[cpy_mobs->id].sprite,
                cpy_mobs->pos);
            cpy_mobs->pos.x +=
                pos[which_index(cpy_mobs->where)].x * cpy_mobs->speed;
            cpy_mobs->pos.y +=
                pos[which_index(cpy_mobs->where)].y * cpy_mobs->speed;
            cpy_mobs->where += cpy_mobs->speed;
            cpy_mobs = cpy_mobs->next;
            sfClock_restart(all->anim->move);
        }
    }
}

void game(all_t *all)
{
    const int status[8] = {0, 0, 0, 1, 0, 0, 0, 0};

    if (all->manager == GAME) {
        escape_to_pause(all);
        set_button_status(all->button, status);
        time_game(all->game_info);
        sfSprite_setTextureRect(all->game_info->health,
            (sfIntRect){0, 295, 200, 45});
        sfText_setString(all->game_info->text_gold,
            all->game_info->buffer_gold);
        shooting(all);
        draw_game(all->init, all->game_info);
        tower_drag(all);
        moving_drawing_menu_tower(all);
        draw_mobs_tower(all);
        loop_move(all);
        draw_set_towers(all->init, &all->all_tower);
    }
}
