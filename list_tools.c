#include "header.h"

void swap_string(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap_info(t_llist *elem1, t_llist *elem2)
{
	t_llist *tmp;
	swap_int(&elem1->size, &elem2->size);
	swap_int(&elem1->nlink,&elem2->nlink);
	swap_string(&elem1->name, &elem2->name);
	swap_string(&elem1->date, &elem2->date);
}

void trie_list(t_llist *list, t_struct *s)
{
	t_llist *tmp;
	int etat;

	etat = 1;
	while (etat != 0)
	{
		tmp = list;
		while (tmp->next != NULL)
		{
			if ((tmp->next->date2) > (tmp->date2))
			{
				swap_info(tmp, tmp->next);
				etat += 1;
				tmp = tmp->next;
			}
			else
				tmp = tmp->next;
		}
		etat = 0;
	}
}

void choose_opt(t_llist *list, t_struct *s, t_parse *p)
{
	if (list->name[0] != '.' && p->l)
		ls_l(list, s);
	else if (p->l && p->a)
		ls_l(list, s);
	else if (list->name[0] != '.' && !p->a && !p->l && !p->R && !p->r && !p->t)
		ls(list, s);
	else if (p->a && (!p->l && !p->R && !p->r && !p->t))
		ls(list, s);
}

void print_list(t_llist *list, t_struct *s, t_parse *p)
{
	if (p->l)
	{
		ft_putstr("total ");
		ft_putnbr(s->block);
		NL;
	}
	 while(list)
	 {
		 choose_opt(list, s, p);
		 list = list->next;
	 }
}

void		ft_push_back_t(t_llist **llist, t_struct *s)
{
	t_llist	*tmp;

	tmp = *llist;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_link(s);
	}
	else
		*llist = add_link(s);
}

t_llist *add_link(t_struct *s)
{
	t_llist *tmp;

	tmp = malloc(sizeof(t_llist));
	if (tmp)
	{
		stock_rights(s, tmp);
		stock_time(s->sb.st_mtime, tmp);
		tmp->name = ft_strdup(s->readenfile->d_name);
		tmp->nlink = (int)s->sb.st_nlink;
		tmp->size = (int)s->sb.st_size;
		tmp->folder = ft_strdup((const char*)s->rep);
		tmp->date2 = (int)s->sb.st_mtime;
		tmp->next = NULL;
	}
	return(tmp);
}
