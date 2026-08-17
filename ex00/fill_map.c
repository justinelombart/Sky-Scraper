/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesfoug <cdesfoug@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:58:30 by cdesfoug          #+#    #+#             */
/*   Updated: 2026/08/17 20:48:05 by cdesfoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

void	prefill_map(t_conditions *conditions);

void	fill_all_last(t_conditions *conditions);

int		fill_next(t_conditions *conds);

int	fill_map(t_conditions *conditions)
{
	prefill_map(conditions);
	fill_all_last(conditions);
	return (fill_next(conditions));
}
/*
#include <stdio.h>
#include "add_nbr.c"
#include "rmv_nbr.c"
#include "create_map.c"
#include "free_all.c"
#include "process_input.c"
#include "input_error.c"
#include "prefill_map.c"
#include "fill_last_case.c"
#include "fill_next.c"
int main(int argc, char **argv)
{
     int **map = create_map();
     t_conditions *tab = process_input(map, argv + 1, argc - 1);
     fill_map(map, tab);
     for  (int i = 0; i < 4; i++)
          {
                  for (int j = 0; j < 4; j++)
                  {
                          printf("%d ", map[i][j]);
                  }
                  printf("\n");
          }
     printf("\n");
}
*/
