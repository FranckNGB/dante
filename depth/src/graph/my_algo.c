/*
** my_algo.c for Project-Master in /home/daoudou.yacouba/CPE_2016_Lemin/src/graph
** 
** Made by le magicien
** Login   <Daoudou Yacouba@epitech.eu>
** 
** Started on  Sun Apr 30 07:49:34 2017 le magicien
** Last update Sun Apr 30 18:25:05 2017 jérémy Matian
*/

#include "lemin.h"

t_algo		*take_star_end(t_list *list, t_parser *ptr)
{
  t_algo	*algo;
  t_elem	*tmp;
  t_elem	*save;

  tmp = list->first;
  algo = algo_ini();
  while (tmp)
    {
      if ((my_strcmp(tmp->room_name, ptr->start[0])) == 0)
	{
	  save = tmp;
	  algo->star = take_mylist(tmp);
	  tmp = save;
	}
      if ((my_strcmp(tmp->room_name, ptr->end[0])) == 0)
	{
	  save = tmp;
	  algo->ends = take_mylist(tmp);
	  tmp = save;
	}
      tmp = tmp->next[FIRST];
    }
  return (algo);
}

int		check_room(t_list *list, t_algo *algo)
{
  t_elem	*tmp;
  int		ind;
  int		index;

  ind = 1;
  while (algo->star[ind] != NULL)
    {
      tmp = list->first;
      while (tmp)
	{
	  if ((my_strcmp(algo->star[0], tmp->room_name)) == 0)
	    index += 0;
	  else
	    {
	      if (tmp->next[1] != NULL)
		if ((check_val_ant(tmp, algo->star[ind], algo)) == 0)
		  return (0);
	    }
	  tmp = tmp->next[0];
	}
      ind += 1;
    }
  return (1);
}

int		check_val_ant(t_elem *tmp, char *tab, t_algo *algo)
{
  t_elem	*list;
  t_elem	*tmp1;

  list = tmp;
  while (tmp)
    {
      if ((algo->room = simple_room2(algo->star, algo->ends)) != NULL)
	return (0);
      if ((my_strcmp(tmp->room_name, tab)) == 0)
	{
	  algo->room = my_str_to_wordtab(tmp->room_name, ' ');
	  tmp1 = list;
	  while (tmp1)
	    {
	      if ((algo->room = take_room(tmp1->room_name, algo->ends,
		   my_str_to_wordtab(tab, ' '))) != NULL)
		return (0);
	      tmp1 = tmp1->next[1];
	    }
	}
      tmp = tmp->next[1];
    }
  return (1);
}

char	**take_room(char *str, char **tab, char **src)
{
  int	index;

  index = 0;
  while (tab[index] != NULL)
    {
      if ((my_strcmp(str, tab[index])) == 0)
	return (realloc_tab(src, tab[index]));
      index += 1;
    }
  free(src);
  return (NULL);
}

char	**simple_room2(char **tab, char **tab1)
{
  int	index;
  int	index1;

  index = 1;
  index1 = 1;
  while (tab[index] != NULL)
    {
      index1 = 0;
      while (tab1[index1] != NULL)
	{
	  if ((my_strcmp(tab[index], tab1[index1])) == 0)
	    return (my_str_to_wordtab(tab1[index1], ' '));
	  index1 += 1;
	}
      index += 1;
    }
  return (NULL);
}
