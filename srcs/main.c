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

int main(void)
{
								char *str;
								char **line;
								char **line2;
								char first_line;
								int i;
								int ret;
								t_inf *inf;
								t_box *box;
								t_path *paths;

								box = NULL;
								// paths = NULL;
								inf = (t_inf *)malloc(sizeof(t_inf));
								ft_bzero(inf, sizeof(*inf));
								first_line = 0;
								while ((ret = get_next_line(0, &str)) > 0)
								{
																i = 0;
																line = ft_strsplit(str, ' ');
																if (ft_strtab(line) < 1)
																		break;
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
																					line2 = ft_strsplit(str, '-');
																					if (ft_pipe(line2, &inf, &box))
																								break;
																					while (line2[i])
																					{
																						free(line2[i]);
																						line2[i] = NULL;
																						++i;
																					}
																					free(line2);
																					i = 0;
																}
																if (!first_line && ft_isnumber(line[0]) && ft_strtab(line) == 1)
																{
																								inf->lemmings = ft_atoi(line[0]);
																								first_line = 1;
																}
																while (line[i])
																{
																	free(line[i]);
																	line[i] = NULL;
																	++i;
																}
																free(line);
																free(str);
								}
								paths = ft_find_paths(&box, &inf);
								// printf("leaks?\n");
								ft_lem_in(&paths, &inf);
								sleep(5);

// sleep(30);
								// while (paths)
								// {
								// 	// free(&paths->length);
								// 	while (paths->path)
								// 	{
								// 		free(paths->path);
								// 		paths->path = paths->path->next;
								// 	}
								// 		free(paths);
								// 		paths = paths->next;
								// }
								// while (box)
								// {
								// 	// printf("box->name  %s\n", box->name);
								// 		while (box->links)
								// 		{
								// 			// printf("links  %s\n", box->links->box->name);
								// 			free(box->links);
								// 			box->links = box->links->next;
								// 		}
								// 	free(box->links);
								// 	free(box->name);
								// 	box = box->next;
								// }
								free(inf->start);
								free(inf->end);
								free(inf);
								// free(box);
								// sleep(30);
								return (0);
}
