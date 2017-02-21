#include "lem_in.h"

t_path *ft_find_paths(t_box **box, t_inf **inf)
{
        t_box *start;
        t_box *end;
        t_link *new_way;
        t_path *paths;

        start = ft_find_box(box, (*inf)->start);
        end = ft_find_box(box, (*inf)->end);
        paths = NULL;
        new_way = ft_new_way(start);
        paths = ft_eval_path(paths, new_way, start, end, inf);
        // while (paths)
        // {
        // //     // printf("NEW PATH\t");
        // //     // printf("LENGTH %zu\n", paths->length);
        //     while (paths->path)
        //     {
        // //       // hex_dump(paths->path, sizeof(paths->path));
        // //       // printf("ADDRESS %p\t", paths->path->box->name);
        // //       printf("%s\t ", paths->path->box->name);
        // //       // printf("length: %zu ", paths->length);
        //       free(paths->path);
        //       paths->path = paths->path->next;
        //     }
        // //     printf("\n");
        //     paths = paths->next;
        // }
        if (paths != NULL)
            (*inf)->valid_map = 1;
        free(new_way);
        // printf("LEAKS?\n");
        // sleep(5);
        return (paths);
}

// HEAD = LISTE DE PATH // CUR = LIST DE BOX POUR LE PATH COURANT
t_path *ft_eval_path(t_path *paths, t_link *new_way, t_box *current_box, t_box *end, t_inf **inf)
{

  t_link *links = current_box->links;
  t_link *cpy_way;
  t_link *tmp;

  if (current_box == end)
  {
    // free(new_way);
    // printf("yo\n");
    ft_add_path(&paths, new_way);
    // printf("noleaks\n");
    // sleep(1);
    return (paths);
  }
  while (links) {
    if (!links->box->visited)
    {
      tmp = ft_new_way(links->box);
      ft_add_link(&new_way, tmp);
      current_box->visited = 1;
      paths = ft_eval_path(paths, new_way, links->box, end, inf);
      free(tmp);
      // paths = ft_eval_path(paths, cpy_way, links->box, end, inf);
      // free(cpy_way);
      current_box->visited = 0;
    }
    links = links->next;
  }

  // sleep(3);
  return (paths);
}
