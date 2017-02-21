#include "lem_in.h"

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
		// printf("name: %s\n", (*box)->name);
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

t_path	*ft_new_path(t_link *path, size_t length)
{

	t_path *new_path;

	if (!(new_path = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	new_path->path = path;
	new_path->length = length;
	new_path->next = NULL;
	return (new_path);
}

t_ant	*ft_new_ant(t_link *current_box, int ant_id)
{

	t_ant *new_ant;

	if (!(new_ant = (t_ant *)malloc(sizeof(t_ant))))
		return (NULL);
	new_ant->ant_id = ant_id;
	new_ant->current_box = current_box;
	new_ant->next = NULL;
	return (new_ant);
}

t_box *ft_new_box(char *name, int visited, t_link *links)
{

	t_box *new_box;

	if (!(new_box = (t_box *)malloc(sizeof(t_box))))
		return (NULL);
	new_box->name = ft_strdup(name);
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


void ft_add_ant(t_ant **head, t_ant *to_add)
{
	t_ant *elem;

	elem = *head;
	if (*head == NULL)
		(*head) = to_add;
	else
	{

		while (elem->next)
			elem = elem->next;
		elem->next = to_add;
	}
}

void ft_add_path(t_path **head, t_link *to_add)
{
	t_path *elem;
	t_path *new_path;
	t_path *prev;
	t_link *fresh_link = NULL;
	t_link *to_free;
	int added;
	size_t length;

	added = 0;
	length = ft_path_size(to_add) - 1;
	while (to_add)
	{
			ft_add_link(&fresh_link, ft_new_way(to_add->box));
			to_add = to_add->next;
	}
	// free(to_add);
	new_path = ft_new_path(fresh_link, length);
	elem = *head;
	if (*head == NULL)
		*head = new_path;
	else
	{
		if (elem->length > length)
		{
			added = 1;
			new_path->next = *head;
			*head = new_path;
		}
		while (elem->next && !added)
		{

			prev = elem;
			elem = elem->next;
			if (elem->length > length)
			{
				added = 1;
				prev->next = new_path;
				new_path->next = elem;
				break;
			}
		}
		if (!added)
			elem->next = new_path;
	}
	// sleep(3);
}


void ft_add_link(t_link **head, t_link *to_add)
{
	t_link *elem;

	elem = *head;
	if (elem == NULL)
		*head = to_add;
	else
	{
		while (elem->next)
		{
			if (elem->next == to_add)
				break;
			elem = elem->next;
		}
		elem->next = to_add;
	}
}

t_link *ft_add_and_cpy_link(t_link *head, t_box *to_add)
{
	t_link *new_link;
	t_link *new_head;
	// t_link *tmp;

	new_head = NULL;
	// tmp = NULL;
	while (head)
	{
		if (!(new_link = ft_new_way(head->box)))
			return (NULL);
		ft_add_link(&new_head, new_link);
		// tmp = head;
		head = head->next;
		// free(head);
	}
	// free(tmp);
	if (!(new_link = ft_new_way(to_add)))
		return (NULL);
	ft_add_link(&new_head, new_link);
	return (new_head);
}
