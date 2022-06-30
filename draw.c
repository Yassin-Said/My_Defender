/*
** EPITECH PROJECT, 2022
** draw
** File description:
** defender
*/

#include "my.h"

void draw_mobs(window_t *init, main_t *anim, mobs_t **mobs)
{
    mobs_t *cpy_mobs = *mobs;

    while (cpy_mobs != NULL) {
        animate_sprite(&anim->anim_all[cpy_mobs->id], anim->clock);
        sfSprite_setPosition(anim->anim_all[cpy_mobs->id].sprite,
            cpy_mobs->pos);
        sfRenderWindow_drawSprite(init->window, cpy_mobs->sprite, NULL);
        cpy_mobs = cpy_mobs->next;
    }
}

void draw_set_towers(window_t *init, tower_t **all_towers)
{
    tower_t *all_towers_parse = *all_towers;

    while (all_towers_parse != NULL) {
        sfRenderWindow_drawSprite(init->window,
            all_towers_parse->sprite, NULL);
        all_towers_parse = all_towers_parse->next;
    }
}

void draw_game(window_t *init, game_t *game_info)
{
    sfIntRect life_bar[6] = {{0, 295, 200, 45}, {0, 236, 200, 45},
        {0, 177, 200, 45}, {0, 118, 200, 45}, {0, 59, 200, 45},
        {0, 0, 200, 45}};

    sfRenderWindow_drawSprite(init->window, game_info->back, NULL);
    sfRenderWindow_drawSprite(init->window, game_info->gold, NULL);
    sfSprite_setTextureRect(game_info->health, life_bar[game_info->pv]);
    sfRenderWindow_drawSprite(init->window, game_info->health, NULL);
    sfRenderWindow_drawText(init->window, game_info->text_gold, NULL);
    sfRenderWindow_drawText(init->window, game_info->text_minute, NULL);
    sfRenderWindow_drawText(init->window, game_info->text_seconde, NULL);
}

void draw_mobs_tower(all_t *all)
{
    for (int i = 0; i != 4; i++) {
        sfRenderWindow_drawText(all->init->window,
            all->tower[i].draw_price, NULL);
        sfRenderWindow_drawSprite(all->init->window,
            all->tower[i].sprite, NULL);
    }
    draw_mobs(all->init, all->anim, &all->mobs);
}
