/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:06:59 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/22 10:15:15 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_ants(t_ant *ant_list)
{
	t_ant	*tmp;

	while (ant_list)
	{
		tmp = ant_list;
		ant_list = ant_list->next;
		free(tmp);
	}
}

void		print_ants(t_ant *ant_elem)
{
	while (ant_elem)
	{
		if (ant_elem->current_box)
		{
			ft_putstr("L");
			ft_putnbr(ant_elem->ant_id);
			ft_putstr("-");
			ft_putstr(ant_elem->current_box->box->name);
			ft_putstr(" ");
			ant_elem->current_box = ant_elem->current_box->next;
		}
		ant_elem = ant_elem->next;
	}
	printf("\n");
}

void		ft_lem_in(t_path **paths, t_inf **inf)
{
	int		i;
	size_t	count;
	t_link	*elem;
	t_ant	*ant;
	t_ant	*ant_list;

	i = 1;
	count = (*inf)->lemmings + (*paths)->length - 1;
	ant_list = NULL;
	elem = (*paths)->path->next;
	while (count != 0)
	{
		if ((*inf)->lemmings != 0)
		{
			ant = ft_new_ant((*paths)->path->next, i);
			ft_add_ant(&ant_list, ant);
			elem = (*paths)->path->next;
			(*inf)->lemmings -= 1;
			++i;
		}
		print_ants(ant_list);
		--count;
	}
	free_ants(ant_list);
}
