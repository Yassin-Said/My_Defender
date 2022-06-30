/*
** EPITECH PROJECT, 2022
** button_pressed
** File description:
** defender
*/

#include "my.h"

void first_state(all_t *all, int i, sfVector2i mouse_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && mouse_pos.x >=
        all->button[i].pos.x && mouse_pos.y >= all->button[i].pos.y &&
        mouse_pos.x <= all->button[i].pos.x + all->button[i].rect.width &&
        mouse_pos.y <= all->button[i].pos.y + all->button[i].rect.height) {
        all->button[i].sec_state = sfTrue;
        sfSprite_setColor(all->button[i].sprite,
            sfColor_fromRGBA(255, 255, 10, 250));
    }
}

int other_state(all_t *all, int i, sfVector2i mouse_pos)
{
    int res = 0;
    event_button_t evt_button[] = {{&tuto}, {&quit}, {&go_menu_lvl},
        {&get_pause}, {&play}, {&go_menu_lvl}, {&go_menu_lvl}, {&quit}};

    if (!sfMouse_isButtonPressed(sfMouseLeft) && all->button[i].sec_state ==
        sfTrue && mouse_pos.x >= all->button[i].pos.x && mouse_pos.y >=
        all->button[i].pos.y && mouse_pos.x <= all->button[i].pos.x +
        all->button[i].rect.width && mouse_pos.y <= all->button[i].pos.y +
        all->button[i].rect.height) {
        sfSprite_setColor(all->button[i].sprite, sfColor_fromRGBA(255, 255,
            255, 255));
        res = evt_button[i].fonct(all->button, all->init, &all->manager);
    } else if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setColor(all->button[i].sprite, sfColor_fromRGBA(255, 255,
            255, 255));
        all->button[i].sec_state = sfFalse;
    }
    if (res == 1)
        return (1);
    return (0);
}

int pressed_button(all_t *all)
{
    int res = 0;
    int i = 0;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->init->window);

    for (; i != 8; i++) {
        if (all->button[i].status == 1) {
            first_state(all, i, mouse_pos);
            res = other_state(all, i, mouse_pos);
        }
        if (res == 1)
            return (1);
    }
    return (0);
}
