/*
** get7.c for get7 in /home/jeremy.matianepi/CPE_2017_getnextline
**
** Made by Jérémy MATIAN
** Login   <jeremy.matianepi@epitech.net>
**
** Started on  Thu Jan 12 15:07:37 2017 Jérémy MATIAN
** Last update Sat May 13 02:26:09 2017 Daoudou
*/

#include "my.h"

char		stock_and_recup_char(const int fd)
{
  t_struct	ptr;
  static char	*string;
  static char	*buffer;
  static int	read_value = 0;

  if ((buffer = malloc(sizeof(char) * ALLOC_1)) == NULL)
    return (-1);
  while (read_value == 0)
    {
      if ((read_value = read(fd, buffer, READ_SIZE)) == -1)
	return (-1);
	  string = buffer;
      if (read_value == 0)
	return (0);
    }
   if (read_value != 0)
    {
      ptr.character = *string;
      string = string + 1;
      read_value = read_value - 1;
    }
  return (ptr.character);
}

char		*get_next_line(const int fd)
{
  t_struct	ptr;
  char		*string;

  if ((ptr.character = stock_and_recup_char(fd)) == -1)
    return (NULL);
  if ((string = malloc(sizeof(char) * ALLOC_1)) == NULL)
    return (NULL);
  ptr.index = 0;
  while (ptr.character != '\0' && ptr.character != '\n')
    {
      string[ptr.index] = ptr.character;
      ptr.character = stock_and_recup_char(fd);
      ptr.index = ptr.index + 1;
    }
  string[ptr.index] = '\0';
  if (ptr.character == 0)
    return (NULL);
  return (string);
}
