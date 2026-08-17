/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesfoug <cdesfoug@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 19:00:39 by cdesfoug          #+#    #+#             */
/*   Updated: 2026/08/16 14:38:21 by cdesfoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONDITIONS_H
# define CONDITIONS_H

typedef struct s_conditions
{
	int	left_view;
	int	right_view;
	int	**values;
	int	seen[5];
}	t_conditions;

#endif
