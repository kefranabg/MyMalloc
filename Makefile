##
## Makefile for Makefile in /home/loeb_t/rendu/PSU_2013_malloc
## 
## Made by LOEB Thomas
## Login   <loeb_t@epitech.net>
## 
## Started on  Tue Feb  4 15:32:18 2014 LOEB Thomas
## Last update Thu Feb 13 18:10:03 2014 LOEB Thomas
##

NAME	= libmy_malloc_$(HOSTTYPE).so

LINK	= libmy_malloc.so

INC_F	= inc/

SRC_F	= src/

SRC	= $(SRC_F)malloc.c		\
	  $(SRC_F)free.c		\
	  $(SRC_F)realloc.c		\
	  $(SRC_F)show_alloc_mem.c	\
	  $(SRC_F)algorithm.c		\
	  $(SRC_F)calloc.c		\
	  $(SRC_F)error.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -W -Wall -Werror -fPIC -I $(INC_F) -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	gcc -shared -o $(NAME) $(OBJ)
	ln -s $(NAME) $(LINK)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(LINK)

re: fclean all
