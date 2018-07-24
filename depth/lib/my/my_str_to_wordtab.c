/*
** my_str_to_wordtab.c for  in /home/matian_j/Delivery/PSU_FOLDER/PSU_2016_minishell1/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Mar 23 19:48:08 2017 John Doe
** Last update Tue May  9 20:11:42 2017 daoudou
*/

#include <stdlib.h>
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

char		**my_str_to_wordtab(char *str, char c)
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
