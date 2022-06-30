/*
** EPITECH PROJECT, 2021
** write copies string
** File description:
** task01
*/

char *my_strcpy(char *dest, char const *src, char c)
{
    int i = 0;

    while ((src[i] != '\0') && (src[i] != c)) {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
