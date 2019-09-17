/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:10:50 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 17:19:08 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_valid(char *buf)
{
	int size;

	if ((size = ft_valid_strok(buf)) <= 26 &&
		ft_valid_simvolov(buf) && ft_valid_figury(buf) && ft_valid_last(buf))
		return (size);
	return (0);
}

int		ft_valid_strok(char *buf)
{
	int count;
	int number;

	number = 0;
	while (*buf)
	{
		count = 0;
		while ((*buf != '\n' && (*(buf + 1) != '\n' || *(buf + 1))) && *buf)
		{
			if (ft_valid_stroki(buf))
			{
				while (*buf != '\n' && *buf)
					buf++;
			}
			count++;
			if (*buf)
				buf++;
		}
		if (count != 4)
			return (0);
		if (*buf)
			buf++;
		number++;
	}
	return (number);
}

int		ft_valid_stroki(char *buf)
{
	int i;

	i = 0;
	while (*buf != '\n' && *buf)
	{
		buf++;
		i++;
	}
	if (i != 4)
		return (0);
	return (1);
}

int		ft_valid_simvolov(char *buf)
{
	while ((*buf == '#' || *buf == '.' || *buf == '\n') && *buf)
		buf++;
	if (*buf == '\0')
		return (1);
	return (0);
}

int		ft_karta_size(char **str)
{
	int i;
	int n;

	n = 0;
	i = 'A';
	while (*str)
	{
		if (ft_find_symbol(*str, i))
		{
			i++;
			n++;
		}
		str++;
	}
	return (n);
}
