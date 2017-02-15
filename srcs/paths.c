#include "lem_in.h"

void ft_find_paths(t_box **box, t_inf **inf)
{
        t_box *start;
        t_box *end;
        t_box *current_box;
        t_path *new_path;
        // t_box *first_link;
        // t_path *paths;

        start = ft_find_box(box, (*inf)->start);
        end = ft_find_box(box, (*inf)->end);
        new_path = (t_path *)malloc(sizeof(t_path));
              // printf("first %s\n", start);
        // ft_eval_path(start, end, &new_path, box);
        //
        // while (new_path->path)
        // {
        //     printf("%s\n", new_path->path->name);
        //     new_path->path= new_path->path->next;
        // }
        if (!(*inf)->valid_map)
                printf("ERROR");
}

void ft_eval_path(t_box *current_box, t_box *end, t_path **current_path, t_box **boxes)
{
    t_box *next_box;
    t_link *begin_path;
    t_link *new_link;
    //
        if (current_box == end)
        {
          // begin_path = (*current_path)->path;
          // while ((*current_path)->path)
          // {
          //   printf("path %s \n", (*current_path)->path->name);
          //   (*current_path)->path =  (*current_path)->path->next;
          // }
            return;
        }
    while (current_box->links)
    {
        // next_box = ft_find_box(boxes, current_box->links->name);
        // if ((*current_path)->path == NULL)
        //   {
        //     // (*current_path)->path = (t_link *)malloc(sizeof(t_link));
        //     // (*current_path)->length = 0;
        //     // (*current_path)->path->name = current_box->name;
        //     // new_link = (t_link *)malloc(sizeof(t_link));
        //     // new_link->name = next_box->name;
        //     // (*current_path)->path->next = new_link;
        //   }
        // else
        // {
        //     // begin_path = (*current_path)->path;
        //     // while ((*current_path)->path->next)
        //     //   (*current_path)->path =  (*current_path)->path->next;
        //     // new_link = (t_link *)malloc(sizeof(t_link));
        //     // new_link->name = next_box->name;
        //     // (*current_path)->path->next = new_link;
        //     // (*current_path)->length +=  1;
        //     // (*current_path)->path = begin_path;
        // }
        current_box->links = current_box->links->next;
        // if ()
        // ft_eval_path(next_box, end, current_path, boxes);
    }
    // return;
}
