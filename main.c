 #include "header.h"

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

// void print_ls_Rt(t_llist **list)
// {
//   t_llist *tmp1;
//   t_llist *tmp2;
//   t_llist *tmp3;
//
//   tmp1 = *list;
//   while (ft_strcmp(tmp1->i->path, ".") == 0)
//   {
//     ft_putstr(tmp1->i->name);
//     NL;
//     tmp1 = tmp1->next;
//   }
//   NL;
//   tmp3 = tmp1;
//   tmp1 = *list;
//   while (ft_strcmp(tmp1->i->path, ".") == 0)
//   {
//     tmp2 = tmp3;
//     if (tmp1->i->droits[0] == 'd')
//     {
//       printf("%s\n", tmp1->i->name);
//       printf("--------\n");
//       while (tmp2 && tmp1 && ft_strcmp(tmp2->i->name, tmp1->i->name) != 0)
//       {
//         printf("%s\n", tmp2->i->name);
//         tmp2 = tmp2->next;
//       }
//     }
//     tmp1 = tmp1->next;
//   }
// }

void print_ls_R(t_llist **list)
{
  t_llist *tmp;
  tmp = *list;
  int bol;
  int bol2;

  bol2 = 0;
  bol = 1;
  while (tmp)
  {
    if (bol && bol2)
    {
      ft_putstr(tmp->i->path);
      ft_putchar(':');
      NL;
    }
    ft_putstr(tmp->i->name);
    if (tmp->next != NULL && (ft_strcmp(tmp->i->path, tmp->next->i->path) == 0))
      bol = 0;
    else
    {
      bol2 = 1;
      bol = 1;
      NL;
    }
    NL;
    tmp = tmp->next;
  }
}

void print(t_llist **list, t_parse *p, t_struct *s)
{
  t_llist *tmp;
  tmp = *list;

  int i = 0;
  printf("l %d, R %d, a %d, r %d, t %d\n", p->l, p->R, p->a, p->r, p->t);
  if (!p->l && p->R && !p->a && !p->r)
      print_ls_R(list);
  else
  {
    while (tmp != NULL)
    {
      if (!p->l && !p->R && !p->a && !p->r)
        print_ls(tmp->i);
      else if (p->l && !p->R && !p->a && !p->r)
        print_ls_l(tmp->i, s);
      tmp = tmp->next;
    }
  }
}

int main(int ac, char **av)
{
  t_llist *l;
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
  if (!p.R)
  {
    if ((s->rep = opendir("./")) != NULL)
      stock(&l, s, &p);
  }
  else
    stock_R(&l, &p, ".");
  print(&l, &p, s);
}
