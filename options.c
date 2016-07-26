#include "header.h"

void ls_l(t_llist *list, t_struct *s)
{
    printf("date : %d ", list->date2);
    printf("name : %s\n", list->name);
    ft_putstr(list->droits);
    SPACE;
    ft_putnbr(list->nlink);
    SPACE;
    ft_putstr(s->usr->pw_name);
    SPACE;
    ft_putstr(s->grp->gr_name);
    SPACE;
    ft_putnbr(list->size);
    SPACE;
    ft_putstr(list->date);
    SPACE;
    ft_putstr(list->name);
    NL;
}

void ls(t_llist *list, t_struct *s)
{
  ft_putstr(list->name);
  NL;
}
