/*
 * E89 Pedagogical & Technical Lab
 * project:     tr
 * created on:  2024-01-10 - 14:42 +0100
 * 1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
 * description: include function
 */

#ifndef FUNCTION_
#define FUNCTION_


unsigned int stu_strlen(const char *str);
int has_opt(char *av, char str);
char *has_not_opt(char **av, int ac);
int tr_remp(char *buffer, char *to_replace, char *substitutes);
char *supp_boucle(char *buffer, int i, char *supp, char *buff);
char *tr_supp(char *buffer, char *supp);
char *keep_boucle(char *buffer, int i, char *to_keep, char *buff);
char *tr_keep(char *buffer, char *to_keep);
int tr_delete(char **av, int ac);
int write_keep_boucle(char **av, int ac, char *buffer, char *bufpv);
int write_keep(char **av, int ac);
int tr_read(char **av);
void helper(char **av);
int main_loop(int ac, char **av, int count, int count2);


#endif
