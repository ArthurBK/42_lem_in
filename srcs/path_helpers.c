/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 09:26:09 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/23 14:36:47 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ft_sorted_insert(t_path **head, size_t length, t_path *new_path)
{
	t_path	*prev;
	t_path	*elem;
	int		added;

	added = 0;
	elem = *head;
	if (elem->length > length)
	{
		added = 1;
		new_path->next = *head;
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
	!added ? elem->next = new_path : 0;
}

void		ft_add_path(t_path **head, t_link *to_add)
{
	t_path	*new_path;
	t_link	*fresh_link;
	t_link	*to_free;
	size_t	length;

	fresh_link = NULL;
	length = ft_path_size(to_add) - 1;
	while (to_add)
	{
		fresh_link = ft_add_link(fresh_link, ft_new_way(to_add->box));
		to_add = to_add->next;
	}
	new_path = ft_new_path(fresh_link, length);
	if (*head == NULL)
		*head = new_path;
	else
	{
		ft_sorted_insert(head, ft_path_size(to_add) - 1, new_path);
	}
}

char		**ft_skip_comments(void)
{
	char	*str;
	char	**line2;

	while (get_next_line(0, &str) > 0)
	{
		line2 = ft_strsplit(str, ' ');
		if (ft_tabl(line2) > 0 && line2[0][0] == '#' && ft_is_comment(line2))
		{
			free_lines(line2);
			free(str);
			continue ;
		}
		else
			break ;
	}
	free(str);
	return (line2);
}
