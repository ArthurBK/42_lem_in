/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 14:44:36 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/22 13:25:13 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_is_comment(char **line)
{
	if ((ft_strcmp(line[0], "##start") == 0 || ft_strcmp(line[0], "##end") == 0)
	&& ft_strtab(line) == 1)
			return (0);
	return (1);
}

int			ft_parse(t_inf *inf, t_box **box, t_path **paths)
{
	char	f_l;
	char	*str;
	char	**l;

	while (get_next_line(0, &str) > 0)
	{
		l = ft_strsplit(str, ' ');
		if (l[0][0] == '#' && ft_is_comment(l))
		{
			free_lines(l);
			free(str);
			continue ;
		}
		if (l[0][0] != '#' && ft_strtab(l) > 3)
		{
				free_lines(l);
				// free(str);
				break ;
		}
		if (f_l && ft_strtab(l) > 0 && l[0][0] == '#' && ft_tagline(l, &inf, box))
			return (0);
		else if (f_l && ft_strtab(l) == 3 && ft_push_box(&inf, box, l[0], "box"))
			return (1);
		if (f_l && ft_strtab(l) == 1 && l[0][0] != '#')
		{
			free_lines(l);
			if (ft_pipe(l = ft_strsplit(str, '-'), &inf, box))
				break ;
		}
		if (!f_l && ft_isnumber(l[0]) && ft_strtab(l) == 1
				&& (inf->lemmings = ft_atoi(l[0])))
			f_l = 1;
		free_lines(l);
		free(str);
	}
	free(str);
	return (0);
}

int		main(void)
{
	t_inf	*inf;
	t_box	*box;
	t_path	*paths;

	box = NULL;
	paths = NULL;
	// inf = NULL
	inf = (t_inf *)malloc(sizeof(t_inf));
	ft_bzero(inf, sizeof(t_inf));

	if (ft_parse(inf, &box, &paths))
		return (1);
		// sleep(5);
	if (ft_strlen(inf->start) && ft_strlen(inf->end) && inf->lemmings > 0)
	{
			paths = ft_find_paths(&box, &inf);
			if (inf->valid_map)
			{
				ft_lem_in(&paths, &inf);
				free(inf->start);
				free(inf->end);
			}
			else
				ft_putstr("ERROR\n");
	}
	else
		ft_putstr("ERROR\n");
	free(inf);
	return (0);
}
