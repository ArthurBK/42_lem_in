/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 14:44:36 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/23 15:49:42 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_is_comment(char **line)
{
	if ((ft_strcmp(line[0], "##start") == 0 || ft_strcmp(line[0], "##end") == 0)
			&& ft_tabl(line) == 1)
		return (0);
	return (1);
}

int			ft_error_coor(char *str, char **lines)
{
	free_lines(lines);
	free(str);
	return (1);
}

int			ft_pipe_error(char **l, char *str, t_box **box)
{
	if (ft_pipe(l = ft_strsplit(str, '-'), box))
	{
		free_lines(l);
		return (1);
	}
	free_lines(l);
	return (0);
}

int			ft_parse(t_inf *inf, t_box **box)
{
	char	f_l;
	char	*str;
	char	**l;

	f_l = 0;
	while (get_next_line(0, &str) > 0)
	{
		l = ft_strsplit(str, ' ');
		if (f_l && ft_tabl(l) > 0 && l[0][0] == '#' && ft_tagline(l, &inf, box))
			return (0);
		else if (f_l && ft_tabl(l) == 3 && ft_push_box(&inf, box, l[0], "box"))
			return (1);
		if (f_l && ft_tabl(l) > 0 && l[0][0] != '#' && ft_tabl(l) > 3)
			return (ft_error_coor(str, l));
		if (f_l && ft_tabl(l) == 1 && l[0][0] != '#')
			if (ft_pipe_error(l, str, box) == 1)
				break ;
		if (!f_l && ft_tabl(l) > 0 && ft_isnumber(l[0]) && ft_tabl(l) == 1
				&& (inf->lemmings = ft_atoi(l[0])))
			f_l = 1;
		free_lines(l);
		free(str);
	}
	free(str);
	return (0);
}

int			main(void)
{
	t_inf	*inf;
	t_box	*box;
	t_path	*paths;

	box = NULL;
	paths = NULL;
	inf = (t_inf *)malloc(sizeof(t_inf));
	ft_bzero(inf, sizeof(t_inf));
	if (ft_parse(inf, &box) == 1)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	if (ft_strlen(inf->start) && ft_strlen(inf->end) && inf->lemmings > 0)
	{
		paths = ft_find_paths(&box, &inf);
		if (inf->valid_map)
			ft_print_sol(&paths, &inf);
		else
			ft_putstr("ERROR\n");
	}
	else
		ft_putstr("ERROR\n");
	free(inf);
	return (0);
}
