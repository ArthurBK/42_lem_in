/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 09:26:33 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/22 09:26:34 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*ft_new_ant(t_link *current_box, int ant_id)
{
	t_ant *new_ant;

	if (!(new_ant = (t_ant *)malloc(sizeof(t_ant))))
		return (NULL);
	new_ant->ant_id = ant_id;
	new_ant->current_box = current_box;
	new_ant->next = NULL;
	return (new_ant);
}

t_box	*ft_new_box(char *name, int visited, t_link *links)
{
	t_box *new_box;

	if (!(new_box = (t_box *)malloc(sizeof(t_box))))
		return (NULL);
	new_box->name = ft_strdup(name);
	new_box->links = links;
	new_box->visited = visited;
	new_box->next = NULL;
	return (new_box);
}

t_link	*ft_new_way(t_box *box)
{
	t_link *new_way;

	if (!(new_way = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	new_way->box = box;
	new_way->next = NULL;
	return (new_way);
}

void	ft_add_ant(t_ant **head, t_ant *to_add)
{
	t_ant *elem;

	elem = *head;
	if (*head == NULL)
		(*head) = to_add;
	else
	{
		while (elem->next)
			elem = elem->next;
		elem->next = to_add;
	}
}

void	ft_add_link(t_link **head, t_link *to_add)
{
	t_link *elem;

	elem = *head;
	if (elem == NULL)
		*head = to_add;
	else
	{
		while (elem->next)
		{
			if (elem->next == to_add)
				break ;
			elem = elem->next;
		}
		elem->next = to_add;
	}
}
