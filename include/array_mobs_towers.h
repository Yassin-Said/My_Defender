/*
** EPITECH PROJECT, 2022
** array_mobs_towers
** File description:
** array_mobs_towers
*/

#ifndef defender
    #define defender

    #include "my.h"

static const int speed_mobs[3] = {6, 3, 2};

static const float relaod_time[4] = {0.4, 0.5, 1, 2};

static const int life_mobs[3] = {175, 350, 250};

static const sfIntRect all_rect_mobs[3] = {{0, 0, 120, 110}, {0, 0, 70, 70},
    {0, 0, 70, 70}};

static const sfVector2f pos_tower[4] = {{2040, 240}, {2200, 240},
    {2040, 430}, {2200, 380}};

static const char *path_tower[4] = {"assets/archer.png",
    "assets/mortier.png", "assets/slow.png", "assets/tp.png"};

static const int damage_tower[4] = {50, 100, 0, 0};

static const int range_tower[4] = {300, 400, 200, 200};

static const sfBool slowing_tower[4] = {0, 0, 1, 0};

static const sfBool tp_tower[4] = {0, 0, 0, 1};

static const int speed_shoot_tower[4] = {2, 5, 2, 0};

static const sfIntRect all_rect_tower[7] = {{0, 0, 80, 150}, {0, 0, 80, 130},
    {0, 0, 80, 130}, {0, 0, 80, 200}};

#endif
