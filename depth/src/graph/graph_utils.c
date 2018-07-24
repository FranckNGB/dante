/*
** graph_utils.c for Project-Master in /home/daoudou.yacouba/CPE_2016_Lemin/src/graph
** 
** Made by le magicien
** Login   <Daoudou Yacouba@epitech.eu>
** 
** Started on  Sun Apr 30 19:21:25 2017 le magicien
** Last update Sun Apr 30 20:41:59 2017 le magicien
*/

#include "lemin.h"

t_algo		*algo_ini()
{
  t_algo        *algo;

  if (!(algo = malloc(sizeof(*algo))))
    return (NULL);
  algo->star = NULL;
  algo->ends = NULL;
  algo->room = NULL;
  return (algo);
}

char		**take_mylist(t_elem *tmp)
{
  char          **tab;

  tab = my_str_to_wordtab(tmp->room_name, ' ');
  if (tmp->next[SECONDE] != NULL)
    {
      tmp = tmp->next[SECONDE];
      while (tmp)
	{
	  tab = realloc_tab(tab, tmp->room_name);
	  tmp = tmp->next[SECONDE];
	}
    }
  return (tab);
}
