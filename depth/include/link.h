/*
** link.h for link in /home/matian_j/Delivery/CPE_FOLDER/CPE_2016_Lemin
** 
** Made by matian
** Login   <jeremy.matian@epitech.eu>
** 
** Started on  Thu Apr 13 15:09:49 2017 matian
** Last update Sun May 14 19:47:28 2017 Johanne-Franck NGBOKOLI
*/

#ifndef	LINK_H_
# define LINK_H_

typedef struct	s_elem
{
  char	       	c;
  int		x;
  int		y;
  struct s_elem	**next;
}		t_elem;

typedef struct	s_list
{
  int		length;
  t_elem	*first;
}		t_list;

typedef struct		s_node
{
  char		c;
  struct s_node	*prev;
  struct s_node	*next;
}			t_node;

/*
**
*** list create
**
*/

t_list          *create_list();
t_elem          *create_bord();
t_elem          *create_elem();
void            display_list(t_list *list, int y);
int		list_put(t_list *list, char *str) ;

/*
**
*** list replisage
**
*/

void            delet(t_list *list);
int             put_bord(t_list *list);
int             push_back(t_list *list, char c, int x, int y);
int		add_node(t_elem *tmp, t_elem *node);
t_elem		*find_node(t_list *list, int x , int y);
int		check_rod(t_list *list, int x, int y);
int		put_connect(t_list *list, t_elem *tmp, int x, int y);
t_elem          *rewind_list(t_list *list, int x, int y);

#endif	/* !LINK_H */
