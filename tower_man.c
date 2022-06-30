/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** tower management
*/

#include "my.h"

site_t *site(void)
{
    site_t *site_info = malloc(sizeof(site_t));
    sfVector2f size = {50, 50};
    sfVector2f origin = {25, 25};
    int status[5] = {0, 0, 0, 0, 0};
    sfRectangleShape **shape = malloc(sizeof(sfRectangleShape *) * 5);
    sfVector2f test[5] = {{225, 250}, {625, 420}, {955, 280},
        {675, 700}, {1295, 825}};

    for (int i = 0; i != 5; i++) {
        shape[i] = sfRectangleShape_create();
        sfRectangleShape_setOrigin(shape[i], origin);
        sfRectangleShape_setFillColor(shape[i], (sfColor){176, 224, 230, 100});
        sfRectangleShape_setSize(shape[i], size);
        sfRectangleShape_setPosition(shape[i], test[i]);
    }
    site_info->all_site = shape;
    site_info->pos = -1;
    for (int i = 0; i < 5; i++)
        site_info->status[i] = status[i];
    return (site_info);
}

int is_on(sfIntRect rect, sfSprite *sprite, window_t *init)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(init->window);

    if (m_pos.x >= pos.x && m_pos.x <= pos.x +\
        rect.width && m_pos.y >= pos.y && m_pos.y\
        <= pos.y + rect.height) {
        return (1);
    }
    return (0);
}

void next_tower_pos(tower_t towers, sfVector2f pos_base, window_t *init,
    sfVector2i new_pos)
{
    pos_base.x = new_pos.x - (towers.size.width) / 2;
    pos_base.y = new_pos.y - towers.size.height;
    sfSprite_setPosition(towers.sprite, pos_base);
    sfCircleShape_setPosition(towers.circle,\
    (sfVector2f){new_pos.x - (towers.range), new_pos.y -\
    (towers.range)});
    sfRenderWindow_drawCircleShape(init->window, towers.circle, NULL);
}

void cond_tower_pos(tower_t towers, window_t *init, sfVector2f site_pos)
{
    sfSprite_setPosition(towers.sprite, (sfVector2f){site_pos.x -
        towers.size.width / 2, site_pos.y - towers.size.height + 25});
    sfCircleShape_setPosition(towers.circle,
        (sfVector2f){site_pos.x - (towers.range), site_pos.y -
        (towers.range)});
    sfRenderWindow_drawCircleShape(init->window, towers.circle, NULL);
}

int tower_pos(tower_t towers, site_t **all_site, window_t *init,
    sfVector2i new_pos)
{
    sfVector2f pos_base = {0, 0};
    sfVector2i pos = sfMouse_getPositionRenderWindow(init->window);
    sfVector2f site_pos;

    for (int i = 0; i != 5; i++) {
        site_pos = sfRectangleShape_getPosition((*all_site)->all_site[i]);
        if ((my_abs(site_pos.x - pos.x) < 100) &&
            (my_abs(site_pos.y - pos.y) < 100) &&
            (*all_site)->status[i] != 1) {
            (*all_site)->pos = i;
            cond_tower_pos(towers, init, site_pos);
            return i;
        }
    }
    next_tower_pos(towers, pos_base, init, new_pos);
    return (-1);
}
