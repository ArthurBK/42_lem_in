/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:08:05 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/21 17:52:47 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
size_t		ft_path_size(t_link *list)
{
	size_t i;

	i = 0;
	while (list)
	{
		++i;
		list = list->next;
	}
	return (i);
}

size_t	ft_strtab(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_isnumber(char *str)
{
	while (*str)
		if (ft_isdigit(*str++) == 0)
			return (0);
	return (1);
}

t_box	*ft_find_box(t_box **box, char *name)
{
	t_box *match;
	t_box *first_box;

	first_box = *box;
	while ((*box))
	{
		if (ft_strcmp(name, (*box)->name) == 0)
		{
			match = *box;
			*box = first_box;
			return (match);
		}
		(*box) = (*box)->next;
	}
	return (NULL);
}
