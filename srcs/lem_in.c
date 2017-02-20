#include "lem_in.h"

void ft_lem_in(t_path **paths, t_inf **inf)
{
  int i;
  size_t count;
  t_link *elem;
  t_ant *ant;
  t_ant *ant_list;
  t_ant *ant_elem;

  i = 1;
  count = (*inf)->lemmings + (*paths)->length - 1;
  ant_list = NULL;
  elem = (*paths)->path->next;
  while (count != 0)
  {
    // printf("i: %zu\n", (*inf)->lemmings);
    if ((*inf)->lemmings != 0)
    {
      ant = ft_new_ant((*paths)->path->next, i);
      ft_add_ant(&ant_list, ant);
      elem = (*paths)->path->next;
      (*inf)->lemmings -= 1;
      ++i;
    }
    ant_elem = ant_list;
    while (ant_elem)
    {
      if (ant_elem->current_box)
      {
        printf("L%i-%s ", ant_elem->ant_id, ant_elem->current_box->box->name);
        ant_elem->current_box = ant_elem->current_box->next;
      }
      ant_elem = ant_elem->next;
    }
    printf("\n");
    --count;
  }
    while (ant_list)
    {
      free(ant_list);
      ant_list = ant_list->next;
    }
}
