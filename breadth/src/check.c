/*
** check.c for Project-Master in /home/david/TEK_1/dante/astar/src/Astar
** 
** Made by Daoudou
** Login   <daoudou.yacouba@epitech.eu>
** 
** Started on  Sun May 14 21:13:49 2017 Daoudou
** Last update Sun May 14 22:12:36 2017 Daoudou
*/


#include "dante.h"

int	check_point(t_elem *tmp)
{
  t_elem	*save;
  int		x;

  x = 0;
  save = tmp;
  if (tmp->next[SECONDE] != NULL)
    {
      tmp = tmp->next[SECONDE];
      while (tmp != NULL)
	{
	  if (tmp->next[FIRST]->c == 'X')
	    x += 1;
	  tmp = tmp->next[SECONDE];
	}
    }
  if (x == 3 && save->c == 'o')
    save->c = '4';
  return (0);
}
