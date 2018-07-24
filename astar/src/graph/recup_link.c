/*
** recup_link.c for lemin in /home/Matian_j/CPE_2016_Lemin
** 
** Made by jérémy Matian
** Login   <Matian_j@epitech.net>
** 
** Started on  Fri Apr 28 16:31:11 2017 jérémy Matian
** Last update Sun Apr 30 17:48:35 2017 le magicien
*/

#include "lemin.h"

char		**recup_cut_str_link(char *link)
{
  char		**link_name;

  link_name = my_str_to_wordtab(link, '-');
  return (link_name);
}

char	**stock_room_on_tab(t_parser *ptr)
{
  char	**tmp;
  char	**tab;
  char	**tmp_bis;
  int	i;

  i = 0;
  if (!(tab = malloc(sizeof(char *) * (2))))
    return (NULL);
  tab[0] = NULL;
  while (ptr->tmp[i] != NULL)
    {
      if (!(tmp = my_str_to_wordtab(ptr->tmp[i], ' ')))
	return (NULL);
      if (!(tmp_bis = my_str_to_wordtab(tmp[0], '\0')))
	return (NULL);
      if (!(tab = realloc_tab(tab, tmp_bis[0])))
	return (NULL);
      free_tab(tmp);
      free_tab(tmp_bis);
      i += 1;
    }
  return (tab);
}
