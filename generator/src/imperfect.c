/*
** imperfect.c for imperfect in /home/Johanne-Franck/My Projects/Introd.toIA/dante/franck/generatorc
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Tue May  9 15:18:43 2017 Johanne-Franck NGBOKOLI
** Last update Sun May 14 14:24:57 2017 Johanne-Franck NGBOKOLI
*/

#include "generator.h"
#include "my.h"

char	**get_maze_tab(t_my_maze maze)
{
  t_my_coord    pos;
  t_my_coord	compt;
  char		**tab;

  pos.y = 0;
  compt.y = 0;
  tab = malloc(sizeof(char **) * (maze.width * maze.height) + 1);
  while (pos.y < maze.height)
    {
      pos.x = 0;
      compt.x = 0;
      tab[compt.y] = malloc(sizeof(char *) * (maze.height) + 1);
      while (pos.x < maze.width)
	{
	  maze.cas = maze.str[pos.y * maze.width + pos.x];
	  if (maze.cas == 1)
	    tab[compt.y][compt.x] = 'X';
	  else if (maze.cas == 2)
	    tab[compt.y][compt.x] = 'o';
	  else
	    tab[compt.y][compt.x] = '*';
	  pos.x = pos.x + 1;
	  compt.x++;
	}
      pos.y++;
      compt.y++;
    }
  return (tab);
}

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void    print_maze(t_my_maze maze)
{
  char	**tab;
  int	i;
  int	j;

  tab = get_maze_tab(maze);
  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  printf("%c", tab[i][j]);
	  j++;
	}
      if (tab[i] && tab[i + 1] ==  NULL)
	{
	  my_free_tab(tab);
	  return ;
	}
      printf("\n");
      i++;
    }
  my_free_tab(tab);
}

t_my_maze	generate_imperfect_maze(t_my_maze maze)
{
  t_my_coord	pos;
  int		compt;
  int		nbr;

  compt = 0;
  generate_perfect_maze(maze);
  nbr = maze.width + 2;
  while (compt <= nbr)
    {
      pos.x = (rand()%(maze.width - 2) + 2);
      pos.y = (rand()%(maze.height - 2) + 2);
      if (pos.y < maze.height && pos.x < maze.width)
	maze.str[pos.y * maze.width + pos.x] = 3;
      compt++;
    }
  return (maze);
}
