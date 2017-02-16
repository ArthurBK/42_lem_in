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

size_t ft_path_size(t_link *list)
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

void ft_add_path(t_path **head, t_link *to_add)
{
								t_path *first;
								t_path *new_path;
								size_t length;

								new_path = ft_new_path(to_add, ft_path_size(to_add) - 1);
								length = ft_path_size(to_add);
								first = *head;
								if ((*head)->path == NULL)
									{
										(*head)->length = ft_path_size(to_add) - 1;
										(*head)->path = to_add;
									}
								else
								{
								while ((*head)->next)
																*head = (*head)->next;
								// (*head)->length = length;
								(*head)->next = new_path;
								}
								*head = first;
}


void ft_add_link(t_link **head, t_link *to_add)
{
								t_link *first;

								first = *head;
								if ((*head)->box == NULL)
									(*head)->box = to_add->box;
								else
								{

								while ((*head)->next)
								{
																if ((*head)->next == to_add)
																								break;
																*head = (*head)->next;
								}
								(*head)->next = to_add;
								}
								*head = first;
}


t_link *ft_add_and_cpy_link(t_link *head, t_box *to_add)
{
								t_link *new_link;
								t_link *new_head;

								if (!(new_head = ft_new_way(NULL)))
									return (NULL);
								while (head)
								{
										if (!(new_link = ft_new_way(head->box)))
											return (NULL);
										ft_add_link(&new_head, new_link);
										head = head->next;
								}
								if (!(new_link = ft_new_way(to_add)))
										return (NULL);
								ft_add_link(&new_head, new_link);
								return (new_head);
}
