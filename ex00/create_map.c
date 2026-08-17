/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlombart <jlombart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:06:41 by jlombart          #+#    #+#             */
/*   Updated: 2026/08/15 17:02:19 by jlombart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	**free_all(int **tab, int failed);

int	*create_arr(void)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc((sizeof(int)) * 4);
	if (!arr)
		return (NULL);
	while (i < 4)
		arr[i++] = 0;
	return (arr);
}

int	**create_map(void)
{
	int	**map;
	int	i;

	i = 0;
	map = malloc((sizeof(int *)) * 4);
	if (!map)
		return (NULL);
	while (i < 4)
	{
		map[i] = create_arr();
		if (!map[i])
		{
			free_all(map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
}
/*#include <stdio.h>
int main(void)
{
	int	**test;
	int	i = 0;
	int	j;

	test = create_map();
	while(i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d", test[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	return (0);
}*/
