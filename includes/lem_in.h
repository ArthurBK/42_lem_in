/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 14:43:26 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/05 16:59:53 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
#define RED  "\e[91m"
#define GRN  "\e[92m"
#define YEL  "\e[93m"
#define BLU  "\e[94m"
#define MAG  "\e[95m"
#define CYN  "\e[96m"
#define WHT  "\e[37m"
#define EOC  "\e[0m"

typedef struct  s_inf {
  size_t lemmings;
  char *start;
  char *end;
  char valid_map;
}               t_inf;

typedef struct  s_box {
  char         *name;
  struct s_link *link;
  struct s_box *next;
  int     weight;
}               t_box;


typedef struct  s_link {
  struct s_box *box;
  struct s_link *next;
}               t_link;


#endif
