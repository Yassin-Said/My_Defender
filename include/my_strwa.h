/*
** EPITECH PROJECT, 2021
** defender
** File description:
** my.h
*/

#ifndef MY_STRWA_
    #define MY_STRWA_

char *clean_string(char *src);
char *my_strdup(char *src, char c);
char *my_strcpy(char *dest, char const *src, char c);
int count_word(char *str, char c);
char *my_str_c_dup(char *src, char c);
int my_token_strlen(char *str, char c);
char **my_str_to_array(char *str, char c);

#endif
