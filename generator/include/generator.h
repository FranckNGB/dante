/*
** generator.h for emacs in /home/Johanne-Franck/My Projects/Introd.toIA/dante/generatorc
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Tue Apr 11 14:53:03 2017 Johanne-Franck NGBOKOLI
** Last update Sun May 14 14:41:33 2017 Johanne-Franck NGBOKOLI
** Last update Wed May 10 06:59:24 2017 Daoudou
*/

#ifndef GENERATOR_H_
# define GENERATOR_H_

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <string.h>
# include "my.h"
# define ERROR_EXIT (84)
# define USE ("You have to use it by this way: ./generator [x] [y] [perfect/imperfect]\n")
# define ERROR_SIZE ("ERROR invalid maze's size\n")
# define ERROR_OPTION ("ERROR, invalid option\n")
# define ERROR_MALLOC ("ERROR, Not allowed memory for maze\n")
# define MAZE_NATURE  ("Error, maze must be rectangular\n")

typedef struct	s_my_maze
{
  char		*str;
  int		width;
  int		height;
  int		cas;
}		t_my_maze;

typedef struct	s_my_positions
{
  int		xd;
  int		yd;
  int		xend;
  int		yend;
  int		dir_x;
  int		dir_y;
  int		way;
  int		compt;
}		t_my_positions;

typedef struct	s_my_coord
{
  int		x;
  int		y;
}		t_my_coord;

void		generate_perfect_maze(t_my_maze maze);
void		print_maze(t_my_maze maze);
void		error_gestion(int ac);
void		error_on_argument(int width, int height);
void		error_on_option(int ac, char **argv);
void		error_malloc(char *str);
void		init_pos(t_my_positions *pos, t_my_coord coord);
void		init_end_maze(t_my_maze *maze, t_my_coord *coord, t_my_positions *pos);
t_my_maze	generate_imperfect_maze(t_my_maze maze);
void		init_maze(t_my_maze maze, t_my_coord coord);
void		get_coord(int ac, char **av, int *width, int *height);
t_my_maze       get_memory_and_coord(t_my_maze maze, int width, int height);
char		**malloc_tab(int cols, int rows);
void		free_tab(char **tab);

#endif /* !GENERATOR_H_ */
