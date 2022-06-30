/*
** EPITECH PROJECT, 2022
** my_tablen
** File description:
** return lenght of an array
*/

#include <stdlib.h>

int tablen(char **tab)
{
    int i = 0;

    if (!tab)
        return -1;
    while (tab[i] != NULL) {
        i++;
    }
    return (i);
}
