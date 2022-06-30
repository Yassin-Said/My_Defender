/*
** EPITECH PROJECT, 2022
** array_details
** File description:
** defender
*/

#ifndef ARRAY_DETAILS_H_
    #define ARRAY_DETAILS_H_

    #include "my.h"

static const sfVector2f pos[8] = {{1800, 15}, {700, 430}, {1050, 420},
    {1800, 15}, {875, 420}, {1750, 500}, {20, 20}, {20, 20}};

static char *path[8] = {"assets/menu_button.png", "assets/menu_button2.png",
    "assets/menu_button2.png", "assets/pause.png", "assets/play.png",
    "assets/right_left.png", "assets/right_left.png",
    "assets/menu_button.png"};

static const sfIntRect all_rect[8] = {{0, 0, 70, 70}, {0, 140, 154, 140},
    {140, 0, 154, 140}, {0, 60, 70, 70}, {0, 0, 154, 140}, {0, 0, 70, 70},
    {0, 70, 70, 70}, {0, 70, 70, 70}};

static const int status[8] = {0, 0, 0, 0, 0, 0, 0, 0};

#endif
