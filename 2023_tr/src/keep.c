/*
E89 Pedagogical & Technical Lab
project:     tr
created on:  2024-01-10 - 14:27 +0100
1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
description: keep
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/function.h"


char *keep_boucle(char *buffer, int i, char *to_keep, char *buff)
{
    int j;
    int index;
    int rep;

    index = 0;
    while (buffer[i] != '\0') {
        rep = 0;
        j = 0;
        while (to_keep[j] != '\0') {
            if (buffer[i] == to_keep[j]) {
                rep = 1;
            }
            j += 1;
        }
        if (rep == 1) {
            buff[index] = buffer[i];
            index += 1;
        }
        i += 1;
    }
    buff[index] = '\0';
    return buff;
}

char *tr_keep(char *buffer, char *to_keep)
{
    int i;
    char *buffprov;
    char *buff;

    i = 0;
    buffprov = malloc(sizeof (char) * 101);
    if (!buffprov) {
        return NULL;
    }
    buff = keep_boucle(buffer, i, to_keep, buffprov);
    return buff;
}

int write_keep_boucle(char **av, int ac, char *buffer, char *bufpv)
{
    char *newbuff;
    int size_read;
    int count;
    int lengh;

    size_read = read(0, buffer, 100);
    lengh = 0;
    while (size_read > 0) {
        count = 0;
        buffer[size_read] = '\0';
        newbuff = tr_keep(buffer, has_not_opt(av, ac));
        while (newbuff[count] != '\0') {
            bufpv[lengh] = newbuff[count];
            lengh += 1;
            count += 1;
        }
        free(newbuff);
        size_read = read(0, buffer, 100);
    }
    bufpv[lengh] = '\0';
    write(0, bufpv, lengh);
    free(buffer);
    free(bufpv);
    return 0;
}

int write_keep(char **av, int ac)
{
    char *buffer;
    char *buffprov;

    buffer = malloc(sizeof (char) * 101);
    if (!buffer) {
        return 1;
    }
    buffprov = malloc(sizeof (char) * 101);
    if (!buffprov) {
        return 1;
    }
    write_keep_boucle(av, ac, buffer, buffprov);
    return 0;
}
