#include "lem_in.h"

t_path		*ft_new_path(t_link *path, size_t length)
{
	t_path	*new_path;

	if (!(new_path = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	new_path->path = path;
	new_path->length = length;
	new_path->next = NULL;
	return (new_path);
}

void		ft_add_path(t_path **head, t_link *to_add)
{
	t_path	*elem;
	t_path	*new_path;
	t_path	*prev;
	t_link	*fresh_link = NULL;
	t_link	*to_free;
	int		added;
	size_t	length;

	added = 0;
	length = ft_path_size(to_add) - 1;
	while (to_add)
	{
		ft_add_link(&fresh_link, ft_new_way(to_add->box));
		to_add = to_add->next;
	}
	new_path = ft_new_path(fresh_link, length);
	elem = *head;
	if (*head == NULL)
		*head = new_path;
	else
	{
		if (elem->length > length)
		{
			added = 1;
			new_path->next = *head;
			*head = new_path;
		}
		while (elem->next && !added)
		{
			prev = elem;
			elem = elem->next;
			if (elem->length > length)
			{
				added = 1;
				prev->next = new_path;
				new_path->next = elem;
				break ;
			}
		}
		if (!added)
			elem->next = new_path;
	}
}
