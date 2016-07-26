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
  char *name;
  struct dirent *readenfile;
  struct stat sb;
  struct passwd *usr;
  struct group *grp;
  struct tm *tps;
  uid_t uid;
  gid_t gid;
  int block;
}              t_struct;

typedef struct s_parse
{
  int l;
  int R;
  int a;
  int r;
  int t;
}               t_parse;

typedef struct s_llist
{
  char            droits[11];
  int             size;
  int             nlink;
  char            *name;
  struct s_llist  *next;
  char            *date;
  int             date2;
  char            *folder;
  char            *path;
}
               t_llist;

void		ft_push_back_t(t_llist **list, t_struct *s);
t_llist *add_link(t_struct *s);
void print_list(t_llist *list, t_struct *s, t_parse *p);
void stock_rights(t_struct *s, t_llist *list);
void  stock_time(time_t date, t_llist *list);
void  stock_time(time_t date, t_llist *list);
void stock_rights2(t_struct *s, t_llist *list);
void stock_rights(t_struct *s, t_llist *list);
void get_name_grpe(t_struct *s);
void check_opt(char *av, t_parse *parse);
int init(t_parse *parse, char *av);
void ls_l(t_llist *list, t_struct *s);
void choose_opt(t_llist *list, t_struct *s, t_parse *p);
void ls(t_llist *list, t_struct *s);
void trie_list(t_llist *list, t_struct *s);
void    swap_info(t_llist *elem1, t_llist *elem2);
void swap_string(char **a, char **b);
void swap_droits(char a, char b);
#endif
