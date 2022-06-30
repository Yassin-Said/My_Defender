/*
** EPITECH PROJECT, 2022
** clean_string
** File description:
** clean_string_without_malloc
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my_strwa.h"

char *clean_string(char *src)
{
    char *tmp = NULL;
    int i = 0;
    int j = 0;

    if (src == NULL)
        return NULL;
    tmp = malloc(sizeof(char) * (my_token_strlen(src, '\0') + 1));
    while (src[i] == ' ' || src[i] == '\t')
        i++;
    for (; src[i] != '\0'; i++) {
        if ((src[i] == ' ' || src[i] == '\t') && (src[i + 1] == ' ' ||
                    src[i + 1] == '\t')) {
        } else {
            tmp[j] = src[i];
            j++;
        }
    }
    tmp[j - 1] = '\0';
    return tmp;
}
