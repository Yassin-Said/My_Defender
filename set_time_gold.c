/*
** EPITECH PROJECT, 2022
** set_time_gold
** File description:
** defender
*/

#include "my.h"

void set_price_text(tower_t *tower_types)
{
    sfFont *font = sfFont_createFromFile("assets/police.ttf");
    const int price[4] = {100, 180, 50, 200};
    char buffer[3];
    sfVector2f pos[4] = {{2060, 390}, {2220, 390}, {2070, 580}, {2220, 580}};

    for (int i = 0; i < 4; i++) {
        tower_types[i].draw_price = sfText_create();
        sfText_setColor(tower_types[i].draw_price, sfBlack);
        sfText_setFont(tower_types[i].draw_price, font);
        sfText_setString(tower_types[i].draw_price,
            int_to_str(price[i], buffer));
        sfText_setPosition(tower_types[i].draw_price, pos[i]);
        tower_types[i].price = price[i];
    }
}

void set_time_game(game_t *game)
{
    game->minute = 0;
    game->seconde = 0;
    correct_malloc(game->buffer_seconde, 3);
    correct_malloc(game->buffer_minute, 5);
    game->time = sfClock_create();
    game->text_seconde = sfText_create();
    game->text_minute = sfText_create();
    sfText_setScale(game->text_minute, (sfVector2f){2, 2});
    sfText_setFont(game->text_minute, game->type_write);
    sfText_setColor(game->text_minute, sfBlack);
    sfText_setPosition(game->text_minute, (sfVector2f){50, 920});
    sfText_setScale(game->text_seconde, (sfVector2f){2, 2});
    sfText_setFont(game->text_seconde, game->type_write);
    sfText_setColor(game->text_seconde, sfBlack);
    sfText_setPosition(game->text_seconde, (sfVector2f){130, 920});
}

void set_gold_text(game_t *game)
{
    game->gold_nb = 0;
    game->text_gold = sfText_create();
    correct_malloc(game->buffer_gold, 5);
    sfText_setScale(game->text_gold, (sfVector2f){2, 2});
    sfText_setFont(game->text_gold, game->type_write);
    sfText_setColor(game->text_gold, sfBlack);
    sfText_setPosition(game->text_gold, (sfVector2f){1350, -13});
}
