/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** shooting mobs
*/

#include "my.h"

void shouting_condition(tower_t *cpy_tower, mobs_t *cpy_mobs)
{
    sfVector2f pos = sfSprite_getPosition(cpy_tower->sprite);
    pos.x += cpy_tower->size.width / 2;
    pos.y += cpy_tower->size.height - 25;

    if (my_abs(pos.x - cpy_mobs->pos.x) <= cpy_tower->range &&
        my_abs(pos.y - cpy_mobs->pos.y) <= cpy_tower->range &&
        time_as_sc(cpy_tower->time) > cpy_tower->reaload) {
        cpy_mobs->life -= cpy_tower->damage;
        if (cpy_tower->tp == 1 && cpy_mobs->tped == 0) {
            cpy_mobs->pos = (sfVector2f){0, 100};
            cpy_mobs->where = 0;
            cpy_mobs->tped = 1;
        }
        if (cpy_tower->slowing == 1 && cpy_mobs->speed > 1)
            cpy_mobs->speed -= 1;
        sfClock_restart(cpy_tower->time);
    }
}

void erase_mob(mobs_t *mob)
{
    free(mob);
}

void exited_mobs(all_t *all)
{
    mobs_t *cpy_mobs = all->mobs;

    while (cpy_mobs != NULL) {
        if (cpy_mobs->where > 3900) {
            sfSound_play(all->game_info->slap_sound);
            all->game_info->pv++;
        }
        cpy_mobs = cpy_mobs->next;
    }
}

void stop_condition(mobs_t *cpy_mobs, mobs_t *cpy_mobs_next, all_t *all)
{
    while (cpy_mobs && cpy_mobs_next != NULL) {
        if (cpy_mobs_next->life <= 0 || cpy_mobs_next->where > 3900) {
            cpy_mobs_next = cpy_mobs->next->next;
            cpy_mobs->next = cpy_mobs_next;
        } else {
            cpy_mobs_next = cpy_mobs_next->next;
            cpy_mobs = cpy_mobs->next;
        }
    }
    if (all->mobs->life <= 0 || all->mobs->where > 3900) {
        all->mobs = all->mobs->next;
    }
}

void shooting(all_t *all)
{
    tower_t *cpy_tower = all->all_tower;
    mobs_t *cpy_mobs = all->mobs;
    mobs_t *cpy_mobs_next = all->mobs->next;

    exited_mobs(all);
    while (cpy_tower != NULL) {
        while (cpy_mobs != NULL) {
            shouting_condition(cpy_tower, cpy_mobs);
            cpy_mobs = cpy_mobs->next;
        }
        cpy_mobs = all->mobs;
        cpy_tower = cpy_tower->next;
    }
    cpy_mobs = all->mobs;
    stop_condition(cpy_mobs, cpy_mobs_next, all);
}
