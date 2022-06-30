/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** event_buttun
*/

#include "my.h"
#include <stdio.h>

int go_menu(button_t *buttons, window_t *init, manager_t *manager)
{
    (void)buttons;
    (void)init;

    *manager = MENU;
    return (0);
}

int get_pause(button_t *buttons, window_t *init, manager_t *manager)
{
    (void)buttons;
    (void)init;

    *manager = PAUSE;
    return (0);
}

int play(button_t *buttons, window_t *init, manager_t *manager)
{
    (void)buttons;
    (void)init;

    *manager = GAME;
    return (0);
}

int go_menu_lvl(button_t *buttons, window_t *init, manager_t *manager)
{
    (void)buttons;
    (void)init;

    *manager = MENU_LEVEL;
    return (0);
}

int go_left(button_t *buttons, window_t *init, manager_t *manager)
{
    (void)buttons;
    (void)init;
    (void)manager;

    return (0);
}
