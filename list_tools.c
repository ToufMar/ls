#include "header.h"

void print_list(t_llist *list)
{
	 while(list)
	 {
		 printf("x : %d\n", list->size);
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
//    stat(s->readenfile->d_name, &s->sb);
		tmp->size = (int)s->sb.st_size;
		tmp->next = NULL;
	}
	return(tmp);
}
