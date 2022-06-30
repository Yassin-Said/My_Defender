##
## EPITECH PROJECT, 2021
## B-MUL-100-RUN-1-1-myhunter-guillyann.ferrere
## File description:
## Makefile
##

SRC =	my_defender.c	\
		menu_level.c	\
		event_buttun.c	\
		game.c	\
		my_tablen.c	\
		my_getnbr.c	\
		fs_read.c	\
		my_strwa/clean_string.c \
		my_strwa/my_strdup.c \
		my_strwa/my_strwa.c \
		my_strwa/my_token_strlen.c \
		my_strwa/my_strcpy.c \
		free.c \
		set_states.c \
		handle_towers_mobs.c \
		animate_sprite.c \
		time_minutes.c \
		int_to_str.c \
		tower_man.c	\
		menu_tower.c \
		draw.c \
		pause_game.c \
		button_menulvl.c \
		button_pressed.c \
		memset.c \
		set_time_gold.c \
		window.c \
		shooting.c \
		free_all.c \
		end.c \
		tower_drag.c \
		my_absolue.c \
		check_tower_drag.c \
		set_all.c \
		usage.c

OBJ = $(SRC:.c=.o)

IFLAGS = -I./include

LFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

LIBS	=	-L/usr/lib/x86_64-linux-gnu -lm

CFLAGS = -Werror -Wall -Wextra -W $(IFLAGS) $(LFLAGS) -g3

NAME = my_defender

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)


clean:
	rm -f *#
	rm -f ~*
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
