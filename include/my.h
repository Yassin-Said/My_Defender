/*
** EPITECH PROJECT, 2021
** defender
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include "struct.h"

mobs_t *update_mobs(mobs_t *mobs, main_t *anim);
mobs_t *set_mobs(char **tab, main_t *anim);
tower_t *set_tower(void);
game_t *set_game(void);
menu_t *set_menu(void);
void set_price_text(tower_t *tower_types);
button_t *set_button(void);
void shooting(all_t *all);
int tablen(char **tab);
int my_getnbr(char *str);
void display_button(button_t *button, window_t *init);
void hoover_button(button_t *button, window_t *init);
int menu_lvl(button_t *button, window_t *init, manager_t *manager);
window_t *close_window(window_t *init);
int go_menu(button_t *buttons, window_t *init, manager_t *manager);
int get_pause(button_t *buttons, window_t *init, manager_t *manager);
int play(button_t *buttons, window_t *init, manager_t *manager);
int go_left(button_t *buttons, window_t *init, manager_t *manager);
void game(all_t *all);
void tower_drag(all_t *all);
int pressed_button(all_t *all);
void set_button_status(button_t *buttons, const int *status);
site_t *site(void);
char *fs_read(char const *filepath);
void free_tab(char **tab);
int my_strlen(char *str);
void moving_drawing_menu_tower(all_t *all);
animable_sprite_t create_knight_sprite(sfClock *clock);
animable_sprite_t create_shadow_sprite(sfClock *clock);
animable_sprite_t create_orc_sprite(sfClock *clock);
void animate_sprite(animable_sprite_t *animable, sfClock *clock);
menu_tower_t *menu_tower(void);
float time_as_sc(sfClock *clock);
float time_as_minute(float seconde);
void time_game(game_t *game_info);
char *int_to_str(int nb, char *score);
char *correct_malloc(char *str, int size);
int go_menu_lvl(button_t *buttons, window_t *init, manager_t *manager);
void pause_game(all_t *all);
void draw_game(window_t *init, game_t *game_info);
void draw_set_towers(window_t *init, tower_t **all_towers);
int game_tuto(all_t *all, manager_t *manager);
void draw_mobs(window_t *init, main_t *anim, mobs_t **mobs);
void draw_mobs_tower(all_t *all);
int tuto(button_t *buttons, window_t *init, manager_t *manager);
void loop_move(all_t *all);
void escape_to_pause(all_t *all);
int quit(button_t *button, window_t *init, manager_t *manager);
void set_gold_text(game_t *game);
void set_time_game(game_t *game);
void set_price_text(tower_t *tower_types);
float my_abs(float nb);
window_t *close_window(window_t *init);
window_t *init_window(window_t *init);
void free_li_list(mobs_t *mobs, tower_t *all_tower);
void erase_mob(mobs_t *mob);
void free_all(all_t *all);
void end(all_t *all);
int tower_pos(tower_t towers, site_t **all_site, window_t *init,
    sfVector2i new_pos);
int is_on(sfIntRect rect, sfSprite *sprite, window_t *init);
int check_drag(tower_t *towers);
all_t *set_all(void);
void description(void);

#endif
