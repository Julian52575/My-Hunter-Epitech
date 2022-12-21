##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## it makes files
##

SRC = 	$(wildcard src/*/*/*/*.c src/*/*/*.c src/*/*.c src/*.c lib/*/*.c)

OBJ = $(SRC:.c=.o)

CFLAGS += -g3 -Wall -Wextra -I./lib/includes -L./lib/my -lmy

CSFlags += -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

NAME = "my_hunter"

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFlags) -g3

all:     $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
