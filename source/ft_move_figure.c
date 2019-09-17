/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_figure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:10:50 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 17:19:21 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_move_figure(char **str)
{
	int i;
	int j;
	int k;
	int q;

	j = 0;
	k = 'A';
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			q = 0;
			if (str[j][i] == k)
			{
				if (!(ft_first_string_h(str, j)))
					q = ft_move_vertikal(str, j, i, k);
				if (!(ft_first_string_v(str, j - q)))
					ft_move_horizontal(str, j - q, i, k);
				k++;
			}
			i++;
		}
		j++;
	}
}

int		ft_first_string_h(char **str, int j)
{
	int i;

	i = 0;
	while (j != 0 && j % 4 != 0)
		j--;
	while (str[j][i])
	{
		if (ft_isalpha(str[j][i]))
			return (1);
		i++;
	}
	return (0);
}

int		ft_move_vertikal(char **str, int q, int w, int k)
{
	int j;
	int i;
	int a;

	a = 0;
	j = q - 1;
	i = w;
	while (q % 4 != 0)
	{
		q--;
		a++;
	}
	while (str[++j])
	{
		i = -1;
		while (str[j][++i])
		{
			if (str[j][i] == k)
			{
				str[j - a][i] = str[j][i];
				str[j][i] = '.';
			}
		}
	}
	return (a);
}
