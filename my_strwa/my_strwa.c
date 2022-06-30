/*
** EPITECH PROJECT, 2022
** my_strwa
** File description:
** my_strwa
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_strwa.h"

int count_word(char *str, char c)
{
    int count = 0;

    if (str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}

char *my_str_c_dup(char *src, char c)
{
    char *str = NULL;

    if (src == NULL)
        return (NULL);
    str = malloc(sizeof(char) * (my_token_strlen(src, c) + 1));
    my_strcpy(str, src, c);
    return (str);
}

char **my_str_to_array(char *str, char c)
{
    int array_size = (count_word(str, c) + 1);
    char **array = NULL;
    int col = 0;
    int i = 0;

    array = malloc(sizeof(char *) * (array_size + 1));
    if (array == NULL)
        return NULL;
    for (; i < array_size; i++) {
        for (int j = 0; str[j] == c; str++);
        array[i] = my_str_c_dup(str, c);
        str += (my_token_strlen(str, c));
        col++;
    }
    array[i] = NULL;
    return (array);
}
