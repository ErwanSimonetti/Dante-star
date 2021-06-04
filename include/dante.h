/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-martin.blancho
** File description:
** dante
*/

#ifndef DANTE_H_
#define DANTE_H_

int my_putstr(char const *str);
int my_getnbr(char const *str);
long long get_lglg(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
char *my_revstr(char *str);
int print_error_msg(char const *str);
void put_error_char(char c);
char *open_and_read(char const *str);
char **str_to_array(char *str);

#endif /* !DANTE_H_ */
