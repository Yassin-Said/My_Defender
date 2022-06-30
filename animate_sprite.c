/*
** EPITECH PROJECT, 2022
** defender
** File description:
** animate_sprite
*/

#include "include/my.h"
#include "include/global.h"
#include <stdlib.h>
#include <stdio.h>

float time_as_ms(sfClock *clock)
{
    return (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)));
}

animable_sprite_t create_knight_sprite(sfClock *clock)
{
    animable_sprite_t sprite = {0};

    sprite.sprite = sfSprite_create();
    sprite.tex = sfTexture_createFromFile("assets/enemy_knight.png", NULL);
    sfSprite_setTexture(sprite.sprite, sprite.tex, sfFalse);
    sprite.current_animation = 0;
    sprite.last_animation_time = time_as_ms(clock);
    sprite.animation_frame = 50;
    for (unsigned int i = 0; i < 9; i++) {
        sprite.rects[i] = KNIGHT_RECTS[i];
    }
    sfSprite_setTextureRect(sprite.sprite,
        sprite.rects[sprite.current_animation]);
    sprite.rects_count = 9;
    return (sprite);
}

animable_sprite_t create_shadow_sprite(sfClock *clock)
{
    animable_sprite_t sprite = {0};

    sprite.sprite = sfSprite_create();
    sprite.tex = sfTexture_createFromFile("assets/shadow_enemy.png", NULL);
    sfSprite_setTexture(sprite.sprite, sprite.tex, sfFalse);
    sprite.current_animation = 0;
    sprite.last_animation_time = time_as_ms(clock);
    sprite.animation_frame = 90;
    for (unsigned int i = 0; i < 10; i++) {
        sprite.rects[i] = SHADOW_RECTS[i];
    }
    sfSprite_setTextureRect(sprite.sprite,
        sprite.rects[sprite.current_animation]);
    sprite.rects_count = 10;
    return (sprite);
}

animable_sprite_t create_orc_sprite(sfClock *clock)
{
    animable_sprite_t sprite = {0};

    sprite.sprite = sfSprite_create();
    sprite.tex = sfTexture_createFromFile("assets/orc_sprite.png", NULL);
    sfSprite_setTexture(sprite.sprite, sprite.tex, sfFalse);
    sprite.current_animation = 0;
    sprite.last_animation_time = time_as_ms(clock);
    sprite.animation_frame = 150;
    for (unsigned int i = 0; i < 7; i++) {
        sprite.rects[i] = ORC_RECTS[i];
    }
    sfSprite_setTextureRect(sprite.sprite,
        sprite.rects[sprite.current_animation]);
    sprite.rects_count = 7;
    return (sprite);
}

void animate_sprite(animable_sprite_t *animable, sfClock *clock)
{
    const float current_time = time_as_ms(clock);

    if (current_time >=
        animable->last_animation_time + animable->animation_frame) {
        animable->last_animation_time = current_time;
        if (animable->current_animation == animable->rects_count) {
            animable->current_animation = 0;
        }
        sfSprite_setTextureRect(animable->sprite,
            animable->rects[animable->current_animation]);
        animable->current_animation++;
    }
}
