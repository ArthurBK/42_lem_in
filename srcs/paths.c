#include "lem_in.h"

void ft_find_paths(t_box **box, t_inf **inf)
{
        t_box *start;
        t_box *end;
        t_link *new_way;
        t_path *paths;

        start = ft_find_box(box, (*inf)->start);
        end = ft_find_box(box, (*inf)->end);
        paths = ft_new_path(NULL, 0);
        new_way = ft_new_way(start);
        paths = ft_eval_path(paths, new_way, start, end, 0);

        while (paths)
        {
            printf("NEW PATH\t");
            printf("LENGTH %d\n", paths->length);
            while (paths->path)
            {
              // hex_dump(paths->path, sizeof(paths->path));
              printf("BOX: %s\n", paths->path->box->name);
              paths->path = paths->path->next;
            }
            paths = paths->next;
        }
        if (!(*inf)->valid_map)
                printf("ERROR");
}

// HEAD = LISTE DE PATH // CUR = LIST DE BOX POUR LE PATH COURANT
t_path *ft_eval_path(t_path *paths, t_link *new_way, t_box *current_box, t_box *end, int k)
{

  t_link *links = current_box->links;
  t_link *cpy_way;

  printf("k = %d\t", k);
  printf("current_box: %s\n", current_box->name);
  if (current_box == end)
  {
    write(1, "end\n", 4);
    // ft_reset_visits(new_way);
    ft_add_path(&paths, new_way);
    // free(new_way);
    return (paths);
  }
  while (links) {
    if (!links->box->visited)
    {
      cpy_way = ft_add_and_cpy_link(new_way, links->box);
      current_box->visited = 1;
      ft_eval_path(paths, cpy_way, links->box, end, k + 1);
      current_box->visited = 0;

    }
    links = links->next;
  }
  return (paths);
}
