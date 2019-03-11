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

int		ft_first_string_v(char **str, int j)
{
	int n;

	n = 0;
	while (n < 4)
	{
		if (ft_isalpha(str[j][0]))
			return (1);
		j++;
		n++;
	}
	return (0);
}

void	ft_move_horizontal(char **str, int q, int e, int k)
{
	int i;
	int a;
	int w;
	int r;

	i = -1;
	w = ft_move_horizontal_check(str, q, e, k);
	a = q;
	while (str[q][++i])
	{
		q = a;
		r = 0;
		while (++r <= 4)
		{
			if (str[q][i] == k)
			{
				str[q][i - w] = str[q][i];
				str[q][i] = '.';
			}
			q++;
		}
		q = q - 1;
	}
}

int		ft_move_horizontal_check(char **str, int j, int a, int k)
{
	int i;

	j = j - 1;
	while (str[++j])
	{
		i = -1;
		while (str[j][++i])
		{
			if (str[j][i] == k && i < a)
				a = i;
		}
	}
	return (a);
}
