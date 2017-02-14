#include "lem_in.h"

t_box *ft_select_box(char *name, t_box **boxes)
{
        t_box *selected_box;
        t_box *first_box;
        first_box = *boxes;

        while ((*boxes))
        {
                if (ft_strcmp((*boxes)->name, name) == 0)
                {
                        selected_box = *boxes;
                        // printf("selected box: %s\n", (selected_box)->name);
                }
                *boxes = (*boxes)->next;
        }
        *boxes = first_box;
        return(selected_box);
}


size_t ft_add_link(t_box **current_box, t_box **box_to_link)
{
        t_link *new_link;
        t_link *first_link;

        if (!(new_link = (t_link *)malloc(sizeof(t_link))))
                return (1);
        new_link->name = (*box_to_link)->name;
        if ((*current_box)->links == NULL)
        {
                (*current_box)->links = new_link;
                // printf("current_box %s\n", (*current_box)->name);
                return(0);
        }
        else
        {
                first_link = (*current_box)->links;
                while((*current_box)->links->next)
                        (*current_box)->links = (*current_box)->links->next;
                // printf("add_link %s\n", new_link->box->name);
                (*current_box)->links->next = new_link;
                (*current_box)->links = first_link;
        }
        return(0);
}



size_t  ft_tagline(char **line, t_inf **inf, t_box **box)
{
        char  *str;
        char  *pos;

        pos = ft_strdup(line[0]);
        if ((ft_strcmp(pos, "##start") == 0 || ft_strcmp(pos, "##end") == 0 )
            && get_next_line(0, &str) > 0)
        {
                line = ft_strsplit(str, ' ');
                if (ft_strtab(line) != 3 || line[0][0] == 'L')
                        return (1);
                if (ft_strcmp(pos, "##start") == 0)
                {
                        // printf("tagline %s\n", line[0]);
                        if (ft_push_box(inf, box, line[0], "start"))
                                return(1);
                }
                else if (ft_push_box(inf, box, line[0], "end"))
                        return(1);
        }
        return (0);
}

size_t ft_push_box(t_inf  **inf, t_box **box, char *name, char *pos)
{
        t_box *first;
        t_box *new_box;

        if (!(new_box = (t_box *)malloc(sizeof(t_box))))
                return (1);
        first = *box;
        new_box->name = ft_strdup(name);
        new_box->next = NULL;
        if (!ft_strcmp(pos, "start"))
                (*inf)->start = name;
        else if(!ft_strcmp(pos, "end"))
                (*inf)->end = name;
        if (*box == NULL)
                (*box) = new_box;
        else
        {
                while ((*box)->next)
                        (*box) = (*box)->next;
                (*box)->next = new_box;
                (*box) = first;
        }
        // printf("push box->name: %s\n", new_box->name);
        return (0);
}

size_t ft_pipe(char **line, t_inf **inf, t_box **box)
{
        t_link  *new_link;
        t_box *current_box;
        t_box *box_to_link;

        if (!(new_link = (t_link *)malloc(sizeof(t_link))))
                return(1);
        if (ft_strtab(line) == 2)
        {
                if (!(current_box = ft_select_box(line[0], box)) || !(box_to_link = ft_select_box(line[1], box)))
                        return(1);
                if (ft_add_link(&current_box, &box_to_link))
                        return(1);
                return (0);
        }
        return(1);
}
