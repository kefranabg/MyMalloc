/*
** algorithm.c for algorithm.c in /home/loeb_t/rendu/PSU_2013_malloc
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Feb 10 19:34:11 2014 LOEB Thomas
** Last update Thu Feb 13 18:06:55 2014 LOEB Thomas
*/

#include		"malloc.h"

static t_malloc		*algorithm_split(size_t size, t_malloc *ptr)
{
  t_malloc		new;

  if (ptr != NULL)
    {
      ptr->isFree = 0;
      if ((int)(ptr->size - (size + sizeof(t_malloc))) > 0)
      	{
      	  new.isFree = 1;
      	  new.size = (int)(ptr->size - (size + sizeof(t_malloc)));
      	  new.next = ptr->next;
      	  new.prev = ptr;
      	  ptr->size = size;
      	  ptr->next = (void*)ptr + sizeof(t_malloc) + ptr->size;
      	  memcpy(ptr->next, &new, sizeof(t_malloc));
	  if (ptr->next->next != NULL)
	    ptr->next->next->prev = ptr->next;
      	}
    }
  return (ptr);
}

static void		*algorithm_realloc(size_t size, t_malloc *ptr)
{
  size_t		alloc;

  alloc = (size_t)((void*)ptr + sizeof(t_malloc) + ptr->size);
  if (size - ptr->size > break_point - alloc)
    {
      if (brk((void*)break_point) == -1)
	return (error_return_ptr(ERROR_BRK));
      if (sbrk(ALLOC((size - ptr->size) -
		     (break_point - alloc), PS)) == (void*)-1)
	return (error_return_ptr(ERROR_SBRK));
      break_point += ALLOC((size - ptr->size) - (break_point - alloc), PS);
    }
  ptr->size = size;
  return (NULL);
}

t_malloc		*algorithm_malloc(size_t size, t_malloc *ptr)
{
  t_malloc		*ret;

  if (ptr == NULL)
    return (NULL);
  ret = NULL;
  while (ptr != NULL)
    {
      if (ptr->isFree == 1)
	{
	  if (ptr->next == NULL && ptr->size < size)
	    if (algorithm_realloc(size, ptr) == (void*)-1)
	      return ((void*)-1);
	  if (ptr->size == size ||
	      (ptr->size > size &&
	       (ret == NULL || ptr->size >= ret->size)))
	    ret = ptr;
	}
      ptr = ptr->next;
    }
  return (algorithm_split(size, ret));
}
