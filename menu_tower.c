/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** menu_tower
*/

#include <stdlib.h>
#include "my.h"

menu_tower_t *menu_tower()
{
    char *path[3] = {"assets/menu_tower_pause_2.png", "assets/drag_right.png",
        "assets/drag_left.png"};
    sfVector2f all_pos[3] = {{1920, 200}, {1840, 300}, {1840, 300}};
    sfSprite **all_menu_asset = malloc(sizeof(sfSprite *) * 3);
    int displayed[3] = {0, -1, 1};
    menu_tower_t *tower_menu = malloc(sizeof(menu_tower_t));

    for (int i = 0; i < 3; i++) {
        all_menu_asset[i] = sfSprite_create();
        sfSprite_setPosition(all_menu_asset[i], all_pos[i]);
        sfSprite_setTexture(all_menu_asset[i],
            sfTexture_createFromFile(path[i], NULL), sfTrue);
        tower_menu->displayed[i] = displayed[i];
    }
    tower_menu->all_menu_asset = all_menu_asset;
    tower_menu->incr = -500;
    return (tower_menu);
}

void loop_cond_menu_tower(sfVector2f sprite_pos, all_t *all)
{
    for (int i = 0; i < 4; i++) {
        sprite_pos = sfSprite_getPosition(all->tower[i].sprite);
        sprite_pos.x += all->tower_menu->incr;
        sfSprite_setPosition(all->tower[i].sprite, sprite_pos);
        all->tower[i].pos.x = sprite_pos.x;
        all->tower[i].pos.y = sprite_pos.y;
        sprite_pos = sfText_getPosition(all->tower[i].draw_price);
        sfText_setPosition(all->tower[i].draw_price,
            (sfVector2f){sprite_pos.x + all->tower_menu->incr, sprite_pos.y});
    }
    for (int i = 0; i < 3; i++) {
        sprite_pos = sfSprite_getPosition(all->tower_menu->all_menu_asset[i]);
        sprite_pos.x += all->tower_menu->incr;
        sfSprite_setPosition(all->tower_menu->all_menu_asset[i], sprite_pos);
        all->tower_menu->displayed[i] *= -1;
    }
}

void loop_menu_tower(all_t *all, sfVector2f sprite_pos, sfVector2f pos_button,
    sfVector2i pos)
{
    int res = 0;

    for (int i = 0; i < 4 ; i++)
        res += all->tower[i].dragged;
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x >= pos_button.x &&
        pos.x <= pos_button.x + 80 && pos.y >= pos_button.y &&
        pos.y <= pos_button.y + 200 && res == 0) {
            loop_cond_menu_tower(sprite_pos, all);
            all->tower_menu->incr *= -1;
    }
}

void moving_drawing_menu_tower(all_t *all)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(all->init->window);
    sfVector2f pos_button;
    sfVector2f sprite_pos;

    for (int i = 0; i < 3; i++) {
        if (all->tower_menu->displayed[i] != -1) {
            sfRenderWindow_drawSprite(all->init->window,
                all->tower_menu->all_menu_asset[i], NULL);
            pos_button =
                sfSprite_getPosition(all->tower_menu->all_menu_asset[i]);
        }
    }
    loop_menu_tower(all, sprite_pos, pos_button, pos);
}
