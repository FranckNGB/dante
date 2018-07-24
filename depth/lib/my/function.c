/*
** function.c for function in /home/jeremy.matian/CPE_2016_getnextline
**
** Made by jeremy matian
** Login   <jeremy.matian@epitech.net>
**
** Started on  Fri Jan 13 17:27:36 2017 jeremy matian
** Last update Tue May  9 20:11:31 2017 daoudou
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char		*my_strcat(char *str1, char *str2)
{
  char		*str;
  int		i;

  if (str1 == NULL || str2 == NULL)
    return (NULL);
  i = my_strlen(str1) + my_strlen(str2) + 1;
  if ((str = malloc(sizeof(char) * i)) == NULL)
    return (NULL);
  i = 0;
  while (*str1 != '\0')
    str[i++] = *str1++;
  while (*str2 != '\0')
    str[i++] = *str2++;
  str[i] = '\0';
  return (str);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}

int		my_put_nbr(int nb)
{
  int		i;

  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  if (nb <= 9)
    my_putchar(nb + 48);
  else if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      i = nb % 10;
      my_putchar(i + 48);
    }
  return (0);
}
