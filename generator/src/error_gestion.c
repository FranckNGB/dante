/*
** error_gestion.c for emacs in /home/Johanne-Franck/My Projects/Introd.toIA/dante/generatorc
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Fri Apr 14 13:56:15 2017 Johanne-Franck NGBOKOLI
** Last update Mon May 15 16:19:14 2017 Johanne-Franck NGBOKOLI
*/

#include "generator.h"
#include "my.h"

void	error_gestion(int ac)
{
  if (ac < 3 || ac > 4)
    {
      my_putstr(USE);
      exit(ERROR_EXIT);
    }
  
}

void	error_on_argument(int width, int height)
{
  if ((width < 0 || height < 0) || (width > 200 || height > 200))
    {
      my_putstr(ERROR_SIZE);
      exit(ERROR_EXIT);
    }
}

void	error_on_option(int ac, char **argv)
{
  if (ac == 4 && strcmp(argv[3], "perfect") != 0 &&
      strcmp(argv[3], "imperfect") != 0)
    {
      my_putstr(ERROR_OPTION);
      exit(ERROR_EXIT);
    }
}

void	error_malloc(char *str)
{
  if (str == NULL)
    {
      my_putstr(ERROR_MALLOC);
      exit(ERROR_EXIT);
    } 
}
