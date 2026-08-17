/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlombart <jlombart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:24:30 by jlombart          #+#    #+#             */
/*   Updated: 2026/08/16 19:43:56 by jlombart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

int	is_error(int a, int b)
{
	if (a == 4 && (b == 2 || b == 3 || b == 4))
		return (1);
	if (a == 3 && (b == 3 || b == 4))
		return (1);
	if (a == 2 && b == 4)
		return (1);
	if (a == 1 && b == 1)
		return (1);
	else
		return (0);
}

int	input_error(t_conditions *conditions)
{
	int	i;
	int	left;
	int	right;

	i = 0;
	while (i < 8)
	{
		left = conditions[i].left_view;
		right = conditions[i].right_view;
		if (is_error(left, right))
			return (1);
		i++;
	}
	return (0);
}
/*#include <stdio.h>
int main(void)
{
    t_conditions conditions[8];

    conditions[0].left_view = 4;
    conditions[0].right_view = 4;

    conditions[1].left_view = 3;
    conditions[1].right_view = 2;

    conditions[2].left_view = 2;
    conditions[2].right_view = 3;

    conditions[3].left_view = 1;
    conditions[3].right_view = 4;

    conditions[4].left_view = 2;
    conditions[4].right_view = 2;

    conditions[5].left_view = 3;
    conditions[5].right_view = 1;

    conditions[6].left_view = 1;
    conditions[6].right_view = 3;

    conditions[7].left_view = 2;
    conditions[7].right_view = 2;

    printf("%d\n", input_error(conditions));

    return (0);
}*/
//- input_error : verif si input incoherents (4 avec 2, etc)
