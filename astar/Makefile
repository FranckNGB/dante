##
## Makefile for lemin in /home/Matian_j/Delivery/CPE_folder/CPE_2016_Lemin
## 
## Made by jérémy Matian
## Login   <Matian_j@epitech.net>
## 
## Started on  Thu Apr 27 14:39:29 2017 jérémy Matian
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wextra -Wall
CFLAGS	+=	-I./include
LDFLAG	=	-L./lib/-lmy

NAME	=	solver

SRCS	=	src/Astar/algo.c		\
		src/graph/my_graph.c		\
		src/graph/my_pc_graph.c		\
		lib/my/function2.c		\
		lib/my/function.c		\
		lib/my/get_next_line.c		\
		lib/my/my_str_to_wordtab.c	\
		src/realloc_tab.c		\
		src/main.c			\
		src/check.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
