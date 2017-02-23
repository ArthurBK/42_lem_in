/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:57:14 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/22 10:21:05 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_box		*ft_select_box(char *name, t_box **boxes)
{
	t_box	*selected_box;
	t_box	*elem;

	elem = *boxes;
	while (elem)
	{
		if (ft_strcmp(elem->name, name) == 0)
			selected_box = elem;
		elem = elem->next;
	}
	return (selected_box);
}

t_box		*ft_add_box(t_box *current_box, t_box *box_to_link)
{
	t_link	*new_link;
	t_link	*elem;

	elem = current_box->links;
	if (!(new_link = ft_new_way(box_to_link)))
		return (NULL);
	if (elem == NULL)
		current_box->links = new_link;
	else
	{
		while (elem->next)
		{
			if (elem->box == box_to_link)
				return (current_box);
			elem = elem->next;
		}
		elem->next = new_link;
	}
	return (current_box);
}

size_t		ft_tagline(char **line, t_inf **inf, t_box **box)
{
	char	**line2;
	char	*pos;

	pos = line[0];
	if ((ft_strcmp(pos, "##start") == 0 || ft_strcmp(pos, "##end") == 0))
	{
		if (!(line2 = ft_skip_comments()))
			return (1);
		if (ft_tabl(line2) != 3 || line2[0][0] == 'L')
			return (1);
		if (ft_strcmp(pos, "##start") == 0)
		{
			if (ft_push_box(inf, box, line2[0], "start"))
				return (1);
		}
		else if (ft_push_box(inf, box, line2[0], "end"))
			return (1);
		free_lines(line2);
	}
	return (0);
}

size_t		ft_push_box(t_inf **inf, t_box **box, char *name, char *pos)
{
	t_box	*elem;
	t_box	*new_box;

	elem = *box;
	new_box = ft_new_box(name, 0, NULL);
	if (!ft_strcmp(pos, "start"))
		(*inf)->start = ft_strdup(name);
	else if (!ft_strcmp(pos, "end"))
		(*inf)->end = ft_strdup(name);
	if (elem == NULL)
		*box = new_box;
	else
	{
		while (elem->next)
		{
			if (ft_strcmp(elem->name, name) == 0)
				return (1);
			elem = elem->next;
		}
		if (ft_strcmp(elem->name, name) == 0)
			return (1);
		elem->next = new_box;
	}
	return (0);
}

size_t		ft_pipe(char **line, t_box **box)
{
	t_box	*current_box;
	t_box	*box_to_link;

	if (ft_tabl(line) == 2)
	{
		if (!(current_box = ft_select_box(line[0], box))
				|| !(box_to_link = ft_select_box(line[1], box)))
			return (1);
		if (!ft_add_box(current_box, box_to_link)
				|| !ft_add_box(box_to_link, current_box))
			return (1);
		return (0);
	}
	return (1);
}
