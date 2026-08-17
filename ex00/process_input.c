/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesfoug <cdesfoug@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:25:33 by cdesfoug          #+#    #+#             */
/*   Updated: 2026/08/17 20:18:01 by jlombart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "conditions.h"
#include <stdio.h>

int				input_error(t_conditions *conditions);

int				*prepare_arg(char *str);

int				valid_input(char *str);

t_conditions	*fill_conds(int **map, int *str, t_conditions *conditions);

t_conditions	bld_line_cond(int *line, int lft_vw, int rgt_vw);

t_conditions	bld_col_cond(int **map, int col, int lft_vw, int rgt_vw);

t_conditions	*free_all_cond(t_conditions *conditions, int failed);

t_conditions	*process_input(int **map, char **argv, int argc)
{
	t_conditions	*conditions;
	int				*arg;

	if (argc != 1 || !valid_input(argv[0]))
		return (NULL);
	conditions = malloc(8 * sizeof(t_conditions));
	if (!conditions)
		return (NULL);
	arg = prepare_arg(argv[0]);
	fill_conds(map, arg, conditions);
	free(arg);
	if (input_error(conditions))
		return (free_all_cond(conditions, 7));
	return (conditions);
}

t_conditions	*fill_conds(int **map, int *arg, t_conditions *conditions)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		conditions[i] = bld_line_cond(map[i], arg[8 + i], arg[12 + i]);
		if (!conditions[i].values)
			return (free_all_cond(conditions, i));
	}
	while (i < 8)
	{
		conditions[i] = bld_col_cond(map, i - 4, arg[i - 4], arg[i]);
		if (!conditions[i].values)
			return (free_all_cond(conditions, i));
		i++;
	}
	return (conditions);
}

int	*prepare_arg(char *str)
{
	int	i;
	int	*arg;

	arg = malloc(16 * sizeof(int));
	i = 0;
	while (i < 16)
	{
		arg[i] = str[2 * i] - '0';
		i++;
	}
	return (arg);
}

t_conditions	bld_line_cond(int *line, int lft_vw, int rgt_vw)
{
	int				i;
	t_conditions	condition;

	condition.left_view = lft_vw;
	condition.right_view = rgt_vw;
	condition.values = malloc(4 * sizeof(int *));
	if (!condition.values)
		return (condition);
	i = 0;
	while (i < 4)
	{
		condition.values[i] = &line[i];
		condition.seen[i + 1] = 0;
		i++;
	}
	return (condition);
}

t_conditions	bld_col_cond(int **map, int column, int lft_vw, int rgt_vw)
{
	int				i;
	t_conditions	condition;

	condition.left_view = lft_vw;
	condition.right_view = rgt_vw;
	condition.values = malloc(4 * sizeof(int *));
	if (!condition.values)
		return (condition);
	i = 0;
	while (i < 4)
	{
		condition.values[i] = &map[i][column];
		condition.seen[i + 1] = 0;
		i++;
	}
	return (condition);
}
/*
#include <stdio.h>
#include "create_map.c"
int main(int argc, char** argv)
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
	printf("\n");
	t_conditions *tab = process_input(map, argv + 1, argc - 1);
	if (!tab)
		return (0);
	for (int i = 0; i < 8; i++)
	{
		printf("%d | ", tab[i].left_view);
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", *(tab[i].values[j]));
		}
		printf("| %d", tab[i].right_view);
		printf("\n");
	}
	printf("\n\n");
	map[2][3] = 4;
	for (int i = 0; i < 8; i++)
        {
                printf("%d | ", tab[i].left_view);
                for (int j = 0; j < 4; j++)
                {
                        printf("%d ", *(tab[i].values[j]));
                }
                printf("| %d", tab[i].right_view);
                printf("\n");
        }
}
*/
