/*
** malloc.h for malloc.h in /home/loeb_t/rendu/PSU_2013_malloc
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed Feb  5 16:48:59 2014 LOEB Thomas
** Last update Sun Feb 16 15:49:45 2014 abgral_f
*/

#ifndef			MALLOC_H_
# define		MALLOC_H_

# include		<unistd.h>
# include		<stdlib.h>
# include		<string.h>
# include		<stdio.h>
# include		<pthread.h>

# define		PS		getpagesize()
# define		ONE_MORE(x)	(((x) != 0) ? 1 : 0)
# define		ALLOC(x, y)	(((x) / (y)) * (y)) + (ONE_MORE((x) % (y)) * (y))

pthread_mutex_t my_mutex;

typedef struct		s_malloc {
  unsigned int		isFree;
  unsigned int		size;
  struct s_malloc	*next;
  struct s_malloc	*prev;
}			t_malloc;

t_malloc		*first;
size_t			break_point;

void			*malloc(size_t size);
void			free(void *ptr);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem();
void			free_regroup(t_malloc *search, char erase);
t_malloc		*algorithm_malloc(size_t size, t_malloc *ptr);

void			*calloc(size_t nmemb, size_t size);

void			*error_return_ptr(char *message);
void			error_return_void(char *message);
void			error_exit(char *message);

# define		ERROR_SBRK	"Error: system call 'sbrk' failed"
# define		ERROR_BRK	"Error: system call 'brk' failed"
# define		ERROR_FREE_PTR	"Error: free: invalid pointer"

#endif
