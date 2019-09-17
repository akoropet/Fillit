/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:10:50 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 17:19:12 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		usage(void)
{
	ft_putendl("usage: ./fillit {file}");
	return (0);
}

static int		error(void)
{
	ft_putendl("error");
	return (0);
}

int				ft_find_symbol(char *s, int a)
{
	while (*s)
	{
		if (*s == a)
			return (1);
		s++;
	}
	return (0);
}

int				main(int ac, char **av)
{
	char	*buf;
	char	*rez;
	int		fd;
	int		ret;

	if (ac != 2)
		return (usage());
	buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	rez = ft_strdup("");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (error());
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		rez = ft_strjoin(rez, buf);
	}
	if (!(ret = ft_valid(rez)))
		return (error());
	ft_karta(rez, ret);
	return (0);
}
