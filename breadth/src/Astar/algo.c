/*
** algo.c for Project-Master in /home/david/TEK_1/dante/astar/src/Astar
** 
** Made by Daoudou
** Login   <daoudou.yacouba@epitech.eu>
** 
** Started on  Sat May 13 20:17:06 2017 Daoudou
** Last update Sun May 14 21:16:39 2017 Johanne-Franck NGBOKOLI
*/

#include "dante.h"

int	algo_astar(t_list *list, int size)
{
  t_elem	*tmp;

  tmp = list->first;
  tmp->c = 'o';
  while (tmp != NULL)
    {
      look_neib(tmp, list, size);
      tmp = tmp->next[FIRST];
    }
  return (0);
}

int	look_neib(t_elem *tmp, t_list *list, int size)
{
  if (tmp->y == size -1)
    if (tmp->next[FIRST] == NULL)
      {
	delet(list);
	display_list(list, size);
	exit(0);
      }
  if (tmp->next[SECONDE] != NULL)
    {
      tmp = tmp->next[SECONDE];
      while (tmp != NULL)
	{
	  take_line(tmp, list, size);
	  tmp = tmp->next[SECONDE];
	}
    }
  return (0);
}

int	take_line(t_elem *tmp, t_list *list, int size)
{
  t_elem	*save;

  save = list->first;
  if (tmp->next[SECONDE] == NULL && tmp->next[FIRST]->c != '*')
    tmp = rewind_list(list, tmp->next[FIRST]->x,
	  tmp->next[FIRST]->y);
  if (tmp->next[FIRST]->c == '*' || tmp->next[FIRST]->c == 'o'
      || tmp->next[FIRST]->c == '4')
    while (save != NULL)
      {
	if (tmp->next[FIRST]->x == save->x &&
	    tmp->next[FIRST]->y == save->y &&
	    tmp->next[FIRST]->c == '*')
	  {
	    tmp->next[FIRST]->c = 'o';
	    if ((look_neib(save, list, size)) == 1)
	      return (1);
	  }
	save = save->next[FIRST];
      }
    else
    {
      tmp = tmp->next[SECONDE];
      take_line(tmp, list, size);
    }
  return (0);
}

int		check_rod(t_list *list, int x, int y)
{
  t_elem	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      if (tmp->x == x && tmp->y == y)
	{
	  if (tmp->next[SECONDE] != NULL)
	    {
	      while(tmp != NULL)
		{
		  if (tmp->next[FIRST]->c == '*')
		    return (0);
		  tmp = tmp->next[SECONDE];
		}
	      return (1);
	    }
	}
      tmp = tmp->next[FIRST];
    }
  return (1);
}

t_elem		*rewind_list(t_list *list, int x, int y)
{
  t_elem	*tmp;
  t_elem	*save;
  int		i;
  
  i = y;
  tmp = list->first;
  while (tmp != NULL)
    {
      if (tmp->x == x && tmp->y == y)
	if (tmp->next[SECONDE] != NULL)
	  {
	    save = tmp;
	    tmp = tmp->next[SECONDE];
	    while (tmp != NULL)
	      {
		if (tmp->next[FIRST]->c == '*')
	 	  return (save);
		tmp = tmp->next[SECONDE];
	      }
	    break ;
	  }
      tmp = tmp->next[FIRST];
    }
  save->c = '4';
  if (i == y)
    save->next[FIRST]->c = '4';
  y -= 1;
  rewind_list(list, x, y);
  return (save);
}
