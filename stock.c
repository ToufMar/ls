#include "header.h"

t_info  *stock_infos(t_struct *s, int nb, char *dossier)
{
  t_info *i;

  i = (t_info*)malloc(sizeof(t_info));
  i->name = ft_strdup(s->readenfile->d_name);
  i->nlink = (int)s->sb.st_nlink;
  i->size = (int)s->sb.st_size;
  i->date2 = (int)s->sb.st_mtime;
  stock_rights(s, i);
  stock_time(s->sb.st_mtime, i);
  if (nb)
    i->path = ft_strdup(dossier);
  return (i);
}

void stock(t_llist **l, t_struct *s, t_parse *p)
{
  t_info *i;

  while ((s->readenfile = readdir(s->rep)) != NULL)
  {
    stat(s->readenfile->d_name, &s->sb);
    i = stock_infos(s, 0, "");
    if (p->t)
      ft_push_back_t(l, i, i->date2);
    else
      ft_push_back_n(l, i, i->name);
  }
}

char    *concat_path(char *root, char *dir)
{
  char  *tmp = NULL;

  tmp = (char*)malloc(ft_strlen(root) + ft_strlen(dir) + 1);
  if (tmp == NULL)
    return NULL;
  tmp = ft_strcat(tmp, root);
  tmp = ft_strcat(tmp, "/");
  tmp = ft_strcat(tmp, dir);
  return (tmp);
}

void stock_R(t_llist **l, t_parse *p, char *dossier)
{
  t_struct *s;
  t_info *i;

  if ((s = (t_struct *)malloc(sizeof(t_struct))) == NULL)
    exit(EXIT_FAILURE);
  ft_memset(&s->sb, 0, sizeof(struct stat));
  if((s->rep = opendir(dossier)) != NULL)
  {
    while ((s->readenfile = readdir(s->rep)) != NULL)
    {
      if ( (strcmp(".", s->readenfile->d_name) != 0)
      && (strcmp("..", s->readenfile->d_name) != 0))
      {
        stat(concat_path(dossier, s->readenfile->d_name), &s->sb);
        i = stock_infos(s, 1, dossier);
        if (!p->t)
          ft_push_back_R(l, i, dossier, s->readenfile->d_name);
        else
          ft_push_back_Rt(l, i, dossier, i->date2);
        if(S_ISDIR(s->sb.st_mode))
          stock_R(l,p, concat_path(dossier, s->readenfile->d_name));
      }
    }
  }
  closedir(s->rep);
}
