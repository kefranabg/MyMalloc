/*
** malloc.c for malloc.c in /home/loeb_t/rendu/PSU_2013_malloc
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue Feb  4 15:23:46 2014 LOEB Thomas
** Last update Sun Feb 16 15:47:47 2014 abgral_f
*/

#include		"malloc.h"

static void		*malloc_add_end(size_t size, t_malloc *ptr)
{
  if (size > break_point - (size_t)ptr)
    {
      if (brk((void*)break_point) == -1)
	return (error_return_ptr(ERROR_BRK));
      if (sbrk(ALLOC(size - (break_point - (size_t)ptr), PS)) == (void*)-1)
	return (error_return_ptr(ERROR_SBRK));
      break_point += ALLOC(size - (break_point - (size_t)ptr), PS);
    }
  return (NULL);
}

static void		*malloc_add_new(size_t size, t_malloc *ptr)
{
  t_malloc		new;

  new.isFree = 0;
  new.size = size;
  new.next = NULL;
  size += sizeof(t_malloc);
  if (ptr == NULL)
    {
      if ((first = sbrk(ALLOC(size, PS))) == (void*)-1)
	return (error_return_ptr(ERROR_SBRK));
      break_point = (size_t)first + ALLOC(size, PS);
      new.prev = NULL;
      ptr = first;
    }
  else
    {
      while (ptr->next != NULL)
	ptr = ptr->next;
      new.prev = ptr;
      ptr->next = (void*)ptr + sizeof(t_malloc) + ptr->size;
      ptr = ptr->next;
      if (malloc_add_end(size, ptr) == (void*)-1)
      	return ((void*)-1);
    }
  return (memcpy(ptr, &new, sizeof(t_malloc)));
}

void			*malloc(size_t size)
{
  t_malloc		*end;

  if (size <= 0)
    return (NULL);
  pthread_mutex_init (&my_mutex, NULL);
  pthread_mutex_lock (&my_mutex);
  while (size % sizeof(int) != 0)
    size++;
  if ((end = algorithm_malloc(size, first)) == NULL)
    end = malloc_add_new(size, first);
  pthread_mutex_unlock (&my_mutex);
  pthread_mutex_destroy(&my_mutex);
  if (end == (void*)-1)
    return (NULL);
  return ((void*)end + sizeof(t_malloc));
}
