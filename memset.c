/*
** EPITECH PROJECT, 2022
** memset
** File description:
** defender
*/

char *correct_malloc(char *str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}
