/*
** realloc.c for realloc.c in /home/loeb_t/rendu/PSU_2013_malloc
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Feb 10 20:06:32 2014 LOEB Thomas
** Last update Thu Feb 13 17:18:03 2014 LOEB Thomas
*/

#include		"malloc.h"

void			*realloc(void *ptr, size_t size)
{
  t_malloc		*search;
  void			*ret;

  if (ptr == NULL || first == NULL)
    return (malloc(size));
  search = first;
  while (search != NULL && (void*)search + sizeof(t_malloc) != ptr)
    search = search->next;
  if (search == NULL)
    return (malloc(size));
  search->isFree = 1;
  free_regroup(search, 0);
  if (ptr != (void*)search + sizeof(t_malloc))
    memcpy((void*)search + sizeof(t_malloc), ptr,
	   (size_t)(ptr - sizeof(t_malloc) + sizeof(unsigned int)));
  ret = malloc(size);
  if (ret != NULL && ret != (void*)search + sizeof(t_malloc))
    {
      memcpy(ret, (void*)search + sizeof(t_malloc), size);
      free((void*)search + sizeof(t_malloc));
    }
  return (ret);
}
