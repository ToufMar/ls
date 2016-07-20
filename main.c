#include "header.h"

void print_time(time_t date)
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
	ft_putstr(s1);
	ft_putchar(' ');
	free(s1);
}

void print_rights2(t_struct *s, t_llist *list)
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

void print_rights(t_struct *s, t_llist *list)
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
  print_rights2(s, list);
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

int main(int ac, char **av)
{
  t_struct s;
  t_llist *list;
  t_parse parse;
  init(&parse, av[1]);
/*  list = NULL;
  s.rep = NULL;
  s.readenfile = NULL;
  s.rep = opendir("./");
  if (s.rep == NULL)
  {
    printf("probleme\n");
    return (0);
  }
  else
    printf("ok fichier ouvert\n");
  get_name_grpe(&s);
  while ((s.readenfile = readdir(s.rep)) != NULL)
  {
    stat(s.readenfile->d_name, &s.sb);
    print_rights(&s);
    SPACE;
    ft_putstr(s.usr->pw_name);
    SPACE;
    ft_putstr(s.grp->gr_name);
    SPACE;
    print_time(s.sb.st_mtime);
    SPACE;
    ft_putstr(s.readenfile->d_name);
    NL;
    ft_push_back_t(&list, &s);
  }
  print_list(list);
  if (s.readenfile == NULL)
  {
    printf("probleme de lecture\n");
    return (0);
  }
  else

  if (closedir(s.rep) == -1)
  {
    printf("mal fermé");
     return (0);
  }
  return (0);*/
}
/*void affdossier (char *nom_dossier)
{
DIR *dossier;
struct dirent *contenu_dossier;
struct stat infos;
printf("Affichage de %s : \n", nom_dossier);
  if((dossier = opendir(nom_dossier)) != NULL)
  {
    while ((contenu_dossier = readdir(dossier)) != NULL)
    {
      if ( (strcmp(".", contenu_dossier->d_name) != 0)
      && (strcmp("..", contenu_dossier->d_name) != 0) )
      {
        stat(contenu_dossier->d_name, &infos);
        printf(" %s ", contenu_dossier->d_name);
        printf("\n");
        if(S_ISDIR(infos.st_mode))
          affdossier(contenu_dossier->d_name);
      }
    }

}
  if (closedir(dossier) == -1) {
  perror("Fermeture du repertoire");
  exit(2);
  }

}

int main(int argc, char **argv)
{
  affdossier("./");
  return (0);
}*/
