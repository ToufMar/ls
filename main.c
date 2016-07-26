#include "header.h"

void stock(t_list **l, t_struct *s)
{
  t_info *i;

  while ((s->readenfile = readdir(s->rep)) != NULL)
  {
    i = (t_info *)malloc(sizeof(t_info));
    stat(s->readenfile->d_name, &s->sb);
    i->name = ft_strdup(s->readenfile->d_name);
    i->nlink = (int)s->sb.st_nlink;
		i->size = (int)s->sb.st_size;
    i->date2 = (int)s->sb.st_mtime;
    stock_rights(s, i);
    stock_time(s->sb.st_mtime, i);
    ft_push_back(l, i, 0);
    i++;
  }
}

void print_ls(t_info *i)
{
  ft_putstr(i->name);
  ft_putchar('\n');
}

void print_ls_l(t_info *i, t_struct *s)
{
  ft_putstr(i->droits);
  SPACE;
  ft_putnbr(i->nlink);
  SPACE;
  ft_putstr(s->usr->pw_name);
  SPACE;
  ft_putstr(s->grp->gr_name);
  SPACE;
  ft_putnbr(i->size);
  SPACE;
  ft_putstr(i->date);
  SPACE;
  ft_putstr(i->name);
  NL;
}

void print(t_list **list, t_parse *p, t_struct *s)
{
  t_list *tmp;

  tmp = *list;
  printf("l %d, R %d, a %d, r %d, t %d\n", p->l, p->R, p->a, p->r, p->t);
  while (tmp != NULL)
  {
    if (!p->l && !p->R && !p->a && !p->r && !p->t)
      print_ls(tmp->content);
    else if (p->l && !p->R && !p->a && !p->r && !p->t)
      print_ls_l(tmp->content, s);
    tmp = tmp->next;
  }
}

int main(int ac, char **av)
{
  t_list *l;
  t_info i;
  t_parse p;
  t_struct *s;
  s = (t_struct *)malloc(sizeof(t_struct));
  l = NULL;
  init_value(&p, s);
  if (ac > 1)
    init_parse(&p, av[1], s);
  get_name_grpe(s);
  printf("ok1\n");
  if ((s->rep = opendir("./")) != NULL)
    stock(&l, s);
  print(&l, &p, s);
}
