/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesfoug <cdesfoug@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:17:33 by cdesfoug          #+#    #+#             */
/*   Updated: 2026/08/17 20:21:37 by jlombart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "conditions.h"

int	**free_all(int **tab, int failed)
{
	int	i;

	i = -1;
	while (++i < failed)
	{
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

t_conditions	*free_all_cond(t_conditions *conditions, int failed)
{
	int	i;

	i = 0;
	while (i < failed)
	{
		free(conditions[i].values);
		i++;
	}
	free(conditions);
	return (NULL);
}
/*#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int **tab;
    int i;

    tab = malloc(4 * sizeof(int *));
    if (!tab)
        return (1);

    i = 0;
    while (i < 4)
    {
        tab[i] = malloc(4 * sizeof(int));
        if (!tab[i])
            return (1);
        i++;
    }

    printf("Before free_all: %p\n", (void *)tab);

    tab = free_all(tab, 4);

    printf("After free_all: %p\n", (void *)tab);

    return (0);
}*/
