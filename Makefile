##
## Makefile for makefile in /home/Johanne-Franck/My Projects/Introd.toIA/dante
## 
## Made by Johanne-Franck NGBOKOLI
## Login   <Johanne-Franck@epitech.net>
## 
## Started on  Sat May 13 16:02:34 2017 Johanne-Franck NGBOKOLI
## Last update Sun May 14 21:24:43 2017 Johanne-Franck NGBOKOLI
##

CC	=	gcc

RM	=	rm -f

all:
	make -s -C generator/ all
	make -s -C depth/ all
	make -s -C astar/ all
	make -s -C breadth/ all

clean:
	make -s -C generator/ clean
	make -s -C depth/ clean
	make -s -C astar/ clean
	make -s -C breadth/ all

fclean: clean
	make -s -C generator/ fclean
	make -s -C depth/ fclean
	make -s -C astar/ fclean
	make -s -C breadth/ fclean

re:	fclean all

.PHONY: all clean fclean re
