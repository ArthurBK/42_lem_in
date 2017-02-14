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




int main(void)
{
	char	*str;
	char	**line;
	char	first_line;
	t_inf	*inf;
	t_box	*box;

	inf = (t_inf *)malloc(sizeof(t_inf));
	// box = (t_box *)malloc(sizeof(t_box));
	ft_bzero(inf, sizeof(*inf));
	// ft_bzero(box, sizeof(*box));
	// printf("%zu\n", sizeof(*inf));
	first_line = 0;
	while (get_next_line(0, &str) > 0)
	{
		line = ft_strsplit(str, ' ');
		if (ft_strtab(line) < 1)
			break;
			// printf("line[0]: %s\n", line[0]);
			// printf("first_line: %i\n", first_line);
			// printf("ft_strcmp(line[0], #): %i\n", line[0][0] == "#"));
		if (first_line && line[0][0] == '#')
		{
				if (ft_tagline(line, &inf, &box))
					break;
		}
		else if (first_line && ft_strtab(line) == 3)
				if (ft_push_box(&inf, &box, line[0], "box"))
					return(1);
		if (first_line && ft_strtab(line) == 1 && line[0][0] != '#')
		{
			line = ft_strsplit(str, '-');
			if (ft_pipe(line, &inf, &box))
				break;
		}
		if (!first_line && ft_isnumber(line[0]) && ft_strtab(line) == 1)
		{
		// printf("yo");
				inf->lemmings = ft_atoi(line[0]);
				first_line = 1;
		}
		}
	// printf("%zu\n", inf->lemmings);
	while (box)
{
	printf("box->name: %s\n", box->name);

  if (box->links != NULL)
	while (box->links)
	{
		printf("link: %s\n", box->links->box->name);
		box->links = box->links->next;
	}
	box = box->next;
}
		if (!inf->valid_map)
			printf("ERROR");
	return (0);
}
