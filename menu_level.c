/*
** EPITECH PROJECT, 2022
** my_defender.c
** File description:
** menu
*/

#include "my.h"
#include <math.h>

int tuto(button_t *buttons, window_t *init, manager_t *manager)
{
    (void)buttons;
    (void)init;

    *manager = TUTORIAL;
    return (0);
}

int quit(button_t *button, window_t *init, manager_t *manager)
{
    (void)manager;

    for (int i = 0; i != 8; i++) {
        if (button[i].sprite)
            sfSprite_destroy(button[i].sprite);
        if (button[i].text)
            sfTexture_destroy(button[i].text);
        init = close_window(init);
    }
    free(button);
    init = close_window(init);
    return (1);
}

int menu_lvl(button_t *buttons, window_t *init, manager_t *manager)
{
    const int status[8] = {1, 0, 0, 0, 1, 0, 0, 1};

    if (*manager == MENU_LEVEL) {
        set_button_status(buttons, status);
        sfRenderWindow_drawSprite(init->window, buttons->back, NULL);
    }
    return (1);
}

int game_tuto(all_t *all, manager_t *manager)
{
    const int status[8] = {0, 0, 0, 0, 0, 0, 1, 0};

    if (*manager == TUTORIAL) {
        set_button_status(all->button, status);
        sfRenderWindow_drawSprite(all->init->window,
            all->game_info->tuto, NULL);
    }
    return (1);
}
