#include "header.h"

void		ft_push_back_t(t_llist **sl, t_info *i, int nb)
{
	t_llist *tmp;
	t_llist *csl;
	t_llist *elem;

	tmp = NULL;
	csl = *sl;
	elem = (t_llist *) malloc(sizeof(t_llist));
	if(!elem)
		exit(EXIT_FAILURE);
	elem->i = i;
	while(csl && csl->i->date2 > nb)
	{
	   	tmp = csl;
	  	csl = csl->next;
	}
	elem->next = csl;
	if(tmp)
		tmp->next = elem;
	else
		*sl = elem;
}

void		ft_push_back_n(t_llist **sl, t_info *i, char *str)
{
	t_llist *tmp;
	t_llist *csl;
	t_llist *elem;

	tmp = NULL;
	csl = *sl;
	elem = (t_llist *) malloc(sizeof(t_llist));
	if(!elem)
		exit(EXIT_FAILURE);
	elem->i = i;
	while (csl && ft_strcmp(csl->i->name, str) < 0)
	{
	    tmp = csl;
	   	csl = csl->next;
	}
	elem->next = csl;
	if (tmp)
		tmp->next = elem;
	else
		*sl = elem;
}

void		ft_push_back_R(t_llist **sl, t_info *i, char *str, char *s2)
{
	t_llist *tmp;
	t_llist *csl;
	t_llist *elem;

	tmp = NULL;
	csl = *sl;
	elem = (t_llist *) malloc(sizeof(t_llist));
	if(!elem)
		exit(EXIT_FAILURE);
	elem->i = i;
	while (csl && (ft_strcmp(csl->i->path, str) != 0))
	{
			tmp = csl;
			csl = csl->next;
	}
	 while (csl && ft_strcmp(csl->i->path, str) == 0 && ft_strcmp(csl->i->name, s2) < 0)
	 {
	 	tmp = csl;
	 	csl = csl->next;
	 }
	elem->next = csl;
	if (tmp)
		tmp->next = elem;
	else
		*sl = elem;
}

void		ft_push_back_Rt(t_llist **sl, t_info *i, char *str, int nb)
{
	t_llist *tmp;
	t_llist *csl;
	t_llist *elem;

	tmp = NULL;
	csl = *sl;
	elem = (t_llist *) malloc(sizeof(t_llist));
	if(!elem)
		exit(EXIT_FAILURE);
	elem->i = i;
	while (csl && (ft_strcmp(csl->i->path, str) != 0))
	{
			tmp = csl;
			csl = csl->next;
	}
	while (csl && ft_strcmp(csl->i->path, str) == 0 && csl->i->date2 > nb)
	{
		tmp = csl;
	 	csl = csl->next;
	}
	elem->next = csl;
	if (tmp)
		tmp->next = elem;
	else
		*sl = elem;
}
