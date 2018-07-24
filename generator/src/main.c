/*
** main.c for emacs in /home/Johanne-Franck/My Projects/Introd.toIA/dante/csrc
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Mon Apr 10 17:49:30 2017 Johanne-Franck NGBOKOLI
** Last update Mon May 15 16:24:32 2017 Johanne-Franck NGBOKOLI
*/

#include "generator.h"

int	main(int ac, char **argv)
{
  t_my_maze     maze;
  int		width;
  int		height;

  error_gestion(ac);
  get_coord(ac, argv, &width, &height);
  maze = get_memory_and_coord(maze, width, height);
  if (ac == 3)
    {
      maze = generate_imperfect_maze(maze);
      print_maze(maze);
    }
  else if (strcmp(argv[3], "perfect") == 0)
    {
      generate_perfect_maze(maze);
      print_maze(maze);
    }
  free(maze.str);
  return (0);
}

