/*
 * E89 Pedagogical & Technical Lab
 * project:     tr
 * created on:  2024-01-10 - 14:36 +0100
 * 1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
 * description: main tr
 */

#include <stdlib.h>
#include <stdio.h>
#include "../include/function.h"


int main(int ac, char **av)
{
    int count;
    int count2;

    count = 1;
    count2 = 1;
    while (count < ac) {
        if (has_opt(av[count], 'h') == 0) {
            helper(av);
            return 0;
        }
        if (main_loop(ac, av, count, count2) == 0) {
            return 0;
        }
        count += 1;
    }
    if (ac < 4 && stu_strlen(av[1]) == stu_strlen(av[2])) {
        tr_read(av);
        return 0;
    }
    return 1;
}
