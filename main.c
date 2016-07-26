#include "header.h"

int main(int ac, char **av)
{
  t_struct s;
  t_llist *list;
  list = NULL;
  t_parse parse;

  if (ac > 1)
    init(&parse, av[1]);
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
    ft_push_back_t(&list, &s);
    s.block += (int)s.sb.st_blocks;
  }
  print_list(list, &s, &parse);
  trie_list(list, &s);
  printf("nouveau trie\n");
  print_list(list, &s, &parse);
  if (s.readenfile == NULL)
  {
    printf("probleme de lecture\n");
    return (0);
  }
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
