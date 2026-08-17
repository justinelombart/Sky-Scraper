/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesfoug <cdesfoug@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 14:57:20 by cdesfoug          #+#    #+#             */
/*   Updated: 2026/08/16 19:28:50 by jlombart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"
#include <stdio.h>

int		add_nbr(t_conditions *conds, int idx, int pos, int nbr);

void	rmv_nbr(t_conditions *conditions, int index, int position);

int		try_fill_next(t_conditions *conds, int idx, int pos);

int	fill_next(t_conditions *conds)
{
	int	idx;
	int	pos;
	int	finished;

	idx = -1;
	finished = 1;
	while (++idx < 4)
	{
		pos = -1;
		while (++pos < 4)
		{
			if (!*(conds[idx].values[pos]))
			{
				finished = 0;
				if (try_fill_next(conds, idx, pos))
					return (1);
			}
		}
	}
	return (finished);
}

int	try_fill_next(t_conditions *conds, int idx, int pos)
{
	int	nbr;

	nbr = 0;
	while (++nbr < 5)
	{
		if (add_nbr(conds, idx, pos, nbr))
		{
			if (fill_next(conds))
				return (1);
			else
				rmv_nbr(conds, idx, pos);
		}
	}
	return (0);
}
/*#include <stdio.h>
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
	printf("Result : %d\n", fill_next(tab));
     for  (int i = 0; i < 4; i++)
          {
                  for (int j = 0; j < 4; j++)
                  {
                          printf("%d ", map[i][j]);
                  }
                  printf("\n");
          }
     printf("\n");
}*/
