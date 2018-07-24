/*
** my.h for Project-Master in /home/david/TEK_1/dante/franck/header
** 
** Made by Daoudou
** Login   <daoudou.yacouba@epitech.eu>
** 
** Started on  Wed May 10 05:19:13 2017 Daoudou
** Last update Sun May 14 19:27:59 2017 Johanne-Franck NGBOKOLI
*/

#ifndef	MY_H_
# define MY_H_

# include <stdlib.h>
# include <unistd.h>

typedef struct s_wordtab
{
  int	e;
  int	len;
  int	i;
  int	l;
  char	**tab;
}	t_wordtab;

int		strlen_tab(char **tab);
void		my_putstr(char *str);
void		my_putchar(char c);
int		my_strlen(char *str);
char		*my_strcpy(char *, char *);
int		my_strcmp(char *, char *);
int		my_getnbr(char *str);
char		**my_str_to_wordtab(char *str, char c);
char		*get_next_line(const int fd);

#endif /* !MY_H */
