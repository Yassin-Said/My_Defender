/*
** EPITECH PROJECT, 2021
** defender
** File description:
** global.h
*/

#ifndef GLOBAL_H_
    #define GLOBAL_H_

    #include "my.h"

static const sfIntRect KNIGHT_RECTS[] = {
    (sfIntRect){0, 3, 80, 78},
    (sfIntRect){80, 3, 80, 78},
    (sfIntRect){160, 3, 80, 78},
    (sfIntRect){240, 3, 80, 78},
    (sfIntRect){320, 3, 80, 78},
    (sfIntRect){400, 3, 80, 78},
    (sfIntRect){480, 3, 80, 78},
    (sfIntRect){560, 3, 80, 78},
    (sfIntRect){640, 3, 80, 78}
};

static const sfIntRect ORC_RECTS[] = {
    (sfIntRect){0, 0, 103, 80},
    (sfIntRect){103, 0, 103, 80},
    (sfIntRect){206, 0, 103, 80},
    (sfIntRect){309, 0, 103, 80},
    (sfIntRect){412, 0, 103, 80},
    (sfIntRect){515, 0, 103, 80},
    (sfIntRect){618, 0, 103, 80},
    (sfIntRect){722, 0, 103, 80},
};

static const sfIntRect SHADOW_RECTS[] = {
    (sfIntRect){0, 0, 80, 87},
    (sfIntRect){80, 0, 80, 87},
    (sfIntRect){160, 0, 80, 87},
    (sfIntRect){240, 0, 80, 87},
    (sfIntRect){320, 0, 80, 87},
    (sfIntRect){400, 0, 80, 87},
    (sfIntRect){480, 0, 80, 87},
    (sfIntRect){560, 0, 80, 87},
    (sfIntRect){640, 0, 80, 87},
    (sfIntRect){720, 0, 80,87}
};

#endif
