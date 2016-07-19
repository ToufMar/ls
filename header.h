#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <unistd.h>
# include <grp.h>
# include "libft/libft.h"
# include <time.h>

# define SPACE ft_putchar(' ');
# define NL ft_putchar('\n');
typedef struct s_struct
{
  DIR *rep;
  char *rights;
  int blocks;
  int oct;
  char *name;
  struct dirent *readenfile;
  struct stat sb;
  struct passwd *usr;
  struct group *grp;
  struct tm *tps;
  uid_t uid;
  gid_t gid;
}              t_struct;

typedef struct s_llist
{
  int size;
  int nlink;
  struct s_llist *next;
}
               t_llist;

void		ft_push_back_t(t_llist **list, t_struct *s);
t_llist *add_link(t_struct *s);
void print_list(t_llist *list);
#endif
