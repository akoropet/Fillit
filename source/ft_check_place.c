/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:10:50 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 17:19:27 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_check_place(char **map, char **fig, int i, int j)
{
	int n;
	int q;
	int w;

	n = 0;
	q = 0;
	while (map[i + q] && fig[q] && q < 4)
	{
		w = 0;
		while (fig[q][w] && map[i + q][j + w])
		{
			if (map[i + q][j + w] == '.' && fig[q][w] != '.')
				n++;
			if (n == 4)
				return (1);
			w++;
		}
		q++;
	}
	return (0);
}

void	ft_enter_fig(char **map, char **fig, int j, int i)
{
	int q;
	int w;
	int n;

	q = -1;
	n = 0;
	while (fig[++q])
	{
		w = -1;
		while (fig[q][++w] && n < 4)
		{
			if (ft_isalpha(fig[q][w]))
			{
				n++;
				map[j][i] = fig[q][w];
			}
			i++;
		}
		i = i - w;
		j++;
	}
}

void	ft_delete_fig(char **map, char k)
{
	int i;
	int j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == k)
				map[j][i] = '.';
		}
	}
}
