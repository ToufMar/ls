#include "header.h"

void  stock_time(time_t date, t_info *i)
{
  char	*s1;
	char	*s2;
	time_t	today;

	today = time(0);
	s1 = ctime(&date);
	if ((today - 15778463) > date || today < date)
	{
		s2 = ft_strnew(6);
		s2 = ft_strsub(s1, 20, 4);
		s1 = ft_strsub(s1, 4, 6);
		s1 = ft_strjoin(s1, "  ");
		s1 = ft_strjoin(s1, s2);
		free(s2);
	}
	else
		s1 = ft_strsub(s1, 4, 12);
	s1[12] = '\0';
	i->date = ft_strdup(s1);
	free(s1);
}

void stock_rights2(t_struct *s, t_info *i)
{
  if (s->sb.st_mode & S_IWGRP)
    i->droits[5] = 'w';
  else
    i->droits[5] = '-';
  if (s->sb.st_mode & S_IXGRP)
    i->droits[6] = 'x';
  else
    i->droits[6] = '-';
  if (s->sb.st_mode & S_IROTH)
    i->droits[7] = 'r';
  else
    i->droits[7] = '-';
  if (s->sb.st_mode & S_IWOTH)
    i->droits[8] = 'w';
  else
    i->droits[8] = '-';
  if (s->sb.st_mode & S_IXOTH)
    i->droits[9] = 'x';
  else
    i->droits[9] = '-';
}

void stock_rights(t_struct *s, t_info *i)
{
  if (S_ISDIR(s->sb.st_mode))
    i->droits[0] = 'd';
  else
    i->droits[0] = '-';
  if (s->sb.st_mode & S_IRUSR)
    i->droits[1] = 'r';
  else
    i->droits[1] = '-';
  if (s->sb.st_mode & S_IWUSR)
    i->droits[2] = 'w';
  else
    i->droits[2] = '-';
  if (s->sb.st_mode & S_IXUSR)
    i->droits[3] = 'x';
  else
    i->droits[3] = '-';
  if (s->sb.st_mode & S_IRGRP)
    i->droits[4] = 'r';
  else
    i->droits[4] = '-';
  stock_rights2(s, i);
  i->droits[10] = '\0';
}

void get_name_grpe(t_struct *s)
{
  s->uid = getuid();
  s->usr = getpwuid(s->uid);
  s->gid = getgid();
  s->grp = getgrgid(s->gid);
}

void check_opt(char *av, t_parse *p)
{
  int i;

  i = 0;
  while (av[i])
  {
    if (av[i] == 'l')
      p->l = 1;
    if (av[i] == 'R')
      p->R = 1;
    if (av[i] == 'a')
      p->a = 1;
    if (av[i] == 'r')
      p->r = 1;
    if (av[i] == 't')
      p->t = 1;
    i++;
  }
}

int init_parse(t_parse *parse, char *av, t_struct *s)
{
  if (av[0] == '-')
  {
    check_opt(av, parse);
    return (1);
  }
  else
    return (0);
}

void init_value(t_parse *parse, t_struct *s)
{
  parse->l = 0;
  parse->R = 0;
  parse->a = 0;
  parse->r = 0;
  parse->t = 0;
  s->rep = NULL;
  s->readenfile = NULL;
}
