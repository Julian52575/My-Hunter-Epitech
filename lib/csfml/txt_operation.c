/*
** EPITECH PROJECT, 2022
** txt op
** File description:
** deals with all the txt stuff
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int is_txt(void)
{
    int fd = open("frog.txt", O_RDONLY);
    return fd;
}
