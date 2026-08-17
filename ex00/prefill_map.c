/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesfoug <cdesfoug@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:26:33 by cdesfoug          #+#    #+#             */
/*   Updated: 2026/08/16 18:30:09 by cdesfoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "conditions.h"

int		add_nbr(t_conditions *conds, int idx, int pos, int nbr);

void	put_start_info(t_conditions *conds, int i);

void	fill_4(t_conditions *conds, int index, int pos, int sens);

void	prefill_map(int **map, t_conditions *conditions)
{
	int	i;
	int	**column;

	i = 0;
	while (i < 8)
	{
		put_start_info(conditions, i);
		i++;
	}
}

void	fill_4(t_conditions *conds, int index, int pos, int sens)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		add_nbr(conds, index, pos, i);
		pos += sens;
		i++;
	}
}

void	put_start_info(t_conditions *conds, int i)
{
	if (conds[i].left_view == 4)
		fill_4(conds, i, 0, 1);
	else if (conds[i].right_view == 4)
		fill_4(conds, i, 3, -1);
	else if (conds[i].left_view == 1)
	{
		add_nbr(conds, i, 0, 4);
		if (conds[i].right_view == 2)
			add_nbr(conds, i, 3, 3);
	}
	else if (conds[i].right_view == 1)
	{
		add_nbr(conds, i, 3, 4);
		if (conds[i].left_view == 2)
			add_nbr(conds, i, 0, 3);
	}
	else if (conds[i].left_view == 2 && conds[i].right_view == 3)
		add_nbr(conds, i, 1, 4);
	else if (conds[i].right_view == 2 && conds[i].left_view == 3)
		add_nbr(conds, i, 2, 4);
}
/*
#include <stdio.h>
#include "create_map.c"
#include "free_all.c"
#include "process_input.c"
#include "input_error.c"
int main(int argc, char **argv)
{
     int **map = create_map();
     for (int i = 0; i < 4; i++)
         {
                 for (int j = 0; j < 4; j++)
                 {
                         printf("%d ", map[i][j]);
                 }
                 printf("\n");
         }
     t_conditions *tab = process_input(map, argv + 1, argc - 1);
     prefill_map(map, tab);
     for (int i = 0; i < 4; i++)
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
