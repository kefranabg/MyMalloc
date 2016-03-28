/*
** error.c for error.c in /home/loeb_t/rendu/PSU_2013_malloc
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed Feb 12 22:37:53 2014 LOEB Thomas
** Last update Wed Feb 12 22:39:31 2014 LOEB Thomas
*/

#include		"malloc.h"

void			*error_return_ptr(char *message)
{
  printf("%s\n", message);
  return ((void*)-1);
}

void			error_return_void(char *message)
{
  printf("%s\n", message);
  return ;
}

void			error_exit(char *message)
{
  printf("%s\n", message);
  exit(0);
}
