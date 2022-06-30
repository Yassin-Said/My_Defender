/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** defender_game
*/

#include "my.h"
#include "my_strwa.h"

void change_color(menu_t *menu, sfColor *color)
{
    if (menu->counting == 0) {
        if (color->b > 0) {
            color->b -= 5;
            color->g -= 5;
        } else  {
            menu->counting++;
        }
    }
    if (menu->counting == 1) {
        if (color->b < 255) {
            color->b += 5;
            color->g += 5;
        } else {
            menu->counting--;
        }
    }
}

void menu(menu_t *menu, manager_t *manager, window_t *init, button_t *button)
{
    const int status[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    sfColor color = sfText_getFillColor(menu->play_btn);

    if (*manager == MENU) {
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            *manager = MENU_LEVEL;
            return;
        }
        set_button_status(button, status);
        sfRenderWindow_clear(init->window, sfBlack);
        sfRenderWindow_drawSprite(init->window, menu->back, NULL);
        change_color(menu, &color);
        sfText_setFillColor(menu->play_btn, color);
        sfRenderWindow_drawText(init->window, menu->play_btn, NULL);
    }
}

void loop_defender_cond_over(all_t *all)
{
    if ((all->game_info->pv >= 6)) {
        all->manager = GAME_OVER;
        end(all);
    }
    pause_game(all);
    game(all);
    menu(all->all_menu, &all->manager, all->init, all->button);
    menu_lvl(all->button, all->init, &all->manager);
    game_tuto(all, &all->manager);
    display_button(all->button, all->init);
    hoover_button(all->button, all->init);
}

int my_defender(void)
{
    all_t *all = set_all();

    while (sfRenderWindow_isOpen(all->init->window)) {
        while (sfRenderWindow_pollEvent(all->init->window, &all->init->event))
            all->init = close_window(all->init);
        if ((all->mobs = update_mobs(all->mobs, all->anim)) == NULL)
            all->manager = WIN;
        sfRenderWindow_clear(all->init->window, sfBlack);
        loop_defender_cond_over(all);
        if (pressed_button(all) == 1) {
            free_all(all);
            return (0);
        }
        sfRenderWindow_display(all->init->window);
    }
    free_all(all);
    return 0;
}

int main(int ac, char **av)
{
    (void)av;
    (void)ac;

    if ((av[1] != NULL) && (av[1][0] == '-') && (av[1][1] == 'h') &&
        (av[1][2] == '\0') && (ac < 3)) {
        description();
        return (0);
    } else if ((ac != 1)) {
        description();
        return (84);
    }
    return (my_defender());
}
