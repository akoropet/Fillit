/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_karta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:10:50 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 17:19:24 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_count(int n)
{
	int i;

	i = 1;
	while (i * i < 4 * n)
		i++;
	return (i);
}

char	**ft_karta(char *buf, int count)
{
	char	**str;
	char	**map;
	int		i;
	int		size;

	i = 0;
	if ((str = ft_strsplit(buf, '\n')) == NULL)
		return (NULL);
	size = ft_count(count);
	map = ft_karta_create(size);
	ft_move_figure(str);
	while (!(ft_add_square(map, str, 0, count)))
		map = ft_karta_create(++size);
	ft_karta_print(map);
	return (NULL);
}

char	**ft_karta_create(int n)
{
	char	**karta;
	int		i;
	int		j;

	i = 0;
	karta = (char **)malloc(sizeof(char *) * (n + 1));
	karta[n] = NULL;
	while (i < n)
	{
		karta[i] = (char *)malloc(sizeof(char) * (n + 1));
		j = -1;
		while (++j < n)
			karta[i][j] = '.';
		karta[i][n] = '\0';
		i++;
	}
	return (karta);
}

void	ft_karta_print(char **karta)
{
	int i;

	i = -1;
	while (karta[++i])
		ft_putendl(karta[i]);
}
