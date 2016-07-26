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

typedef struct s_info
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
}             t_info;

int init_parse(t_parse *parse, char *av, t_struct *s);
void init_value(t_parse *parse, t_struct *s);
void check_opt(char *av, t_parse *parse);
void get_name_grpe(t_struct *s);
void stock_rights(t_struct *s, t_info *i);
void stock_rights2(t_struct *s, t_info *i);
void  stock_time(time_t date, t_info *i);
#endif
