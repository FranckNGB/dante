/*
** dante.h for Project-Master in /home/david/TEK_1/dante/david/astar/include
** 
** Made by Daoudou
** Login   <daoudou.yacouba@epitech.eu>
** 
** Started on  Sat May 13 00:52:36 2017 Daoudou
** Last update Sun May 14 20:39:19 2017 Johanne-Franck NGBOKOLI
*/

#ifndef LEMIN_H_
# define LEMIN_H_

# define SUCCESS (0)
# define FAILURE (1)
# define CONVERT (48)
# define FIRST   (0)
# define SECONDE (1)
# define LAST    (2)

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h> 
# include <fcntl.h>
# include "link.h"
# include "my.h"
typedef struct		s_ptr
{
  int		x;
  int		y;
}			t_ptr;


int     tab_len(char *str, t_ptr *ptr);
char    *conver_tab(char **tab, t_ptr *ptr);
int     check_point(t_elem *tmp);

/*
**
*** Read file
**
*/

char	*read_map(char *str, t_ptr *ptr);

/*
**
*** realloc tab
**
*/

void    free_tab(char **tab);
char    **realloc_tab(char **envp, char *argv1);

/*
**
*** Algo
**
*/

int     algo_astar(t_list *list, int y);
int     look_neib(t_elem *tmp, t_list *list, int size);
int     take_line(t_elem *tmp, t_list *list, int size);

#endif /* LEMIN_H_ */
