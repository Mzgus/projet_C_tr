/*
 * E89 Pedagogical & Technical Lab
 * project:     tr
 * created on:  2024-01-10 - 14:33 +0100
 * 1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
 * description: helper
 */

#include <unistd.h>
#include "../include/function.h"


void helper(char **av)
{
    char *text;

    text = " [OPTION]... STRING1 [STRING2]\n"
        "Translate, squeeze, and/or delete characters"
        "from standard input,\n"
        "writing to standard output.  STRING1 and STRING2"
        "specify arrays of\n"
        "characters ARRAY1 and ARRAY2 that control the action.\n"
        "\n"
        "-c, -C, --complement    use the complement of ARRAY1\n"
        "-d, --delete            delete characters in ARRAY1,"
        "do not translate\n\0";
    write(1, "Usage: ", 7);
    write(1, av[0], stu_strlen(av[0]));
    write(1, text, stu_strlen(text));
}
