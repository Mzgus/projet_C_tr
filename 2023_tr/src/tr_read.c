/*
 * E89 Pedagogical & Technical Lab
 * project:     tr
 * created on:  2023-12-15 - 12:02 +0100
 * 1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
 * description: read standar
 */

#include <unistd.h>
#include <stdlib.h>
#include "../include/function.h"


int tr_remp(char *buffer, char *to_replace, char *substitutes)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (buffer[i] != '\0') {
        while (to_replace[j] != '\0') {
            if (buffer[i] == to_replace[j]) {
                buffer[i] = substitutes[j];
            }
            j += 1;
        }
        j = 0;
        i += 1;
    }
    return 0;
}


int tr_read(char **av)
{
    char *buffer;
    int size_read;

    buffer = malloc(sizeof (char) * 101);
    if (!buffer) {
        return 1;
    }
    size_read = read(0, buffer, 100);
    while (size_read > 0) {
        buffer[size_read] = '\0';
        tr_remp(buffer, av[1], av[2]);
        write(0, buffer, size_read);
        size_read = read(0, buffer, 100);
    }
    free(buffer);
    return 0;
}

int main_loop(int ac, char **av, int count, int count2)
{
    if (has_opt(av[count], 'd') == 0 && ac >= 3 && ac <= 4) {
        while (count2 < ac) {
            if (has_opt(av[count2], 'c') == 0 &&
                ac >= 3 && ac <= 4 ) {
                write_keep(av, ac);
                return 0;
            }
            count2 += 1;
        }
        tr_delete(av, ac);
        return 0;
    }
    return 1;
}
