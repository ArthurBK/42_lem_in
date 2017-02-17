#include "lem_in.h"

void ft_lem_in(t_path **paths, t_inf **inf)
{
  int i;
  t_link *elem;

  i = 1;

  elem = (*paths)->path->next;
  (*inf)->lemmings += 1;
  while ((*inf)->lemmings != 0)
  {
    while (elem)
    {
      printf("L%i-%s\n", i, elem->box->name);
      elem = elem->next;
    }
    elem = (*paths)->path->next;
    (*inf)->lemmings -= 1;
    ++i;
  }
}
