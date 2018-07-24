/*
** my_pc_graph.c for Project-Master in /home/david/TEK_1/dante/david/astar/src/graph
** 
** Made by Daoudou
** Login   <daoudou.yacouba@epitech.eu>
** 
** Started on  Sat May 13 01:43:42 2017 Daoudou
** Last update Sun May 14 21:11:06 2017 Johanne-Franck NGBOKOLI
*/

#include "dante.h"

int	list_put(t_list *list, char *str)
{
  int	index;
  int	x;
  int	y;

  x = 0;
  y = 0;
  index = 0;
  while (str[index] != '\0')
    {
      if (str[index] == '\n')
	 {
	   x += 1;
	   y = 0;
	   index += 1;
	 }
      push_back(list, str[index], x, y);
      y += 1;
      index += 1;
    }
  return (SUCCESS);
}

t_elem		*create_elem()
{
  t_elem        *new_elem;

  if (!(new_elem = malloc(sizeof(*new_elem))))
    return (NULL);
  if (!(new_elem->next = malloc(sizeof(*new_elem->next) * (2 + 1))))
    return (NULL);
  new_elem->x = 0;
  new_elem->y = 0;
  new_elem->c = 0;
  new_elem->next[FIRST] = NULL;
  new_elem->next[SECONDE] = NULL;
  new_elem->next[LAST] = NULL;
  return (new_elem);
}

t_elem		*create_bord()
{
  t_elem        *new_elem;

  if (!(new_elem = malloc(sizeof(*new_elem))))
    return (NULL);
  if (!(new_elem->next = malloc(sizeof(*new_elem->next) * (2))))
    return (NULL);
  new_elem->c = 0;
  new_elem->x = 0;
  new_elem->y = 0;
  new_elem->next[FIRST] = NULL;
  new_elem->next[SECONDE] = NULL;
  return (new_elem);
}

t_list		*create_list()
{
  t_list	*list;

  if (!(list = malloc(sizeof(*list))))
    return (NULL);
  list->length = 0;
  list->first = NULL;
  return (list);
}

void		display_list(t_list *list, int y)
{
  t_elem	*tmp;
  int		a;

  a = 0;
  y -= 1;
  tmp = list->first;
  while (tmp)
    {
      my_putchar(tmp->c);
      if (a == y)
      	{
	  if (tmp->next[FIRST] != NULL)
	    my_putchar('\n');
      	  a = 0;
      	}
      else
      	a += 1;
      tmp = tmp->next[FIRST];
    }
}
