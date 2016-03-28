/*
** free.c for free.c in /home/loeb_t/rendu/PSU_2013_malloc
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Feb 10 20:00:01 2014 LOEB Thomas
** Last update Sun Feb 16 15:48:03 2014 abgral_f
*/

#include		"malloc.h"

static void		free_erase(t_malloc *search)
{
  size_t		total;

  memset((void*)search + sizeof(t_malloc), 0, search->size);
  search->isFree = 1;
  if (search->next == NULL)
    {
      if (search->prev == NULL)
	{
	  total = (break_point - (size_t)first) / PS;
	  first = NULL;
	}
      else
	{
	  total = (break_point - (size_t)search) / PS;
	  search->prev->next = NULL;
	}
      if (total > 0)
	{
	  if (brk((void*)break_point) == -1)
	    return (error_return_void(ERROR_BRK));
	  if (sbrk(- (total * PS)) == (void*)-1)
	    return (error_return_void(ERROR_SBRK));
	  break_point -= (total * PS);
	}
    }
}

void			free_regroup(t_malloc *search, char erase)
{
  if (search->prev != NULL && search->prev->isFree == 1)
    {
      search->prev->size += (sizeof(t_malloc) + search->size);
      search->prev->next = search->next;
      if (search->next != NULL)
	search->next->prev = search->prev;
      search = search->prev;
    }
  if (search->next != NULL && search->next->isFree == 1)
    {
      search->size += (sizeof(t_malloc) + search->next->size);
      search->next = search->next->next;
      if (search->next != NULL)
	search->next->prev = search;
    }
  if (erase == 1)
    free_erase(search);
}

void			free(void *ptr)
{
  t_malloc		*search;

  if (ptr == NULL || first == NULL)
    return ;
  pthread_mutex_init (&my_mutex, NULL);
  pthread_mutex_lock (&my_mutex);
  search = first;
  while (search != NULL && (void*)search + sizeof(t_malloc) != ptr)
    search = search->next;
  if (search != NULL)
    free_regroup(search, 1);
  pthread_mutex_unlock (&my_mutex);
  pthread_mutex_destroy(&my_mutex);
}
