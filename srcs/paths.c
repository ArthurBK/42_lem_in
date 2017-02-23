/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:45:13 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/23 14:37:11 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_path		*ft_eval_path(t_path *paths,
		t_link *new_way, t_box *current_box, t_box *end)
{
	t_link	*links;

	links = current_box->links;
	if (current_box == end)
	{
		ft_add_path(&paths, new_way);
		return (paths);
	}
	while (links)
	{
		if (!links->box->visited)
		{
			new_way = ft_add_link(new_way, ft_new_way(links->box));
			current_box->visited = 1;
			paths = ft_eval_path(paths, new_way, links->box, end);
		}
		links = links->next;
	}
	return (paths);
}

t_path		*ft_find_paths(t_box **box, t_inf **inf)
{
	t_box	*start;
	t_box	*end;
	t_link	*new_way;
	t_link	*tmp;
	t_path	*paths;

	start = ft_find_box(box, (*inf)->start);
	end = ft_find_box(box, (*inf)->end);
	paths = NULL;
	new_way = ft_new_way(start);
	paths = ft_eval_path(paths, new_way, start, end);
	if (paths != NULL)
		(*inf)->valid_map = 1;
	while (new_way)
	{
		tmp = new_way;
		new_way = new_way->next;
		free(tmp);
	}
	return (paths);
}
