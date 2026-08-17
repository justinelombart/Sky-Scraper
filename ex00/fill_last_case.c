/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_last_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesfoug <cdesfoug@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 10:40:01 by cdesfoug          #+#    #+#             */
/*   Updated: 2026/08/16 18:49:51 by jlombart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

int	add_nbr(t_conditions *conds, int idx, int pos, int nbr);

int	fill_last(t_conditions *conds, int idx);

void	fill_all_last(t_conditions *conditions)
{
	int	i;
	int	changed;

	changed = 1;
	while (changed)
	{
		changed = 0;
		i = 0;
		while (i < 8)
		{
			if (fill_last(conditions, i))
				changed++;
			i++;
		}
	}
}

int	fill_last(t_conditions *conds, int idx)
{
	int	i;
	int	count;
	int	sum;
	int	last;

	i = 0;
	count = 0;
	sum = 0;
	while (i < 4)
	{
		sum += *(conds[idx].values[i]);
		if (!*(conds[idx].values[i]))
		{
			last = i;
			count++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	add_nbr(conds, idx, last, 10 - sum);
	return (1);
}
/*
#include <stdio.h>
#include "create_map.c"
#include "free_all.c"
#include "process_input.c"
#include "input_error.c"
#include "prefill_map.c"
int main(int argc, char **argv)
{
     int **map = create_map();
     t_conditions *tab = process_input(map, argv + 1, argc - 1);
     prefill_map(map, tab);
	printf("Result : %d\n", fill_all_last(tab));
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
