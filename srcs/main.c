/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 14:44:36 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/06 13:14:27 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int ft_isnumber(char *str)
{
	while (*str)
		if (ft_isdigit(*str++) == 0)
			return(0) ;
	return (1);
}

size_t	ft_strtab(char **tab)
{
	size_t i;

  i = 0;
	while(tab[i])
		i++;
	return (i);
}

size_t	ft_tagline(char **line,	t_inf	*inf)
{
	char	*str;


	if (ft_strcmp(line[0], "##start") == 0 && get_next_line(0, &str) > 0)
	{
		line = ft_strsplit(str, ' ');
		if (ft_strtab(line) != 3 || line[0][0] == 'L')
			return (1);
		inf->start = line[0];
	}
	else if(ft_strcmp(line[0], "##end") == 0 && get_next_line(0, &str) > 0)
	{

		line = ft_strsplit(str, ' ');
		if (ft_strtab(line) != 3 || line[0][0] == 'L')
			return (1);
		inf->end = line[0];
		return (0);
	}
	return(1);
}

size_t ft_pipe(char **line,	t_inf	*inf, t_box, *box)
{
		line = ft_strsplit(str, '-');
		if (ft_strtab(line) == 2)
		{
			box->name = line[0];
			// box->link = line[0];
			// box->next = line[1];
		}
		return(1);
}

int main(void)
{
	char	*str;
	char	**line;
	char	first_line;
	t_inf	*inf;
	t_box	*box;

	inf = (t_inf *)malloc(sizeof(t_inf));
	box = (t_box *)malloc(sizeof(t_box));
	ft_bzero(inf, sizeof(*inf));
	// printf("%zu\n", sizeof(*inf));
	first_line = 0;
	while (get_next_line(0, &str) > 0)
	{
		line = ft_strsplit(str, ' ');
		if (ft_strtab(line) < 1)
			break;
		// if (line[0][0] == 'L')

		// if (ft_strrchr(line, '-'))
		if (!first_line && ft_isnumber(line[0]) && ft_strtab(line) == 1)
		{
				inf->lemmings = ft_atoi(line[0]);
				first_line = 1;
		}
			// printf("line[0]: %s\n", line[0]);
			// printf("first_line: %i\n", first_line);
			// printf("ft_strcmp(line[0], #): %i\n", line[0][0] == "#"));
		if (first_line && line[0][0] == '#')
			if (ft_tagline(line, inf))
				break;
		if (first_line && ft_strtab(line) == 1)
			if (ft_pipe(line, inf, box))
				break;
		}

	// printf("%zu\n", inf->lemmings);
	// printf("%s\n", inf->start);
	if (!inf->valid_map)
		printf("ERROR");
	return (0);
}
