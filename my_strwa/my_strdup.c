/*
** EPITECH PROJECT, 2021
** allocates memory copies string
** File description:
** task01
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my_strwa.h"

char *my_strdup(char *src, char c)
{
    char *str = NULL;

    if (src == NULL)
        return (NULL);
    str = malloc(sizeof(char) * (my_token_strlen(src, c) + 1));
    my_strcpy(str, src, c);
    return (str);
}
