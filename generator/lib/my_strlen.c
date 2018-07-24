/*
** my_strlen.c for my_strlen in /home/Johanne-Franck/My Projects/Introd.toIA/dante/generator/lib
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Sun May 14 19:24:58 2017 Johanne-Franck NGBOKOLI
** Last update Sun May 14 19:26:22 2017 Johanne-Franck NGBOKOLI
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
