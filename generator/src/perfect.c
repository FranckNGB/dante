/*
** generator.c for emacs in /home/Johanne-Franck/My Projects/Introd.toIA/dante/generatorc
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Tue Apr 11 15:03:13 2017 Johanne-Franck NGBOKOLI
*/

#include "generator.h"

void	init_pos(t_my_positions *pos, t_my_coord coord)
{
  pos->xd = coord.x + pos->dir_x;
  pos->yd = coord.y + pos->dir_y;
  pos->xend = pos->xd + pos->dir_x;
  pos->yend = pos->yd + pos->dir_y;
}

void	init_end_maze(t_my_maze *maze, t_my_coord *coord, t_my_positions *pos)
{
  maze->str[pos->yd * maze->width + pos->xd] = 0;
  maze->str[pos->yend * maze->width + pos->xend] = 0;
  coord->x = pos->xend;
  coord->y = pos->yend;
  pos->way = rand() % 4;
  pos->compt = 0;
}

void	init_maze(t_my_maze maze, t_my_coord coord)
{
  t_my_positions	pos;
  
   pos.way = rand() % 4;
   pos.compt = 0;
   while (pos.compt < 4)
     {
       pos.dir_x = 0;
       pos.dir_y = 0;
       if (pos.way ==  0)
	 pos.dir_x = 1;
       else if (pos.way == 1)
	 pos.dir_y = 1;
       else if (pos.way ==  2)
	 pos.dir_x = -1;
       else
	 pos.dir_y = -1;
       init_pos(&pos, coord);
       if (pos.xend > 0 && pos.xend < maze.width && pos.yend > 0
	   && pos.yend < maze.height && maze.str[pos.yd * maze.width + pos.xd] == 1
	   && maze.str[pos.yend * maze.width + pos.xend] == 1)
	 init_end_maze(&maze, &coord, &pos);
       pos.way = (pos.way + 1) % 4;
       pos.compt = pos.compt + 1;
     }
}

void	generate_perfect_maze(t_my_maze maze)
{  
  t_my_coord	place;

  place.x = 0;
  while (place.x < maze.width * maze.height)
    {
      maze.str[place.x] = 1;
      place.x = place.x + 1;
    }
  maze.str[maze.width + 1] = 0;
  srand(time(NULL));
  place.y = 1;
  while (place.y < maze.height)
    {
      place.x = 1;
      while (place.x < maze.width)
	{
	  init_maze(maze, place);
	  place.x = place.x + 2;
	}
      place.y = place.y + 2;
    }
  maze.str[0] = 0;
  maze.str[1] = 0;
  maze.str[(maze.height - 1) * maze.width + (maze.width - 1)] = 0;
  maze.str[(maze.height - 1) * maze.width + (maze.width - 2)] = 0;
 }
