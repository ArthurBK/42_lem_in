#include "lem_in.h"

void ft_find_paths(t_box **box, t_inf **inf)
{
        t_box *start;
        t_box *end;
        // t_box *first_link;
        t_box *current_box;
        t_path *new_path;
        // t_path *paths;

        start = ft_find_box(box, (*inf)->start);
        end = ft_find_box(box, (*inf)->end);
        new_path = (t_path *)malloc(sizeof(t_path));
              // printf("first %s\n", start->name);
        ft_eval_path(start, end, &new_path, box);
        //
        // while (new_path->path)
        // {
        //     // printf("%s\n", new_path->path->box->name);
        //     new_path->path= new_path->path->next;
        // }
        if (!(*inf)->valid_map)
                printf("ERROR");
}
//
// typedef struct  s_box {
//   char         *name;
//   struct s_link *links;
//   struct s_box *next;
//   int     weight;
// }               t_box;
//
// typedef struct  s_link {
//   struct s_box *box;
//   struct s_link *next;
// }               t_link;
//
// typedef struct  s_path {
//   int length;
//   struct s_link *path;
//   struct s_path *next;
// }               t_path;

void ft_eval_path(t_box *current_box, t_box *end, t_path **current_path, t_box **boxes)
{
    t_box *next_box;
    t_link *begin_path;
    if (current_box == end)
    {

      // begin_path = (*current_path)->path;
      // while ((*current_path)->path)
      // {
      //   // printf("%s\n", next_box->name);
      //   (*current_path)->path =  (*current_path)->path->next;
      // }
      // (*current_path)->path = (t_link *)malloc(sizeof(t_link));
      // (*current_path)->path->box = end;
      // (*current_path)->length +=  1;
      // (*current_path)->path = begin_path;
      //   while ((*current_path)->path)
      //   {
      //       printf("%s\n", (*current_path)->path->box->name);
      //       (*current_path)->path = (*current_path)->path->next;
      //   }
        return;
    }
    while (current_box->links)
    {
        next_box = ft_find_box(boxes, current_box->links->box->name);
        // printf("current_box%s \n", current_box->name);
        // printf("next_box %s \n", next_box->name);
        if ((*current_path)->path == NULL)
          {
            (*current_path)->path = (t_link *)malloc(sizeof(t_link));
            (*current_path)->length = 0;
            (*current_path)->path->box = current_box;
          }
        else
        {
            begin_path = (*current_path)->path;
            while ((*current_path)->path)
            {
              printf("%s\n", next_box->name);
              (*current_path)->path =  (*current_path)->path->next;
            }
            // (*current_path)->path = (t_link *)malloc(sizeof(t_link));
            // // write(1,"yo",2);
            // (*current_path)->path->box = next_box;
            // // (*current_path)->path = (*current_path)->path->next;
            // (*current_path)->length +=  1;
            // (*current_path)->path = begin_path;
            // printf("length %i \n", (*current_path)->length);
        }
        current_box->links = current_box->links->next;
        ft_eval_path(next_box, end, current_path, boxes);
    }
    return;
}
