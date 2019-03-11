/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:32:56 by akoropet          #+#    #+#             */
/*   Updated: 2018/04/11 15:50:56 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*t;
	int		i;

	i = 0;
	t = (char *)s;
	while (t[i] != '\0')
	{
		if (*t == c)
			return (t);
		t++;
	}
	if (c == '\0')
		return (t);
	return (0);
}
