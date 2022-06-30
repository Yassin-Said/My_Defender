/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** free_all
*/

#include "my.h"

void free_ath(all_t *all)
{
    sfSprite_destroy(all->game_info->health);
    sfSprite_destroy(all->game_info->gold);
    sfSprite_destroy(all->game_info->menu_pause);
    sfSprite_destroy(all->game_info->back);
}

void erase_tower(tower_t *tower)
{
    sfSprite_destroy(tower->sprite);
    free(tower);
}

void free_li_list(mobs_t *mobs, tower_t *all_tower)
{
    mobs_t *mobs_next = mobs;
    tower_t *tower_next = all_tower;

    while (mobs != NULL) {
        mobs_next = mobs->next;
        erase_mob(mobs);
        mobs = mobs_next;
    }
    while (all_tower != NULL) {
        tower_next = all_tower->next;
        erase_tower(all_tower);
        all_tower = tower_next;
    }
}

void free_all(all_t *all)
{
    free_li_list(all->mobs, all->all_tower);
    free_ath(all);
    sfSoundBuffer_destroy(all->game_info->buffer_slap_sound);
    sfSoundBuffer_destroy(all->game_info->buffer_tower_sound);
    sfSound_destroy(all->game_info->slap_sound);
    sfSound_destroy(all->game_info->tower_sound);
    sfMusic_destroy(all->game_info->game_music);
    sfSprite_destroy(all->anim->anim_all[0].sprite);
    sfSprite_destroy(all->anim->anim_all[1].sprite);
    sfSprite_destroy(all->anim->anim_all[2].sprite);
    sfSprite_destroy(all->game_info->tuto);
    sfSprite_destroy(all->game_info->game_over);
}
