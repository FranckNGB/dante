/*
** my_graph.c for Project-Master in /home/david/TEK_1/dante/david/astar/src/graph
** 
** Made by Daoudou
** Login   <daoudou.yacouba@epitech.eu>
** 
** Started on  Sat May 13 01:43:29 2017 Daoudou
** Last update Sun May 14 21:08:30 2017 Johanne-Franck NGBOKOLI
*/

#include "dante.h"

int		push_back(t_list *list, char c, int x, int y)
{
  t_elem        *new_node;
  t_elem        *tmp;

  if (!(new_node = create_elem()))
    return (FAILURE);
  tmp = list->first;
  new_node->c = c;
  new_node->x = x;
  new_node->y = y;
  if (tmp == NULL)
    list->first = new_node;
  else
    {
      while (tmp->next[FIRST] != NULL)
	tmp = tmp->next[FIRST];
      tmp->next[FIRST] = new_node;
    }
  return (SUCCESS);
}

int		put_bord(t_list *list)
{
  t_elem        *tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      put_connect(list, tmp, tmp->x, tmp->y);
      tmp = tmp->next[FIRST];
    }
  return (0);
}

int		add_node(t_elem *tmp, t_elem *node)
{
  t_elem        *new_node;

  if (!(new_node = create_bord()))
    return (FAILURE);
  new_node->next[FIRST] = node;
  if (tmp->next[SECONDE] == NULL)
    tmp->next[SECONDE] = new_node;
  else
    {
      while (tmp->next[SECONDE] != NULL)
	tmp = tmp->next[SECONDE];
      tmp->next[SECONDE] = new_node;
    }
  return (SUCCESS);
}

int		put_connect(t_list *list, t_elem *tmp, int x, int y)
{
  t_elem	*node;

  if ((node = find_node(list, y + 1, x)) != NULL && add_node(tmp, node))
    return (FAILURE);
  if ((node = find_node(list, y, x - 1)) != NULL && add_node(tmp, node))
    return (FAILURE);
  if ((node = find_node(list, y, x + 1)) != NULL && add_node(tmp, node))
      return (FAILURE);
  if ((node = find_node(list, y - 1, x)) != NULL && add_node(tmp, node))
    return (FAILURE);
  return (SUCCESS);
}

t_elem		*find_node(t_list *list, int y , int x)
{
  t_elem	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      if (tmp->x == x && tmp->y == y)
	return (tmp);
      tmp = tmp->next[FIRST];
    }
  return (NULL);
}
