/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/Johanne-Franck/My Projects/Introd.toIA/dante/depth/lib
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Sat May 13 18:04:44 2017 Johanne-Franck NGBOKOLI
** Last update Sat May 13 18:48:44 2017 Johanne-Franck NGBOKOLI
*/

#include "my.h"

int	strlen_word(char *str, char c, int i)
{
  int	len;

  len = 0;
  while (str[i] && str[i] != c)
    {
      len += 1;
      i += 1;
    }
  return (len + 1);
}

int	nb_line(char *str, char c)
{
  int	len;
  int	i;

  i = 0;
  len = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c && str[i + 1] != c)
	len = len + 1;
      i = i + 1;
    }
  return (len + 1);
}

t_wordtab	init_value_struct()
{
  t_wordtab	ptr;

  ptr.e = 0;
  ptr.len = 0;
  ptr.i = 0;
  return (ptr);
}

char	**my_str_to_wordtab(char *str, char c)
{
  t_wordtab	ptr;

  ptr = init_value_struct();
  if (str != NULL)
    ptr.len = nb_line(str, c);
  if ((ptr.tab = malloc(sizeof(char *) * (ptr.len + 1))) == NULL)
    return (NULL);
  while (str[ptr.e] != '\0')
    {
      ptr.l = 0;
      if ((ptr.tab[ptr.i] = malloc(sizeof(char) *
	 (strlen_word(str, c, ptr.e) + 2))) == NULL)
	return (NULL);
      while (str[ptr.e] != '\0' && str[ptr.e] == c)
	ptr.e += 1;
      while (str[ptr.e] != '\0' && str[ptr.e] != c)
	ptr.tab[ptr.i][ptr.l++] = str[ptr.e++];
      ptr.tab[ptr.i][ptr.l] = 0;
      if (str[ptr.e] != 0)
	ptr.e += 1;
      ptr.i += 1;
    }
  ptr.tab[ptr.i] = NULL;
  return (ptr.tab);
}
