/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:10:50 by akoropet          #+#    #+#             */
/*   Updated: 2018/07/23 20:11:12 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_add_square(char **map, char **fig, int k, int count)
{
	int		i;
	int		j;

	if (k == count)
		return (1);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_check_place(map, fig + 4 * k, i, j))
			{
				ft_enter_fig(map, fig + 4 * k, i, j);
				if (ft_add_square(map, fig, k + 1, count))
					return (1);
				else
					ft_delete_fig(map, k + 'A');
			}
		}
	}
	return (0);
}
