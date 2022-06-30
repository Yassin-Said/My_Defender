/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-said.yassin
** File description:
** fs_read
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char *fs_read(char const *filepath)
{
    int fd = 0;
    char *str;
    struct stat file_stat;

    if (stat(filepath, &file_stat) == -1)
        return NULL;
    str = malloc(sizeof(char) * (file_stat.st_size + 2));
    fd = open(filepath, O_RDONLY);
    if (fd == -1 || str == NULL)
        return NULL;
    if (read(fd, str, file_stat.st_size) == -1) {
        close(fd);
        free(str);
        return NULL;
    }
    str[file_stat.st_size] = '\0';
    close(fd);
    return (str);
}
