/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganfinog <ganfinog@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:04:21 by ganfinog          #+#    #+#             */
/*   Updated: 2026/08/17 20:11:04 by jlombart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_map(int **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = map[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1," ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
/*int main(void)
{
    int LH[] = {4,3,2,1};
    int LB[] = {4,2,2,2};
    int CG[] = {4,3,2,1};
    int CD[] = {1,2,3,2};
    int *map[] = {LH, LB, CG, CD};
    print_map(map);
}*/
