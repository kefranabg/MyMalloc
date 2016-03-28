/*
** calloc.c for calloc.c in /home/loeb_t/rendu/PSU_2013_malloc/src
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu Feb 13 17:18:25 2014 LOEB Thomas
** Last update Sun Feb 16 17:09:56 2014 abgral_f
*/

#include		"malloc.h"

void			*calloc(size_t nmemb, size_t size)
{
  void			*ret;
  size_t		total;

  if (nmemb == 0 || size == 0)
    return (NULL);
  total = nmemb * size;
  while (total % sizeof(int) != 0)
    total++;
  ret = malloc(total);
  if (ret != NULL)
    memset(ret, 0, total);
  return (ret);
}
