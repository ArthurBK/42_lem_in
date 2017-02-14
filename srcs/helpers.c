#include "lem_in.h"

size_t	ft_strtab(char **tab)
{
	size_t i;

  i = 0;
	while(tab[i])
		i++;
	return (i);
}



int ft_isnumber(char *str)
{
	while (*str)
		if (ft_isdigit(*str++) == 0)
			return(0) ;
	return (1);
}
