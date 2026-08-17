/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmv_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesfoug <cdesfoug@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 15:37:20 by cdesfoug          #+#    #+#             */
/*   Updated: 2026/08/16 18:05:51 by cdesfoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

void	rmv_nbr(t_conditions *conditions, int index, int position)
{
	int	nb;
	int	comp_idx;

	if (index < 4)
		comp_idx = position + 4;
	else
		comp_idx = position;
	nb = *(conditions[index].values[position]);
	conditions[index].seen[nb] = 0;
	conditions[comp_idx].seen[nb] = 0;
	*(conditions[index].values[position]) = 0;
	return ;
}
