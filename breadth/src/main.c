/*
** main.c for Project-Master in /home/david/TEK_1/dante/david/astar/src
** 
** Made by Daoudou
** Login   <daoudou.yacouba@epitech.eu>
** 
** Started on  Sat May 13 01:06:03 2017 Daoudou
** Last update Sun May 14 21:05:24 2017 Johanne-Franck NGBOKOLI
*/

#include "dante.h"

int		main(int ac, char **av)
{
  t_list	*list;
  t_ptr		*ptr;
  char		*str;

  if (ac != 2)
    {
      write(2, "Error, too few or too many arguments\n", 38);
      return (84);
    }
  if (!(ptr = malloc(sizeof(*ptr))))
    return (FAILURE);
  if (!(list = create_list()))
    return (FAILURE);
  if ((str = read_map(av[1], ptr)) == NULL)
    return (FAILURE);
  if ((list_put(list, str)) != SUCCESS)
    return (FAILURE);
  if ((put_bord(list)) != SUCCESS)
    return (FAILURE);
  algo_astar(list, ptr->y);
  return (SUCCESS);
}

char		*read_map(char *str, t_ptr *ptr)
{
  struct stat	state;
  char          *buf;
  int		fd;
  int		size;
  int		red;

  stat(str, &state);
  size = (state.st_size);
  fd = open(str, O_RDONLY);
  if (!(buf = malloc(sizeof(*buf) * (size + 1))))
    return (NULL);
  red = read(fd, buf, size);
  if (red == - 1)
    {
      write(2, "Error, map file doesn't exist\n", 30);
      exit(84);
    }
  buf[red] = '\0';
  tab_len(buf, ptr);
  close(fd);
  return (buf);
}

int	tab_len(char *str, t_ptr *ptr)
{
  int	i;

  i = 0;;
  while (str[i] != '\n')
    i += 1;
  ptr->y = i;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	ptr->x += 1;
      i += 1;
    }
  return (0);
}

void		delet(t_list *list)
{
  t_elem	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      if (tmp->c == 'o')
	check_point(tmp);
      if (tmp->c == '4')
	tmp->c = '*';
      tmp = tmp->next[FIRST];
    }
  return ;
}
