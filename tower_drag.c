/*
** EPITECH PROJECT, 2022
** tower_drag
** File description:
** defender
*/

#include "my.h"

void cond_one(all_t *all, int i)
{
    if (all->tower[i].dragged == 0)
        all->tower[i].dragged = 1;
}

void cond_two(all_t *all, int i, int res)
{
    tower_t *new_tower;

    if (res != -1) {
        (all->all_site)->status[(all->all_site)->pos] = 1;
        new_tower = malloc(sizeof(tower_t));
        *new_tower = all->tower[i];
        new_tower->sprite = sfSprite_copy(all->tower[i].sprite);
        new_tower->next = all->all_tower;
        all->all_tower = new_tower;
        (all->all_site)->pos = -1;
        sfSound_play(all->game_info->tower_sound);
    }
}

void tower_drag_check(all_t *all, int res)
{
    for (int i = 0; i != 4; i++) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && is_on(all->tower[i].size,\
        all->tower[i].sprite, all->init) == 1 && check_drag(all->tower) == 0) {
            cond_one(all, i);
        }
        if (!sfMouse_isButtonPressed(sfMouseLeft) &&
            all->tower[i].dragged == 1) {
            cond_two(all, i, res);
            all->tower[i].dragged = 0;
        }
    }
}

void loop_tower_drag(all_t *all)
{
    for (int j = 0; j != 5; j++)
        sfRenderWindow_drawRectangleShape(all->init->window,
            all->all_site->all_site[j], NULL);
}

void tower_drag(all_t *all)
{
    sfVector2i new_pos = {0, 0};
    int res = 0;

    for (int i = 0; i != 4; i++) {
        if (all->tower[i].dragged == 1) {
            loop_tower_drag(all);
            new_pos = sfMouse_getPositionRenderWindow(all->init->window);
            res = tower_pos(all->tower[i], &all->all_site, all->init, new_pos);
        } else {
            sfSprite_setPosition(all->tower[i].sprite, all->tower[i].pos);
        }
    }
    tower_drag_check(all, res);
}
