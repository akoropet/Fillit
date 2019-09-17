/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_figury.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:10:50 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 17:19:05 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_valid_figury(char *buf)
{
	char	*str;
	int		i;

	i = 0;
	if (!ft_valid_check(buf))
		return (0);
	str = ft_strdup(buf);
	while (str[i] && str[i] != '#')
		i++;
	if (str[i] == '#')
		return (0);
	return (1);
}

int		ft_valid_check(char *buf)
{
	int		i;
	char	ascii;

	i = 0;
	ascii = 'A';
	while (buf[i] != '#' && buf[i])
		i++;
	if (ft_block(buf, i, ascii) != 4)
		return (0);
	while (*buf)
	{
		if (*(buf - 1) == '\n' && *(buf - 2) == '\n')
		{
			i = 0;
			while (buf[i] != '#' && buf[i])
				i++;
			if (ft_block(buf, i, ++ascii) != 4)
				return (0);
		}
		buf++;
	}
	return (1);
}

int		ft_block(char *buf, int i, int n)
{
	int r;

	r = 1;
	buf[i] = n;
	if (i > 0 && buf[i - 1] == '#')
		r += ft_block(buf, i - 1, n);
	if (i > 4 && buf[i - 5] == '#')
		r += ft_block(buf, i - 5, n);
	if (i < 19 && buf[i + 1] == '#')
		r += ft_block(buf, i + 1, n);
	if (i < 15 && buf[i + 5] == '#')
		r += ft_block(buf, i + 5, n);
	return (r);
}

int		ft_valid_last(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
		i++;
	if (buf[i - 1] == '\n' && buf[i - 2] == '\n')
		return (0);
	return (1);
}
