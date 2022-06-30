/*
** EPITECH PROJECT, 2022
** window
** File description:
** defender
*/

#include "my.h"

window_t *close_window(window_t *init)
{
    if (init->event.type == sfEvtClosed)
        sfRenderWindow_close(init->window);
    return (init);
}

window_t *init_window(window_t *init)
{
    init = malloc(sizeof(window_t));
    init->video_mod = (sfVideoMode){1920, 1080, 60};
    init->window = sfRenderWindow_create(init->video_mod,
        "my_defender", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(init->window, 60);
    return init;
}
