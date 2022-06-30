/*
** EPITECH PROJECT, 2022
** set_defender
** File description:
** defender
*/

#include "my.h"
#include <string.h>
#include "my_strwa.h"

mobs_t *update_mobs(mobs_t *mobs, main_t *anim)
{
    char *str = fs_read("map.txt");
    char **all_mobs = NULL;

    if (mobs == NULL) {
        all_mobs = my_str_to_array(str, ' ');
        mobs = set_mobs(all_mobs, anim);
    }
    return (mobs);
}

void set_ath(game_t *game)
{
    sfVector2f scale = {2.75, 2};
    sfVector2f scale_gold = {0.09, 0.09};
    sfTexture *text = sfTexture_createFromFile("assets/grass1.png", NULL);
    sfTexture *text_gold = sfTexture_createFromFile("assets/gold.png", NULL);
    sfTexture *text_life = sfTexture_createFromFile("assets/life.png", NULL);
    sfTexture *pause_text =
        sfTexture_createFromFile("assets/menu_p.png", NULL);

    game->gold = sfSprite_create();
    game->health = sfSprite_create();
    game->back = sfSprite_create();
    game->menu_pause = sfSprite_create();
    sfSprite_setTexture(game->menu_pause, pause_text, sfTrue);
    sfSprite_setTexture(game->gold, text_gold, sfTrue);
    sfSprite_setTexture(game->health, text_life, sfTrue);
    sfSprite_scale(game->gold, scale_gold);
    sfSprite_setPosition(game->gold, (sfVector2f){1250, 6});
    sfSprite_setPosition(game->health, (sfVector2f){700, 6});
    sfSprite_setTexture(game->back, text, sfTrue);
    sfSprite_scale(game->back, scale);
}

game_t *set_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfTexture *text = sfTexture_createFromFile("assets/tuto.png", NULL);
    sfTexture *text2 = sfTexture_createFromFile("assets/over.png", NULL);

    game->tuto = sfSprite_create();
    sfSprite_setTexture(game->tuto, text, sfTrue);
    game->game_over = sfSprite_create();
    sfSprite_setTexture(game->game_over, text2, sfTrue);
    game->pv = 0;
    game->game_music = sfMusic_createFromFile("assets/game_music.ogg");
    game->status_pause = 0;
    game->type_write = sfFont_createFromFile("./assets/police.ttf");
    set_gold_text(game);
    set_time_game(game);
    set_ath(game);
    return (game);
}

menu_t *set_menu(void)
{
    sfTexture * texture =
        sfTexture_createFromFile("assets/main_menu.png", NULL);
    menu_t *all_menu = malloc(sizeof(menu_t));
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/police.ttf");
    sfVector2f pos = {750, 500};

    sfText_setFont(text, font);
    sfText_setString(text, "Press Enter to play");
    sfText_setPosition(text, pos);
    all_menu->counting = 0;
    all_menu->back = sfSprite_create();
    sfSprite_setTexture(all_menu->back, texture, sfTrue);
    all_menu->play_btn = text;
    return (all_menu);
}
