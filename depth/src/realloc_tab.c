/*
** realloc_tab.c for Project-Master in /home/david/TEK_1/dante/david/astar/src
** 
** Made by Daoudou
** Login   <daoudou.yacouba@epitech.eu>
** 
** Started on  Sat May 13 03:00:09 2017 Daoudou
** Last update Sat May 13 03:00:45 2017 Daoudou
*/

#include "dante.h"

char	**realloc_tab(char **envp, char *argv1)
{
  int	i;
  char	**envp2;

  i = 0;
  while (envp[i] != NULL)
    i++;
  if (envp[0] == NULL)
    i = 1;
  if ((envp2 = malloc(sizeof(char*) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  while (envp[i] != NULL)
    {
      if ((envp2[i] = malloc(sizeof(char) * (my_strlen(envp[i]) + 1))) == NULL)
	return (NULL);
      envp2[i] = my_strcpy(envp2[i], envp[i]);
      i++;
    }
  if ((envp2[i] = malloc(sizeof(char) * (my_strlen(argv1) + 1))) == NULL)
    return (NULL);
  envp2[i] = my_strcpy(envp2[i], argv1);
  i++;
  envp2[i] = NULL;
  return (envp2);
}

void	free_tab(char **tab)
{
  int	index;

  index = 0;
  while (tab[index] != NULL)
    {
      free(tab[index]);
      index += 1;
    }
  free(tab);
}
