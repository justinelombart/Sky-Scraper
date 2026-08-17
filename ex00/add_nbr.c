/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesfoug <cdesfoug@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 12:57:46 by cdesfoug          #+#    #+#             */
/*   Updated: 2026/08/16 17:23:46 by cdesfoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

void	rmv_nbr(t_conditions *conditions, int index, int position);

int		vrfy_vw(int **values, int view, int unknown, int pos, int sens);

int		verify_both_views(t_conditions *conds, int idx);

int	add_nbr(t_conditions *conds, int idx, int pos, int nbr)
{
	int	comp_idx;

	if (idx < 4)
		comp_idx = pos + 4;
	else
		comp_idx = pos;
	if (conds[idx].seen[nbr] || conds[comp_idx].seen[nbr])
	{
		return (0);
	}
	conds[idx].seen[nbr] = 1;
	conds[comp_idx].seen[nbr] = 1;
	*(conds[idx].values[pos]) = nbr;
	if (!verify_both_views(conds, idx) || !verify_both_views(conds, comp_idx))
	{
		rmv_nbr(conds, idx, pos);
		return (0);
	}
	return (1);
}

int	verify_both_views(t_conditions *conds, int idx)
{
	int	i;
	int	unknown;
	int	vrf;

	unknown = 0;
	i = 1;
	while (i < 5)
	{
		if (!conds[idx].seen[i])
			unknown ++;
		i++;
	}
	vrf = 1;
	vrf &= vrfy_vw(conds[idx].values, conds[idx].left_view, unknown, 0, 1);
	vrf &= vrfy_vw(conds[idx].values, conds[idx].right_view, unknown, 3, -1);
	return (vrf);
}

int	vrfy_vw(int **values, int view, int unknown, int pos, int sens)
{
	int	i;
	int	max;
	int	count;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (*values[pos] > max)
		{
			max = *values[pos];
			count++;
		}
		i++;
		pos += sens;
	}
	if (unknown == 0)
		return (count == view);
	return (count + unknown >= view);
}
