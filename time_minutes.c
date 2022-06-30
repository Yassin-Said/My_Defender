/*
** EPITECH PROJECT, 2022
** time
** File description:
** defender
*/

#include "my.h"

float time_as_minute(float seconde)
{
    if (seconde == 0)
        return 0;
    else
        return (seconde / 60);
}

float time_as_sc(sfClock *clock)
{
    return (sfTime_asSeconds(sfClock_getElapsedTime(clock)));
}
