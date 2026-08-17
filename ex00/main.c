/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesfoug <cdesfoug@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:18:17 by cdesfoug          #+#    #+#             */
/*   Updated: 2026/08/16 20:15:19 by cdesfoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "conditions.h"

t_conditions	*process_input(int **map, char **argv, int argc);

int				**create_map(void);

int				fill_map(t_conditions *conditions);

int				**free_all(int **tab, int failed);

t_conditions	*free_all_cond(t_conditions *conditions, int failed);

void			print_map(int **map);

int	main(int argc, char **argv)
{
	t_conditions	*conditions;
	int				**map;
	int				finished;

	map = create_map();
	conditions = process_input(map, argv + 1, argc - 1);
	if (!conditions)
	{
		write(1, "Error\n", 6);
		free_all(map, 3);
		return (0);
	}
	finished = fill_map(conditions);
	if (!finished)
	{
		write(1, "Error\n", 6);
		free_all(map, 3);
		free_all_cond(conditions, 7);
		return (0);
	}
	print_map(map);
	free_all(map, 3);
}
