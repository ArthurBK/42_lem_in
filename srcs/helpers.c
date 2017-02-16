#include "lem_in.h"

size_t ft_strtab(char **tab)
{
								size_t i;

								i = 0;
								while (tab[i])
																i++;
								return (i);
}

int  ft_isnumber(char *str)
{
								while (*str)
																if (ft_isdigit(*str++) == 0)
																								return (0);
								return (1);
}

t_box *ft_find_box(t_box **box, char *name)
{

								t_box *match;
								t_box *first_box;

								first_box = *box;
								while ((*box))
								{
																// printf("name: %s\n", (*box)->name);
																if(ft_strcmp(name, (*box)->name) == 0)
																{
																								match = *box;
																								*box = first_box;
																								return (match);
																}
																(*box) = (*box)->next;
								}
								return (NULL);
}

t_path *ft_new_path(t_link *path, int length)
{

								t_path *new_path;

								if (!(new_path = (t_path *)malloc(sizeof(t_path))))
																return (NULL);
								new_path->path = path;
								new_path->length = length;
								new_path->next = NULL;
								return (new_path);
}

t_box *ft_new_box(char *name, int visited, t_link *links)
{

								t_box *new_box;

								if (!(new_box = (t_box *)malloc(sizeof(t_box))))
																return (NULL);
								new_box->name = name;
								new_box->links = links;
								new_box->visited = visited;
								new_box->next = NULL;
								return (new_box);
}

t_link *ft_new_way(t_box *box)
{
								t_link *new_way;

								if (!(new_way = (t_link *)malloc(sizeof(t_link))))
																return (NULL);
								new_way->box = box;
								new_way->next = NULL;
								return (new_way);
}

void ft_add_path(t_path **head, t_link *to_add)
{
								t_path *first;
								t_path *new_path;

								new_path = ft_new_path(to_add, 1);
								first = *head;
								// write(1, "yo\n", 3);
								while ((*head)->next)
												*head = (*head)->next;
								(*head)->next = new_path;
								*head = first;
}


void ft_add_link(t_link **head, t_link *to_add)
{
								t_link *first;

								first = *head;
								while ((*head)->next)
								{
                        if ((*head)->next == to_add)
														break;
											*head = (*head)->next;
								}
								(*head)->next = to_add;
								*head = first;
}


t_link *ft_add_and_cpy_link(t_link *head, t_link *to_add)
{
								t_link *first;
								t_link *new_link;
								t_link *new_head;

								first = head;
								while (head->next)
								{
									if (!new_link = ft_new_way(new_head))
										return (NULL);
									new_head = head;
									new_head = new_head->next;
									head = head->next;
								}
								head->next = to_add;
								new_head = first;
								return (new_head);
}
