/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-free-said.yassin
** File description:
** free.c
*/

#include "my.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}
