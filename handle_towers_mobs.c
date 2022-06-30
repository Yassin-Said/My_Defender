/*
** EPITECH PROJECT, 2022
** init_towers_mobs
** File description:
** defender
*/

#include "my.h"
#include "my_strwa.h"
#include "array_mobs_towers.h"

void set_circle(tower_t *tower_types, int range, int i)
{
    sfVector2f pos = {0, 0};
    sfColor color = {0, 0, 0, 0};
    sfColor color2 = {200, 200, 200, 100};
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, range);
    sfCircleShape_setOutlineThickness(circle, 2);
    sfCircleShape_setOutlineColor(circle, color2);
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setPosition(circle, pos);
    tower_types[i].circle = circle;
}

void loop_set_tower(tower_t *tower_types, int i)
{
    tower_types[i].time = sfClock_create();
    tower_types[i].reaload = relaod_time[i];
    tower_types[i].sprite = sfSprite_create();
    tower_types[i].text = sfTexture_createFromFile(path_tower[i], NULL);
    tower_types[i].damage = damage_tower[i];
    tower_types[i].lvl = 1;
    tower_types[i].size = all_rect_tower[i];
    tower_types[i].dragged = 0;
    tower_types[i].pos = pos_tower[i];
    tower_types[i].range = range_tower[i];
    tower_types[i].speed_shoot = speed_shoot_tower[i];
    set_circle(tower_types, range_tower[i], i);
    tower_types[i].slowing = slowing_tower[i];
    tower_types[i].tp = tp_tower[i];
    sfSprite_setTexture(tower_types[i].sprite,
    tower_types[i].text, sfTrue);
}

tower_t *set_tower()
{
    tower_t *tower_types = malloc(sizeof(tower_t) * 4);

    for (int i = 0; i != 4; i++) {
        loop_set_tower(tower_types, i);
        sfSprite_setTextureRect(tower_types[i].sprite, all_rect_tower[i]);
        sfSprite_setPosition(tower_types[i].sprite, tower_types[i].pos);
    }
    return (tower_types);
}

void loop_set_mobs(mobs_t *mobs, int diff, main_t *anim, int id)
{
    mobs->life = life_mobs[id];
    mobs->mobs_life = mobs->life;
    mobs->pos.x = diff;
    mobs->pos.y = 100;
    mobs->speed = speed_mobs[id];
    mobs->tped = 0;
    mobs->id = id;
    mobs->where = diff;
    sfSprite_setPosition(anim->anim_all[id].sprite, mobs->pos);
}

mobs_t *set_mobs(char **tab, main_t *anim)
{
    int i = 0;
    int diff = -100;
    int id = 0;
    mobs_t *memo = NULL;
    mobs_t *mobs = NULL;

    anim->anim_all = malloc(sizeof(animable_sprite_t) * 3);
    anim->anim_all[0] = create_knight_sprite(anim->clock);
    anim->anim_all[1] = create_shadow_sprite(anim->clock);
    anim->anim_all[2] = create_orc_sprite(anim->clock);
    for (; tab[i] != NULL; i++) {
        mobs = malloc(sizeof(mobs_t));
        id = my_getnbr(tab[i]);
        mobs->sprite = anim->anim_all[id].sprite;
        loop_set_mobs(mobs, diff, anim, id);
        diff -= 200;
        mobs->next = memo;
        memo = mobs;
    }
    return (mobs);
}
