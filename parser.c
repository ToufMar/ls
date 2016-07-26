#include "header.h"

void  stock_time(time_t date, t_llist *list)
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
	list->date = ft_strdup(s1);
	free(s1);
}

void stock_rights2(t_struct *s, t_llist *list)
{
  if (s->sb.st_mode & S_IWGRP)
    list->droits[5] = 'w';
  else
    list->droits[5] = '-';
  if (s->sb.st_mode & S_IXGRP)
    list->droits[6] = 'x';
  else
    list->droits[6] = '-';
  if (s->sb.st_mode & S_IROTH)
    list->droits[7] = 'r';
  else
    list->droits[7] = '-';
  if (s->sb.st_mode & S_IWOTH)
    list->droits[8] = 'w';
  else
    list->droits[8] = '-';
  if (s->sb.st_mode & S_IXOTH)
    list->droits[9] = 'x';
  else
    list->droits[9] = '-';
}

void stock_rights(t_struct *s, t_llist *list)
{
  if (S_ISDIR(s->sb.st_mode))
    list->droits[0] = 'd';
  else
    list->droits[0] = '-';
  if (s->sb.st_mode & S_IRUSR)
    list->droits[1] = 'r';
  else
    list->droits[1] = '-';
  if (s->sb.st_mode & S_IWUSR)
    list->droits[2] = 'w';
  else
    list->droits[2] = '-';
  if (s->sb.st_mode & S_IXUSR)
    list->droits[3] = 'x';
  else
    list->droits[3] = '-';
  if (s->sb.st_mode & S_IRGRP)
    list->droits[4] = 'r';
  else
    list->droits[4] = '-';
  stock_rights2(s, list);
  list->droits[10] = '\0';
}

void get_name_grpe(t_struct *s)
{
  s->uid = getuid();
  s->usr = getpwuid(s->uid);
  s->gid = getgid();
  s->grp = getgrgid(s->gid);
}

void check_opt(char *av, t_parse *parse)
{
  int i;

  i = 0;
  while (av[i])
  {
    if (av[i] == 'l')
      parse->l = 1;
    if (av[i] == 'R')
      parse->R = 1;
    if (av[i] == 'a')
      parse->a = 1;
    if (av[i] == 'r')
      parse->r = 1;
    if (av[i] == 't')
      parse->t = 1;
    i++;
  }
}

int init(t_parse *parse, char *av)
{
  parse->l = 0;
  parse->R = 0;
  parse->a = 0;
  parse->r = 0;
  parse->t = 0;

  if (av[0] == '-')
  {
    check_opt(av, parse);
    return (1);
  }
  else
    return (0);
}
