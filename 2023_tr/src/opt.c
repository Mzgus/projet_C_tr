/*
 * E89 Pedagogical & Technical Lab
 * project:     tr
 * created on:  2024-01-10 - 14:39 +0100
 * 1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
 * description: opt and len
 */

#include "../include/function.h"

unsigned int stu_strlen(const char *str)
{
    int count;

    count = 0;
    while (str[count] != '\0') {
        count = count + 1;
    }
    return count;
}

int has_opt(char *av, char str)
{
    int count2;

    count2 = 0;
    if (av[0] == '-') {
        while (av[count2] != '\0') {
            if (str == av[count2]) {
                return 0;
            }
            count2 = count2 + 1;
        }
        count2 = 0;
    }
    return 1;
}

char *has_not_opt(char **av, int ac)
{
    int count;

    count = 1;
    while (count < ac) {
        if (av[count][0] != '-') {
            return av[count];
        }
        count += 1;
    }
    return "";
}
