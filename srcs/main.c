/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 14:44:36 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/22 11:34:33 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


int	ft_parse(t_inf *inf, t_box **box, t_path **paths)
{
	char	first_line;
	char	*str;
	char	**line;

	while (get_next_line(0, &str) > 0)
	{
		line = ft_strsplit(str, ' ');
		if (first_line && ft_strtab(line) > 0 && line[0][0] == '#' && ft_tagline(line, &inf, box))
				return (1);
		else if (first_line && ft_strtab(line) == 3 && ft_push_box(&inf, box, line[0], "box"))
				return (1);
		if (first_line && ft_strtab(line) == 1 && line[0][0] != '#')
		{
			free_lines(line);
			line = ft_strsplit(str, '-');
			if (ft_pipe(line, &inf, box))
				break ;
		}
		if (!first_line && ft_isnumber(line[0]) && ft_strtab(line) == 1)
		{
			inf->lemmings = ft_atoi(line[0]);
			first_line = 1;
		}
		free_lines(line);
		free(str);
	}
	free(str);
	return(0);
}

int		main(void)
{
	// char	*str;
	// int		ret;
	t_inf	*inf;
	t_box	*box;
	t_path	*paths;

	box = NULL;
	paths = NULL;
	// first_line = (char *)malloc(sizeof(char));
	inf = (t_inf *)malloc(sizeof(t_inf));
	ft_bzero(inf, sizeof(inf));
	// first_line = 0;
	if (ft_parse(inf, &box, &paths))
		return (0);

	paths = ft_find_paths(&box, &inf);
	ft_lem_in(&paths, &inf);
	free(inf->start);
	free(inf->end);
	free(inf);
	// printf("out of parse\n");

	sleep(7);
	return (0);
}
