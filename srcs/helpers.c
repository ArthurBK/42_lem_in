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

t_path *ft_new_path(t_link *path)
{

	t_path *new_path;

	if (!(new_path = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	new_path->path = path;
	new_path->length = 1;
	new_path->next = NULL;
	return (new_path);
}

t_link *ft_new_way(char *name)
{

	t_link *new_way;

	if (!(new_way = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	new_way->name = name;
	new_way->next = NULL;
	return (new_way);
}

void add_path(t_path **head, t_link **to_add)
{
		t_path *first;
		t_path *new_path;
		// t_link *new_way;

		new_path = ft_new_path(*to_add);
		first = *head;
		while ((*head)->next)
			*head = (*head)->next;
		(*head)->next = new_path;
		*head = first;
}
