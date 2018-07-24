/*
** function2.c for function2 in /home/matian_j/Delivery/PSU_FOLDER/PSU_2016_minishell1/src
**
** Made by matian
** Login   <jeremy.matian@epitech.eu>
**
** Started on  Thu Mar 23 17:12:14 2017 matian
** Last update Tue May  9 20:12:07 2017 daoudou
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] - s2[i] == 0)
    i += 1;
  return (s1[i] - s2[i]);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}

int	my_getnbr(char *str)
{
  int	var;
  int	inv;
  int	i;

  inv = 1;
  var = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while ((*str < 47 || *str > 58) && *str != 0)
    {
      str = str + 1;
      i = i + 1;
    }
  if (i > 0 && *(str - 1) == 45)
    inv = -1;
  while (*str != 0 && *str >= '0' && *str <= '9')
    {
      var = var * 10;
      var = var + *str - 48;
      str = str + 1;
    }
  var = var * inv;
  return (var);
}

void	show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i += 1;
    }
}

int	strlen_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i += 1;
  return (i);
}
