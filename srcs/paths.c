#include "lem_in.h"

void ft_find_paths(t_box **box, t_inf **inf)
{
        t_box *start;
        t_box *end;
        t_link *new_way;
        t_path *paths;
        // t_box *first_link;
        // t_path *paths;

        start = ft_find_box(box, (*inf)->start);
        end = ft_find_box(box, (*inf)->end);
        paths = (t_path *)malloc(sizeof(t_path));
  // write(1, "yo", 2);
        new_way = ft_new_way(start->name);
              // printf("first %s\n", start);
        paths = ft_eval_path(paths, new_way, start, end->name);
        // // //
        // // printf("l: %i\n", new_path->length);
        // while (new_path->path)
        // {
        //     printf("%s\n", new_path->path->name);
        //     new_path->path= new_path->path->next;
        // }
        if (!(*inf)->valid_map)
                printf("ERROR");
}

// HEAD = LISTE DE PATH // CUR = LIST DE BOX POUR LE PATH COURANT
t_path *ft_eval_path(t_path *paths, t_link *new_way, t_box *current_box, char *end)
{

  t_link *links = current_box->links;

  if (ft_strcmp(current_box->name, end) == 0)
  {
    add_path(&paths, &new_way);
    return (paths);
  }

  while (links) {

    links = links->next;
  }

  return (NULL);
}

// void ft_eval_path(t_box *current_box, t_box *end, t_path **current_path, t_box **boxes)
// {
//     // current_box->visited = 1;
//     // printf("box visited: %s\n", current_box->name);
//
//     t_box *next_box;
//     t_link *begin_path;
//     t_link *new_link;
//     //
//         if (current_box == end)
//         {
//         //   begin_path = (*current_path)->path;
//         //   while ((*current_path)->path)
//         //   {
//         //     printf("path %s \n", (*current_path)->path->name);
//         //     (*current_path)->path =  (*current_path)->path->next;
//         //   }
//             return;
//         }
//     while (current_box->links)
//     {
//         next_box = ft_find_box(boxes, current_box->links->name);
//         // if (!(next_box->visited))
//         if ((*current_path)->path == NULL)
//           {
//             (*current_path)->path = (t_link *)malloc(sizeof(t_link));
//             (*current_path)->length = 1;
//             (*current_path)->path->name = current_box->name;
//             new_link = (t_link *)malloc(sizeof(t_link));
//             new_link->name = next_box->name;
//             new_link->next = NULL;;
//             (*current_path)->path->next = new_link;
//           }
//         else
//         {
//             begin_path = (*current_path)->path;
//             while ((*current_path)->path->next)
//               (*current_path)->path =  (*current_path)->path->next;
//             new_link = (t_link *)malloc(sizeof(t_link));
//             new_link->name = next_box->name;
//             new_link->next = NULL;
//             (*current_path)->path->next = new_link;
//             (*current_path)->length +=  1;
//             (*current_path)->path = begin_path;
//
//             if (next_box == end)
//               return;
//         }
//         current_box->links = current_box->links->next;
//         // ft_eval_path(next_box, end, current_path, boxes);
//     }
//     // return;
// }
