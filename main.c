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

void print_rights(t_struct *s)
{
  S_ISDIR(s->sb.st_mode) ? ft_putchar('d') : ft_putchar('-');
  (s->sb.st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
  (s->sb.st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
  (s->sb.st_mode & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
  (s->sb.st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
  (s->sb.st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
  (s->sb.st_mode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
  (s->sb.st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
  (s->sb.st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
  (s->sb.st_mode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
  ft_putstr("  ");
}

int main(int ac, char **av)
{
  t_struct s;
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
  s.uid = getuid();
  s.usr = getpwuid(s.uid);
  s.gid = getgid();
  s.grp = getgrgid(s.gid);
  while ((s.readenfile = readdir(s.rep)) != NULL)
  {
    stat(s.readenfile->d_name, &s.sb);
    print_rights(&s);
    ft_putnbr((int)s.sb.st_nlink);
    SPACE;
    ft_putstr(s.usr->pw_name);
    SPACE;
    ft_putstr(s.grp->gr_name);
    SPACE;
    ft_putnbr((int)s.sb.st_size);
    SPACE;
    print_time(s.sb.st_mtime);
    SPACE;
    ft_putstr(s.readenfile->d_name);
    NL;
  }
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
  return (0);
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
