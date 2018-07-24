/*
** my_putstr.c for my_putstr in /home/Johanne-Franck/My Projects/Introd.toIA/dante/generator/lib
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Sun May 14 19:23:45 2017 Johanne-Franck NGBOKOLI
** Last update Sun May 14 19:27:29 2017 Johanne-Franck NGBOKOLI
*/

#include "my.h"

void	my_putstr(char *str)
{
  write(2, str, my_strlen(str));
}
