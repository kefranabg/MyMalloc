/*
** show_alloc_mem.c for show_alloc_mem.c in /home/loeb_t/rendu/PSU_2013_malloc
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Feb 10 20:03:55 2014 LOEB Thomas
** Last update Thu Feb 13 17:18:16 2014 LOEB Thomas
*/

#include		"malloc.h"

void			show_alloc_mem()
{
  t_malloc		*end;

  if (first == NULL)
    printf("break : %p\n", sbrk(0));
  else
    printf("break : %p\n", (void*)break_point);
  end = first;
  while (end != NULL)
    {
      if (end->isFree == 0)
	printf("%p - %p : %u octets\n",
	       (void*)end + sizeof(t_malloc),
	       (void*)end + sizeof(t_malloc) + end->size, end->size);
      end = end->next;
    }
}
