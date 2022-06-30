/*
** EPITECH PROJECT, 2022
** check_drag_tower
** File description:
** defender
*/

#include "my.h"

int check_drag(tower_t *towers)
{
    for (int i = 0; i != 4; i++) {
        if (towers[i].dragged == 1)
            return (1);
    }
    return (0);
}
