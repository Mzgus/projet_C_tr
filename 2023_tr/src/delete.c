/*
 * E89 Pedagogical & Technical Lab
 * project:     tr
 * created on:  2024-01-10 - 14:31 +0100
 * 1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
 * description: delete
 */

#include <stdlib.h>
#include <unistd.h>
#include "../include/function.h"

char *supp_boucle(char *buffer, int i, char *supp, char *buff)
{
    int j;
    int index;
    int rep;

    index = 0;
    while (buffer[i] != '\0') {
        rep = 0;
        j = 0;
        while (supp[j] != '\0') {
            if (buffer[i] == supp[j]) {
                rep = 1;
            }
            j += 1;
        }
        if (rep == 0) {
            buff[index] = buffer[i];
            index += 1;
        }
        i += 1;
    }
    buff[index] = '\0';
    return buff;
}

char *tr_supp(char *buffer, char *supp)
{
    char *buffprov;
    char *buff;
    int i;

    i = 0;
    buffprov = malloc(sizeof (char) * 101);
    if (!buffprov) {
        return NULL;
    }
    buff = supp_boucle(buffer, i, supp, buffprov);
    return buff;
}

int tr_delete(char **av, int ac)
{
    char *buffer;
    char *newbuff;
    int size_read;

    buffer = malloc(sizeof (char) * 101);
    if (!buffer) {
        return 1;
    }
    size_read = read(0, buffer, 100);
    while (size_read > 0) {
        buffer[size_read] = '\0';
        newbuff = tr_supp(buffer, has_not_opt(av, ac));
        write(0, newbuff, stu_strlen(newbuff));
        size_read = read(0, buffer, 100);
        free(newbuff);
    }
    free(buffer);
    return 0;
}
