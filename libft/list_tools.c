void		ft_push_back_and_tri(t_list **list, t_info *i, size_t content_size)
{
	t_list	*tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(i, content_size);
	}
	else
		*list = ft_create_elem(i, content_size);
}
