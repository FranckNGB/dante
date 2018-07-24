/*
** check_arg.c for check_arg in /home/Johanne-Franck/My Projects/Introd.toIA/dante/franck/generatorc
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Tue May  9 16:56:45 2017 Johanne-Franck NGBOKOLI
** Last update Mon May 15 16:15:43 2017 Johanne-Franck NGBOKOLI
*/

#include "generator.h"

void	get_coord(int ac, char **av, int *width, int *height)
{
  *width = atoi(av[1]);
  *height = atoi(av[2]);
  error_on_argument(*width, *height);
  error_on_option(ac, av);
}

t_my_maze	get_memory_and_coord(t_my_maze maze, int width, int height)
{
  maze.str = malloc(width * height * sizeof(char*));
  error_malloc(maze.str);
  maze.width = width;
  maze.height = height;
  return (maze);
}
