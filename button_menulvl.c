/*
** EPITECH PROJECT, 2022
** button_handle
** File description:
** defender
*/

#include "my.h"
#include "array_details.h"

void display_button(button_t *button, window_t *init)
{
    for (int i = 0; i != 8; i++) {
        if (button[i].status != 1);
        else
            sfRenderWindow_drawSprite(init->window, button[i].sprite, NULL);
    }
}

void hoover_button(button_t *button, window_t *init)
{
    sfVector2f scale = {1.12, 1.12};
    sfVector2f scale2 = {1, 1};
    sfVector2i pos = sfMouse_getPositionRenderWindow(init->window);

    for (int i = 0; i != 8; i++) {
        if (pos.x >= button[i].pos.x && pos.x <= button[i].pos.x +
            button[i].rect.width && pos.y >= button[i].pos.y && pos.y
            <= button[i].pos.y + button[i].rect.height) {
            sfSprite_setScale(button[i].sprite, scale);
        } else {
            sfSprite_setScale(button[i].sprite, scale2);
        }
    }
}

void set_menu_lvl(button_t *button)
{
    for (int i = 0; i != 8; i++) {
        button[i].pos = pos[i];
        button[i].status = status[i];
        button[i].link = path[i];
        button[i].sec_state = sfFalse;
        button[i].rect = all_rect[i];
        button[i].text = sfTexture_createFromFile(button[i].link, NULL);
        button[i].sprite = sfSprite_create();
        sfSprite_setPosition(button[i].sprite, button[i].pos);
        sfSprite_setTexture (button[i].sprite, button[i].text, sfTrue);
        sfSprite_setTextureRect(button[i].sprite, button[i].rect);
    }
}

button_t *set_button(void)
{
    button_t *button = malloc(sizeof(button_t) * 8);
    sfVector2f scale = {1.50, 1.45};
    sfTexture *text = sfTexture_createFromFile("assets/image_menu1.jpg", NULL);
    sfSprite *background = sfSprite_create();

    sfSprite_setTexture(background, text, sfTrue);
    sfSprite_setScale(background, scale);
    set_menu_lvl(button);
    button->back = background;
    return (button);
}

void set_button_status(button_t *buttons, const int *status)
{
    for (int i = 0; i != 8; i++) {
        buttons[i].status = status[i];
    }
}
