/*
** my.h for Project-Master in /home/david/TEK_1/dante/david/astar/include
** 
** Made by Daoudou
** Login   <daoudou.yacouba@epitech.eu>
** 
** Started on  Sat May 13 02:19:49 2017 Daoudou
** Last update Sat May 13 03:08:00 2017 Daoudou
*/

#ifndef	MY_H_
# define MY_H_

# define ALLOC_1 4096
# define READ_SIZE 1

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_wordtab
{
  int		e;
  int		len;
  int		i;
  int		l;
  char		**tab;
}		t_wordtab;
typedef struct  s_struct
{
  char		character;
  int		index;
  int		bool;
}		t_struct;  

typedef struct	s_printf
{
  void		(*ptrfunc)(va_list);
  char		key;
}		t_printf;

/*
** T0_WORDTAB
*/

char		**my_str_to_wordtab(char *str, char c);
int		nb_line(char *str, char c);
int		strlen_word(char *str, char c, int i);
t_wordtab	init_value_struct();

/*
** GNL
*/

char		stock_and_recup_char(const int fd);
char		*get_next_line(const int fd);

/*
** FNC_STR
*/
void		free_tab(char **tab);
int		my_getnbr(char *str);
int		check_neg_for_getnbr(char *str);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
void		my_putchar(char c);
char		*my_strcpy(char *desk, char *src);
void		my_putstr(char *str);
int		my_strlen(char *str);
char		*my_strcat(char *str1, char *str2);
int		my_put_nbr(int nb);
int		my_put_nbr_base(int nb, char *base);
void		show_tab(char **);

#endif
