##
## Makefile for makefile in /home/Johanne-Franck/My Projects/Introd.toIA/dante/generatorc
## 
## Made by Johanne-Franck NGBOKOLI
## Login   <Johanne-Franck@epitech.net>
## 
## Started on  Sat May 13 14:12:31 2017 Johanne-Franck NGBOKOLI
## Last update Sun May 14 12:39:48 2017 Johanne-Franck NGBOKOLI
##

CC	=	gcc -g3

RM	=	rm -rf

CFLAGS	+=	-Wextra -Wall
CFLAGS  +=	-I./include

NAME	=	generator

SRCS	=	src/main.c \
		src/check_arg.c \
		src/error_gestion.c \
		src/imperfect.c \
		src/perfect.c \
		lib/my_putstr.c \
		lib/my_strlen.c \
		lib/my_str_to_wordtab.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
